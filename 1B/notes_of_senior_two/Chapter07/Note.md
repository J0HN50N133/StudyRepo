# 空间解析几何与向量代数



## 空间直角坐标系

有八个卦限

## 向量及其线性运算

1. 加减法

2. 向量的数乘
3. 两个向量的平行关系
4. 向量在坐标轴上的投影
   	1. $A'B'=|AB|\cos \phi$	
    	2. 两个向量的和在轴上的投影等于两个向量轴上投影的和
    	3. 向量与数的乘积在轴上的投影等于向量在该轴上的投影与数的乘积

## 向量的坐标，数量积，向量积

1. 方向角：$\alpha,\beta,\gamma$,非零向量分别与$x,y,z$轴构成的夹角

   > $a_x = |\vec\alpha|\cos\alpha$；$y,z$轴以此类推
   >
   > 有什么用呢？
   >
   > 向量单位化，我们得到一个这样的向量$(\cos\alpha,\cos\beta,\cos\gamma)$，这个向量是原向量单位化的结果

2. 矩阵的内积
3. 柯西-施瓦茨不等式  
   $$\vec a\cdot\vec b \le |a|\cdot|b|$$   
   $$\sum_{i=1}^3 a_i\cdot b_i \le \sqrt{\sum_{i=1}^3 a_i^2}\cdot\sqrt{\sum_{i=1}^3 b_i^2}$$

## 平面、曲面、空间曲线及其方程



## 常见的二次曲面及其图形

### 平面

1. 方程

- 点法式方程 ：$M_0(x_0,y_0,z_0)$是平面上的一个已知点，$\vec n(A,B,C)$是平面的一个法向量，则平面的点法式方程可以表示为：

  $$A(x-x0) + B(y - y_0) + C(z - z_0) = 0$$

  那么平面的法向量怎么找呢？  

  看$x,y,z$前的系数不就可以了吗

- 三点式方程，有了三个点，意味着我可以得到三个向量，而这三个向量共面，共面意味着混合积为0,则行列式为0.

  $A(x_1,y_1,z_1),B(x_2,y_2,z_2),C(x_3,y_3,z_3),还有一个任意点X(x,y,z)$

  $$\begin{vmatrix}x-x_1&y-y_1&z-z_1\\x_1-x_2&y_1-y_2&z_1-z_2\\x_2-x_3&y_2-y_3&z_2-z_3\end{vmatrix} = 0$$

  解出以上方程即可

- 截距式方程 ：平面与$x,y,z$三轴分别交于$P(a,0,0),Q(0,b,0),R(0,0,c)其中a\ne0,b\ne0,c\ne0$易得平面的截距式方程为${x \over a}+{y \over b}+{z \over c} = 1$

2. 两平面之间的夹角$\theta$（二面角)$\theta \in [0,{\pi \over 2}]$

   1. 求解两个平面之间的夹角:求出两个平面的法向量，两向量之间的夹角为$\phi$,两平面之间的夹角为$\theta$,计算$\cos \phi,易证\phi = \theta$

   2. 两平面的位置特征$$\Pi_1 \perp \Pi_2 \Rightarrow A_1A_2 + B_1B_2 + C_1C_2 = 0$$

      $$\Pi_1 \parallel \Pi_2 \Rightarrow {A_1 \over A_2}={B_1 \over B_2}={C_1 \over C_2}$$

   3. 点到平面距离$d=$${|Ax_0+BY_0+CZ_0+D|}\over {\sqrt{A^2+B^2+C^2}}$

      怎么证明？

      我们已知平面的法向量为$\vec n =(A,B,C)$,$x(x,y,z)$是平面内的一个点，得到一个向量是$\vec a = (x-x_0,y-y_0,z-z_0)$距离就是$\vec a$在法向量方向上的投影嘛,

      $d = \frac{|\vec n \cdot \vec a |}{|\vec n|} = \frac {|A(x-x_0) + B(y-y_0) + C(z-z_0)|}{\sqrt{A^2+B^2+C^2}}=\frac{Ax_0+BY_0+CZ_0+D|} {\sqrt{A^2+B^2+C^2}}$



### 直线

1. 方程
   - 一般方程：直线是两个平面的交线，则用两个平面方程联立来确定一条直线
   - 两点式方程 : 推到点向式方程，因为两点可以得到一个向量$\vec l = (m,n,p)$
   - 点向式方程：有一个平行于直线的向量$\vec l = (m,n,p)$则直线方程可以写作
   $$\frac{x-x_0}{m}=\frac{y-y_0}{n}=\frac{z-z_0}{p}$$
   - 同上已知方向向量，直线的参数方程可以写作：
   $$\begin{cases}  {x = x_0 + mt}\\{y = y_0 + nt}\\z = z_0 + pt\end{cases}$$
   - 已知两个平面，怎么求直线？分别得到两个平面的法向量以后,由于直线在两个平面内，则直线与两个法向量都垂直，也就是说方向与两法向量叉积结果相同。
2. 两直线夹角，即是两方向向量的夹角，范围在$(0,\frac \pi 2)$
两直线公垂线的求法: 

### 平面束
平面束：通过一条直线的全部平面组成的平面称为平面束
$$L:\lambda_1(A_1x+B_1y+C_1z+D_1=0) + \lambda_2(A_2x+B_2y+C_2z+D_2=0) (\lambda_1 * \lambda_2 \ne 0)$$
注意平面束方程存在退化情况（两个平面重合）以及两个平面平行的特殊情况
实际使用时我们经常两边除以$\lambda_1$以简化方程，然而，在非退化情况下这样的方程不能表示出第二个平面，因此我们使用的时候要格外小心,注意讨论第二个平面是否符合条件.

### 曲面和空间曲线

曲面S满足一个三元方程 $F(x，y，z) = 0$,若看作集合则有:

$$S = \{(x,y,z)|F(x,y,z) = 0\}$$

则$F(x,y,z) = 0$是曲面$S$的方程。

1. 方程:

   - 一般方程:

     $$\begin{cases}F(x,y,z) = 0 \\G(x,y,z) = 0\end{cases}$$

   - 参数方程

     ![参数方程](/home/ljx/高等数学二/Chapter07/picturenote/参数方程.png)

## 旋转面、柱面

### 旋转面

既然是旋转面就一定有一条旋转轴，还有一条母线，用这两个东西肯定可以得到方程

![旋转面参数方程](/home/ljx/高等数学二/Chapter07/picturenote/7.7旋转面参数方程.png)

绕轴旋转意味着什么？见高等数学上p214
绕着谁旋转，则谁不变例如$F(y,\sqrt{x^2+z^2})$

#### 旋转椭球面

方程：(其实都是由$F(\sqrt {x^2+y^2},z))$等公式推出的,绕谁转，谁不变，另外一元换，看哪两项可以凑出原来对应的平面曲线方程(母线方程)就知道了
$$\frac{x^2}{a^2}+\frac{y^2}{a^2}+\frac{z^2}{b^2} = 1$$
$$\frac{x^2}{b^2}+\frac{y^2}{a^2}+\frac{z^2}{a^2} = 1$$

#### 旋转单叶双曲面，旋转双叶双曲面
单叶双曲线就是以对称轴为轴进行旋转得到的，双叶双曲面是以双曲线两定点所连成直线为轴旋转而成的

单叶:两正一负 双叶：两负一正

#### 旋转抛物面

### 柱面
路径作为准线，过路径上一点，垂直与坐标轴的点成为直母线
方程之中少了哪一个字母就平行于哪一个轴（并不常常这样,因为有时候母线是斜的，就你妈邪门)

#### 重要曲面

##### 重要曲面1

1. 球面 ： $x^2 + y^2 + z^2 = R^2$

 	2. 圆锥面 : $x^2 + y^2 = z^2$（由$y = z$ 绕$z$轴旋转而来）
 	3. 旋转双曲面 : $\frac{x^2}{a^2} + \frac{y^2}{b^2} - \frac{z^2}{c^2} = 1$

##### 重要曲面2

1. 圆柱面 : $x^2 + y^2 = R^2$

 	2. 抛物柱面 : $x^2 = 2py(p>0)$
 	3. 椭圆柱面 : $\frac{x^2}{a^2} + \frac{y^2}{b^2} = 1$

##### 重要曲面3

1. 椭球面 : $\frac{x^2}{a^2} + \frac{y^2}{b^2} + \frac{z^2}{c^2} = 1$

 	2. 椭圆抛物面 :  $\frac{x^2}{2p^2} + \frac{y^2}{2q^2} = z$ (p,q同号)
 	3. 马鞍面
 	4. 单叶双曲面

 3