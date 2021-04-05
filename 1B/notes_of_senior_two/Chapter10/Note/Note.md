# 曲线积分



## 第一节:第一类曲线积分



### 对弧长的积分



#### 问题提出与定义

曲线型构件的质量怎么求?

质量均匀的构件：$M=\rho \cdot s$

按照这个基本原理我们可以得到:

$$M = \int_L \rho(x,y)ds$$



```mermaid
graph LR;
 分割:分割出无数小段-->近似:小段里可以认为密度均匀-->求和把小段加起来-->取极限:最长的段长度趋于0
```

如果这个求和极限存在,则称此极限为函数$f(x,y)$在曲线弧$L$上对弧长的曲线积分或第一类曲线积分,记作$\int_L f(x,y)ds$



#### 存在条件

$f(x,y)$在光滑曲线弧$L$上连续时积分存在



#### 推广

三维坐标中的曲线积分:$\int_\Gamma f(x,y,z)ds$



#### 注意事项

1. 运算性质：可加可减可以乘常量(线性性质)，介值定理
2. 函数$f(x,y)$在闭合曲线$L$上对弧长的曲线积分记为$\oint_L f(x,y)ds$

#### 对弧长曲线积分的计算



##### 定义

函数$f(x,y)$在$L$上有定义且连续,$L$的参数方程为：

$$\begin{cases}x=\varphi(t)\\y=\Psi(t)\end{cases}$$

$\varphi(t),\Psi(t)$在$[\alpha,\beta]$上有一阶连续导数，已知$\begin{cases} ds= \sqrt{dx^2+dy^2}\\dx=\varphi'(t)dt\\dy=\Psi'(t)dt\end{cases}$则:

$$\int_L f(x,y)ds = \int^\beta_\alpha f[\varphi(t),\Psi(t)]\sqrt{\varphi'^2(t)+\Psi'^2(t)}dt $$



##### 注意：

1. 定积分的下限$\alpha$一定要小于上限$\beta$;
2. $f(x,y)$中$x,y$不彼此独立而是相互有关的



##### 推广：

$$\Gamma:x=\varphi(t)，y=\Psi(t)，z=\omega(t)$$

$$\int_\Gamma f(x,y,z)ds = \int^\beta_\alpha f[\varphi(t),\Psi(t)，\omega(t)]\sqrt{\varphi'^2(t)+\Psi'^2(t)+\omega'^2(t)}ds$$



#### 几何与物理意义

1.  当$\rho(x,y)$表示$L$的线密度时，积分为质量
2. 当$f(x,y) = 1$时积分为长度
3. 当$h(x,y)$为路径上的高时，积分为面积







## 第二节:对坐标的曲线积分



### 问题的提出(Why)

实例： 变力沿曲线做的功

如果是恒定的力$W=F \cdot \vec{AB}$，那变力换成积分形式就是$W=\int_L F(x,y)ds$

$$F(x,y)=P(x,y)\vec i + Q(x,y)\vec j$$

分割 : $A\rarr M_0,M_1\dots M_n\rarr B$,$\vec{M_{i-1}M_i}=(\Delta x_i)\vec i +(\Delta y_i)\vec j$

近似 ： 取$F(\xi_i,\eta_i)=P(\xi_i,\eta_i)\vec i + Q(\xi_i,\eta_i)\vec j$

​	$$\Delta W_i \approx F_i\cdot\vec{M_{i-1}M_i}$$

即 $\Delta W_i \approx P(\xi_i,\eta_i)\Delta x_i + Q(\xi_i,\eta_i)\Delta y_i $

求和： $$W = \sum^n_{i=1} \Delta W_i \approx \sum^n_{i=1}[P(\xi_i,\eta_i)\Delta x_i + Q(\xi_i,\eta_i)\Delta y_i ]$$

取极限: 

$$\lambda = min(\sqrt{\Delta x_1^2+\Delta y_1^2},\sqrt{\Delta x_2^2+\Delta y_2^2}\dots\sqrt{\Delta x_n^2+\Delta y_n^2})$$

$$W = lim_{\lambda \to 0}\sum^n_{i=1}[P(\xi_i,\eta_i)\Delta x_i + Q(\xi_i,\eta_i)\Delta y_i ]$$

如此我们定义出了第二类曲线积分，并且有关于$x$轴的第二类曲线积分和关于$y$轴的第二类曲线积分

### 存在条件

当$P(x,y),Q(x,y)$在光滑曲綫弧$L$上连续时，第二类曲线积分存在

### 组合形式与拆分形式

$$\int_LP(x,y)dx+\int_LQ(x,y)dy=\int_LP(x,y)dx+Q(x,y)dy=\int_L\vec F \cdot \vec{ds}$$

### 推广

空间里变成$x,y,z$即可

### 性质

1. 线性，区间可加
2. 有向性，方向相反被积函数相同的轨迹积分为相反数

### 计算

$$\begin{cases}x=\varphi(t)\\y=\Psi(t)\end{cases}$$

$$\int_LP(x,y)dx+Q(x,y)dy=\int^\beta_\alpha\{P(\varphi(t),\Psi(t))\varphi'(t)+Q(\varphi(t),\Psi(t))\Psi'(t)\}dt$$

特殊情形

1. $L: y=y(x)$
2. $L:x=x(y)$

推广 ： 三维方法与二维一致

### 两类曲线积分的联系

设有向平面曲线弧为$$L:\begin{cases}x=\varphi(t)\\y=\Psi(t)\end{cases}$$，

$L$上点$(x,y)$处的切线向量的方向角为$\alpha,\beta$,则

$$\int_LPdx+Qdy=\int_L(P\cos\alpha +Q\cos\beta)ds$$





## 第三节:格林公式及其应用

### 格林公式

闭区域D由分段光滑的曲线$L$围成,函数$P(x,y),Q(x,y)$在$D$上具有一阶连续偏导数,则有

$$\iint_D (\frac{\partial Q}{\partial x} - \frac{\partial P}{\partial y} )dxdy = \oint Pdx + Qdy$$

其中$L$是$D$的取正向的边界曲线.

证明A:(不分片情况)

​		$$\iint_D\frac{\partial Q}{\partial x}dxdy = \int^d_cdy\int^{\Psi_2(y)}_{\Psi_1(y)} \frac{\partial Q}{\partial x}$$

$ \int^d_cdy\int^{\Psi_2(y)}_{\Psi_1(y)} \frac{\partial Q}{\partial x} = \int^d_c Q(\Psi_2(y),y)dy - \int^d_c Q(\Psi_1(y),y)dy $

$= \int^d_c Q(\Psi_2(y),y)dy + \int^d_c Q(\Psi_1(y),y)dy = \oint_L Q(x,y)dy$ 

同理可证  $-\iint_D \frac{\partial P}{\partial y}dxdy = \oint_L P(x,y)dx$

两式相加即可

证明B:(分片情况)

​	利用区间可加性即可证

证明C:(内空情况)



### 边界曲线的方向

1. 正向: 当观察者沿边界行走时,区域$D$总是在它的左边.
2. 负向: 当观察者沿边界行走时,区域$D$总是在它的右边.

​		如果区域$D$既是$X-$型区域又是$Y-$型区域,平行于坐标轴的直线和$L$至多交于两点.

### 格林公式实质

沟通了沿闭曲线的积分和二重积分之间的联系.

格林公式便于记忆的形式:

$$\iint_D\begin{vmatrix}\frac{\partial}{\partial x}\quad \frac{\partial}{\partial y}\\P \quad Q\end{vmatrix}dxdy = \oint Pdx+Qdy$$



### 简单应用

1. 简化曲线积分
2. 简化二重积分
3. 计算平面面积



### 曲线积分与路径无关的条件



​	设区域$D$为平面区域,如果区域里任取一闭曲线所围成的部分都属于$D$,则$D$为平面单连通区域,否则为平面复连通区域.

​	如果区域$G$内的任意两条有相同起点和终点的分段光滑有向曲线(方向不同),有:

​		$\int_{L_1}Pdx+Qdy = \int_{L_2}Pdx+Qdy$

则称曲线积分$\int_LPdx+Qdy$在$G$内与路径无关

​	**定理** : 对于开区域$G$是一个单连通域,函数$f(x,y),Q(x,y)$在G内具有一阶连续偏导数,则下列三个条件等价:

1. 曲线积分在$G$内与路径无关

2. 在$G$内存在某个函数$u(x,y)$,使 $du=Pdx+Qdy$

3. 在$G$内每一点处有

   ​	$$\frac{\partial P}{\partial y} = \frac{\partial Q}{\partial x}$$

当曲线积分与路径无关时我们直接以起点和终点为积分上下限即可. 



### 证明了曲线积分与路径无关后求原函数

我们证明了曲线积分$\int_LPdx+Qdy$与路径无关后知道有$du=Pdx+Qdy$怎样求原函数$u(x,y)$?

以$(x^4+4xy^3)dx+(6x^2y^2-5y^4)dy$为例

1. 不定积分法:

   ​	由于$\frac{\partial u}{\partial x}=P(x,y)=x^4+4xy^3$,因此

   ​															$$u(x,y) = \frac{1}{5}x^5+2x^2y^3+\varphi(y)$$,

   其中$\varphi(y)$为仅含$y$的任意函数,于是$\frac{\partial u}{\partial y}=6x^2y^2+\varphi'(y)$

   因此

   ​															$\varphi'(y)=-5y^4$

   从而

   ​														$\varphi(y)=-y^5+C$

   即得原函数

   ​									$u(x,y)=\frac{1}{5}x^5+2x^2y^3-y^5+C$

2. **特殊路径法**:

   ​		$$u(x,y)=\int_{(0.0)}^{(x,y)}Pdx+Qdy+C=\int_0^xP(x,0)dx+\int_0^yQ(x,y)dy+C$$

   ​	                   $$=\int_0^4x^4dx+\int_0^y(6x^2y^2-5y^4)dy+C=\frac{1}{5}x^5+2x^2y^3-y^5+C$$

3. 观察微分法:
   $$
   (x^4+4xy^3)dx+(6x^2y^2-5y^4)dy
   $$

   $$
   =x^4dx-5y^4dy+4xy^3dx+6x^2y^2dy
   $$

   $$
   =d(\frac{1}{5}x^5-y^5)+2y^3dx^2+2x^2dy^3
   $$

   $$
   =d(\frac{1}{5}x^5-y^5)+d(2x^2y^3)
   $$

   $$
   =d(\frac{1}{5}x^5-y^5+2x^2y^3)
   $$

   

## 第四节:对面积的曲面积分



### 概念

#### 实例

如果曲面$\Sigma$是光滑的,它的面密度为连续函数$\rho(x,y,z)$,求它的质量.(光滑即曲面上各点都有切平面,且当点在曲面上连续移动的时候,切平面也连续转动)

### 对面积的曲面积分的定义

定义 取曲面$\Sigma$是光滑的,函数$f(x,y,z)$在$\Sigma$上有界,把$\Sigma$分成n个小块$\Delta S_i$($\Delta S_i$同时表示第$i$块曲面的面积),设点$(\xi_i,\eta_i,\zeta_i)$为$\Delta S_i$上任意取定的一个点,做乘积$f(\xi_i,\eta_i,\zeta_i)\cdot \Delta S_i$,并求和$\sum^n_{i=1}f(\xi_i,\eta_i,\zeta_i)\cdot \Delta S_i$,然后取极限,让最大的小平面面积趋近于0,如果这个极限存在,我们称此极限为函数$f(x,y,z)$在曲面$\Sigma$上对面积的曲面积分或第一类曲面积分

```mermaid
graph LR;
A[分割: 把曲面切成n个小块]
B[近似: 每一个小块,面密度可以视作不变,那么着一块的质量就是小块面积直接乘小块内任意一点的函数值]
C[求和: 所有小块质量加起来]
D[取极限: 最大的小块面积趋近于0]
 A-->B
 B-->C
 C-->D
```



符号: $$\iint_\Sigma f(x,y,z)dS$$

性质:

1. 可以分片求积分(积分区域可加性)

### 计算方法

三个情况

1. 若曲面$\Sigma: z = z(x,y)$

   ​		则 $$\iint_\Sigma f(x,y,z)dS = \iint_{D_{xy}}f[x,y,z(x,y)]\sqrt{1+z'_x+z'_y}dxdy$$

2. 若曲面$\Sigma: y = y(z,x)$  跟上面同理

3. 若曲面$\Sigma: x=x(x,y)$跟上面同理

### 注意

如果曲面$\Sigma$投影到某坐标平面上,则在其投影区域内部任意一点作垂直此坐标平面的直线与曲面$\Sigma$应该只有一个焦点.如果有两个或两个以上的交点, 则应将曲面$\Sigma$分成几部分, 使得每一部分曲面都符合上述条件.然后分片积分. 

$\oiint$表示封闭曲面





## 第五节:对坐标的曲面积分(第二类区面积分)

### 基本概念

曲面分为上侧和下侧,内侧和外侧.

侧其实是什么呢?法向量的指向决定了曲面的侧.

*决定了侧的曲面称为有向曲面.*

*曲面的投影问题:*在有向曲面$\Sigma$上取一小块曲面$\Delta S$,$\Delta S$在$xoy$平面上的投影$(\Delta S)_{xy}$为
$$
(\Delta S)_{xy}=
\begin{cases}
(\Delta \sigma)_{xy},\quad\ \ \  if \cos \gamma >0 \\
-(\Delta \sigma)_{xy},\quad if \cos \gamma <0 \\
0,\quad\quad\quad\quad\ if cos \gamma = 0\\
\end{cases}
$$
$(\Delta \sigma)_{xy}$为投影区域的面积,$\gamma$为法向量和$y$轴正半轴的夹角

### 概念,性质,存在条件

定义:老套路,分割,近似,求和,取极限

$$\iint_{\Sigma}R(x,y,z)dxdy = \lim_{\lambda \to 0}\Sigma^n_{i=1}R(\xi_i,\eta_i,\zeta_i)(\Delta S_i)_{xy}$$

同理可以定义其他两个平面上的第二类曲面积分

存在条件:被积函数在有向光滑曲面上连续时,对坐标的曲面积分存在



组合形式:

$\iint_\Sigma=\iint Pdydz+\iint Q dxdz+\iint Rdxdy$

性质:

1. 积分曲面可加性
2. 有向性涉及正负,方向相反的话积分加一个负号



### 计算法

设积分曲面$\Sigma$是由方程$z=z(x,y)$所给出的曲面上侧,$\Sigma$在$xoy$面上的投影区域为$D_{xy}$函数$z=z(x,y)$在$D_{xy}$上具有一阶连续偏导数,被积函数$R(x,y,z)$在$\Sigma$上连续.

$$\iint_{\Sigma}R(x,y,z)dxdy = \lim_{\lambda \to 0}\Sigma^n_{i=1}R(\xi_i,\eta_i,\zeta_i)(\Delta S_i)_{xy}$$

$\because \Sigma取上侧,cos\gamma > 0,$

$\therefore (\Delta S_i)_{xy} = (\Delta\sigma)_{xy},$

又$\because \zeta_i=z(\xi_i,\eta_i)$

$\therefore \lim_{\lambda \to 0}\Sigma^n_{i=1}R(\xi_i,\eta_i,\zeta_i)(\Delta S_i)_{xy} = \lim_{\lambda \to 0}\Sigma^n_{i=1}R(\xi_i,\eta_i,z(\xi_i,\eta_i))(\Delta \sigma_i)_{xy}$

即$\iint_\Sigma R(x,y,z)dxdy = \iint_{D_{xy}}R[x,y,z(x,y)]dxdy$

取下侧带个负号就行了.其他两个平面也做相应的换元即可.

注意!!!对坐标的区面积分一定注意哪一侧

**例1**计算$\iint_\Sigma xyzdxdy$,其中$\Sigma$是球面$x^2+y^2+z^2=1$外侧在$x \ge 0,y \ge 0$的部分.

对于$xoy$的上半部分夹角是锐角,下半部分是钝角

把$\Sigma$分成$\Sigma_1$和$\Sigma_2$两个部分

$\Sigma_1:z_1=\sqrt{1-x^2-y^2},$

$\Sigma_2:z_2=-\sqrt{1-x^2-y^2}$

$\iint_\Sigma xyzdxdy = \iint_{\Sigma_1} xy\sqrt{1-x^2-y^2}dxdy +\iint_{\Sigma_2} -xy\sqrt{1-x^2-y^2}dxdy $

​				    $=\iint_{D_{xy}}xy\sqrt{1-x^2-y^2}dxdy - \iint_{D_{xy}}xy(-\sqrt{1-x^2-y^2})dxdy$

​				    $= 2\iint_{D_{xy}}xy\sqrt{1-x^2-y^2}dxdy$

### 两类曲线积分的关系

 $\iint_{\Sigma}R(x,y,z)\cos\gamma dS= \pm \iint_{D_{xy}}R[x,y,z(x,y)]dxdy$

所以$\iint_{\Sigma}Pdydz+Qdzdx+Rdxdy=\iint_\Sigma(P\cos \alpha + Q \cos \beta + R \cos \gamma)dS$

曲面$\Sigma$的法向量的方向余弦为
$$
\cos \alpha = \frac{\mp z_x}{\sqrt{1+z_x^2+z_y^2}}\\
\cos \beta  = \frac{\mp z_y}{\sqrt{1+z_x^2+z_y^2}}\\
\cos \gamma = \frac{\pm q}{\sqrt{1+z_x^2+z_y^2}}
$$
注意  法向量的坐标表示为$(\frac{\partial z}{\partial x},\frac{\partial z}{\partial y},-1)$所以$x$方向和$y$方向的方向余弦与$z$方向恰好差一个负号.

$\frac{\cos \alpha}{\cos\gamma} = -z_x,\frac{\cos \beta}{\cos\gamma} = -z_y,$