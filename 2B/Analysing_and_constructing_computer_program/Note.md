
# Table of Contents

1.  [可信软件开发](#orgc9084e1)
    1.  [Part 1: Definition of a little language and discrete math refreshing](#org8d670e8)
    2.  [Part 2: Direct study of 10 simple programs](#orgcb86038)
        1.  [What to do and How to prove it.](#org6404ff5)
    3.  [Part 3: Introduction to a program construction method](#org4d4216a)
    4.  [Part 4: Constructing the programs studied in part 2](#org43a99cc)


<a id="orgc9084e1"></a>

# 可信软件开发


<a id="org8d670e8"></a>

## Part 1: Definition of a little language and discrete math refreshing


<a id="orgcb86038"></a>

## Part 2: Direct study of 10 simple programs


<a id="org6404ff5"></a>

### What to do and How to prove it.

1.  Example : Interger Inverse

    测试 &rarr; 数学证明
    Find **PRE-condition**, then check whether the question
    satisfy the PRE-condition.
    Find **POST-condition**, then check whether the answer we
    find satisfy the POST-condition.
    POST-condition说的是你的输出是如何与输入产生关联的，并且输出满足
    什么条件。
    （Hoare 逻辑）
    
    -   **post-condition:** 
    
    -   **pre-condition:** 

2.  Invariant

    given a loop
    
        A1;
        while P do
            A2
        variant
            Q
        end
    
    -   Properties Q must hold just before and just after the
        body of loop.
    -   **If** Q holds before A2, then it must hold after A2.
    -   The **invariant Q** holds also **at the end of the loop.**
    -   We have to prove that the initialisation establishes
        the invariant.
    -   The **negation of the guard P** holds at the end of the loop.
    -   Therefore, at the end of loop, we get Q&and; &not; P. We want
        to prove after the loop, the POST-condition is held.
        Then we get a sequent(相继式)
        PRE，&not; P, Q |&mdash; OST
    -   But there is a price to pay: the discovery of Q
    -   We have also to prove that the loop terminates.(Otherwise
        the loop never stop and we can't get &not; P)
    
    The interger inverse program (Part2&ndash;1 page6)can be write in
    
        squareroot
          r := 0;
          while square(r + 1) less or equal to n do
            r := r + 1
          invariant
            r in N
            sqare(r) less than N
          end
    
    `=============`
    
    -   Given an assignment A and a property P, we write
        the following:
        [A]P to denote **what is to be proved for P to hold**
        just after Assignment.
        e.g. [r := r+1]r<sup>2</sup> &le; n
        [r := r + 1] r<sup>2</sup> &le; n
        = P(r &larr; r + 1)
        = (r + 1)<sup>2</sup> &le; n
    -   PRE |&mdash; [A<sub>1</sub>]Q **INI**
    -   PRE, P, Q |&mdash; [A<sub>2</sub>]Q **INV**
    -   PRE, &not; P, Q |- POST **POST**


<a id="org4d4216a"></a>

## Part 3: Introduction to a program construction method


<a id="org43a99cc"></a>

## Part 4: Constructing the programs studied in part 2

