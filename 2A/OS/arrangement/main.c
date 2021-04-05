#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

long foo(long n);

int main(int argc, char *argv[]) {

        if (argc <= 1) {
                fprintf(stderr, "Usage: ./main <postive number>");
        }
        long n = atol(argv[1]);
        if (n <= 0) {
                fprintf(stderr, "Please enter a postive number");
        }
        if (!fork()){
                while(n != 1){
                        printf("%ld ", n);
                        n = foo(n);
                }
                printf("%ld", n);
        }
        int statusp;
        wait(&statusp);
        return 0;
}

long foo(long n) {
        if (n % 2) {
                return 3 * n + 1;
        }
        return n / 2;
}
