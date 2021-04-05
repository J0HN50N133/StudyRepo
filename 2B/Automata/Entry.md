
# Table of Contents

1.  [形式语言与状态机理论](#org6b0f4a5)
    1.  [基础知识](#org91fb795)
        1.  [谓词逻辑语言](#orgbb12ee5)


<a id="org6b0f4a5"></a>

# 形式语言与状态机理论


<a id="org91fb795"></a>

## 基础知识

-   **序列:** **有序** 排列的一组元素
    -   表示 <a<sub>1</sub> , a<sub>2</sub> , a<sub>3</sub> , a<sub>1</sub>>
-   **元组:** 有限序列
    -   表示 (a, b, c)


<a id="orgbb12ee5"></a>

### 谓词逻辑语言

-   Terms
    -   variables: x, y, z
    -   functions: f(t1, t2, t3)
-   formulas
    -   谓词+逻辑连接符
    -   predicate symbols: P(t1, t2, t3,&#x2026;)
    -   Equality: 连接两个term, 判断两个term是否相等
    -   logical connectives: 逻辑连接词（参考离散数学）
-   Model M=(D,I)
    -   D是非空论域
    -   I是对non-logical terms的解释函数
        -   Function symbol f: I(f): D<sup>n</sup> &rarr; D, I相当于一个解释器, D<sup>n是对论域里的n个terms进行解释</sup>, 运算的结果还是落在论域里。
        -   Predicate symbol P: I(P): D<sup>n</sup> &rarr; {true, false}
            对n个terms应用谓词以后得到了什么，即这n个terms是不是都符合谓词。

-   Interpretation (M, &sigma;)
    -   Terms: I(f(x<sub>1</sub>, x<sub>2</sub>, &#x2026;)) = I(f)(&sigma;(x<sub>1</sub>),&sigma;(x<sub>2</sub>),&#x2026;)

