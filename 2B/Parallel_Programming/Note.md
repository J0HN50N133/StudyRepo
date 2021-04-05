
# Table of Contents

1.  [Parallel Program Design](#org78b4ba0)
    1.  [Introduction to Parallel Architectures](#orgab1a56b)
        1.  [冯诺依曼架构](#orge2b0751)
        2.  [Memory Hierarchy](#org4955626)
    2.  [Distrubuted-Memory Programming with MPI](#org8c9ae5a)


<a id="org78b4ba0"></a>

# Parallel Program Design


<a id="orgab1a56b"></a>

## Introduction to Parallel Architectures


<a id="orge2b0751"></a>

### 冯诺依曼架构

-   Component
    有五个部分组成
    1.  Control
    2.  Datapath(数据通路AKA. 运算器)
    3.  Memory
    4.  Input
    5.  Output
-   Why Von Neumann Architectures make sense?
    在早期, 计算机的软件是固化在硬件里的,软件不可以和硬件分离, 直到冯诺依曼结构才能实现软硬分离.
    不过, 并行程序还是要依照硬件的结构来设计才能发挥最大性能
-   Von Neumann bottleneck
    存储和运算分开的架构影响了性能.为了改善这个bottleneck而引入了memory hierarchy


<a id="org4955626"></a>

### Memory Hierarchy

---

-   Registers  -

---

---

-   Cache  -

---

---

-   Memory   -

---

---

-   Disk  -

---

---

-   Tape  -

---

-   **存储架构:** 层级
-   **存储技术:** SRAM, DRAM


<a id="org8c9ae5a"></a>

## Distrubuted-Memory Programming with MPI

