# 生产者消费者问题1
```c
int n = 1;
extern struct semaphore mutex {1};
extern struct semaphore empty {n};
extern struct semaphore full  {0};

// Producer
do{
        /*Produce an item in next produced*/
        P(empty);
        P(mutex);
        // add next produced to the buffer
        V(mutex);
        V(full);
}while(true);

// Consumer
do{
        P(full);
        P(mutex);
        // consume the item in the next consumed
        V(mutex);
        V(empty);
}while(true);
```

# 生产者消费者问题2
```c
int n = 1;
extern struct semaphore mutex {1};
extern struct semaphore empty {n};
extern struct semaphore full {0};

// Producer
do{
        /*Produce an item in next produced*/
        P(empty);
        P(mutex);
        // add next produced to the buffer
        V(mutex);
        V(full);
}while(true);

// Consumer
do{
        P(full);
        P(mutex);
        // consume the item in the next consumed
        V(mutex);
        V(empty);
}while(true);
```

# 生产者消费者问题3
```c
int plateSize = 2;

extern struct semaphore mutex {1};
extern struct semaphore empty {plateSize};
extern struct semaphore apple {0};
extern struct semaphore orange {0};

// Father
do{
        // produce an apple
        P(empty);
        P(mutex);
        // put an apple on the plate
        V(mutex);
        V(apple);
}while(true);

// mother
do{
        // produce an orange
        P(empty);
        P(mutex);
        // put an orange on the plate
        V(mutex);
        V(orange);
}while(true);

// son

do{
        // produce an orange
        P(orange);
        P(mutex);
        // eat an orange
        V(mutex);
        V(empty);
}while(true);

// daughter
do{
        // produce an apple
        P(mutex);
        P(apple);
        // eat an apple
        V(mutex);
        V(empty);
}while(true);

```
