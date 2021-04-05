#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void killChild(int);

pid_t childPid;

int main(){
        struct sigaction actALRM, actTSTP;
        actALRM.sa_handler = killChild;
        actTSTP.sa_handler = killChild;
        sigaction(SIGTSTP, &actTSTP, NULL);
        sigaction(SIGALRM, &actALRM, NULL);
        switch(childPid = fork()){
                case -1:
                        fprintf(stderr, "Fork fail\n");
                        break;
                case 0: // child process
                        execlp("grep","grep", "-R","#!/bin/bash", "/home", NULL);
                        break;
                default: // parent process
                        alarm(10);
                        break;
        }
        pause();
}

void killChild(int sig){
        if (kill(childPid, SIGTERM) == 0){
                if(sig == SIGTSTP)
                        fprintf(stderr, "\nterminated by <C-z>. Child died.\n");
                else
                        fprintf(stderr, "Time out. Child killed.\n");
        }
}
