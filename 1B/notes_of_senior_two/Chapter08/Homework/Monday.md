# 周一作业

## 1.求下列函数的定义域

(2) $z = \ln {(y-x)} + \frac{\sqrt x}{\sqrt {1-x^2-y^2}}$

$$
\begin{cases}
  y - x > 0\\
  1 - x^2 - y^2>0\\
  x > 0\\
\end{cases}
$$
解得
$D = \{(x,y)|x>0 且 x>y 且 x^2+y^2 < 1>\}$

(4) $u = \arccos{\frac{z}{\sqrt {x^2 + y^2}}}$

$$
\begin{cases}
  -1 < \frac{z}{\sqrt {x^2 + y^2}} < 1\\
  x^2+y^2 > 0
\end{cases}
$$
解得
$D = \{(x,y,z)|x^2+y^2 \neq 0 且 -\sqrt {x^2+y^2} \leq z \leq \sqrt {x^2+y^2} \}$

## 2.求下列多元函数的极限

(1) $\lim_{(x,y) \to (1,0)}{\frac{\ln{x+e^y}}{\sqrt{x^2+y^2}}} = \ln{2}$

(2) $\lim_{(x,y) \to (0,0)}{\frac{2 - \sqrt{xy+4}}{xy}} = \lim_{(x,y) \to (0,0)}{\frac{4 - (xy+4)}{xy\sqrt{xy+4}}}=\lim_{(x,y) \to (0,0)}{\frac{1}{\sqrt{xy+4}}} = \frac{1}{2}$

(3) $\lim_{(x,y) \to (0,5)}{\frac{\sin{xy}}{x}} = \lim_{(x,y) \to (0,5)}{\frac{\sin{xy}}{xy} \cdot \frac{xy}{x}} =\lim_{(x,y) \to (0,5)}{y} = 5$

(4) $\lim_{(x,y) \to (0,0)}{\frac{1-\cos{(x^2+y^2)}}{(x^2+y^2)e^{x^2y^2}}}=\lim_{(x,y) \to (0,0)}{\frac{2\sin^2{\frac{x^2+y^2}{2}}}{(x^2+y^2)e^{x^2y^2}}}=\lim_{(x,y) \to (0,0)}{\frac{\sin{\frac{x^2+y^2}{2}}}{\frac{x^2+y^2}{2}}}\cdot\frac{\sin{\frac{x^2+y^2}{2}}}{e^{x^2y^2}}$=0

(5) $\lim_{(x,y) \to (0,0)}{(x^2+y^2)}^{xy}$
$$\lim_{(x,y) \to (0,0)}{(2xy)}^{xy} \leq \lim_{(x,y) \to (0,0)}{(x^2+y^2)}^{xy} \leq \lim_{(x,y) \to (0,0)}{(x^2+y^2)}^{\frac{x^2+y^2}{2}}$$
令$t = 2xy$,则
$\lim_{(x,y) \to (0,0)}{(xy)}^{xy} = \lim_{t \to 0}{t^{\frac{t}{2}}}$

$\lim_{t \to 0} \frac{t}{2}\ln t = \lim_{t \to 0}{\frac{\ln t}{\frac{2}{t}}} = \lim_{t \to 0}{\frac{\frac{1}{t}}{-\frac{2}{t^2}}} = \lim_{t \to 0}{-\frac{t}{2}} = 0$  

则$\lim_{(x,y) \to (0,0)}{(2xy)}^{xy} =  e^0 =1$

同理$\lim_{(x,y) \to (0,0)}{(x^2+y^2)}^{\frac{x^2+y^2}{2}} = 1$

由夹逼定理知,
$\lim_{(x,y) \to (0,0)}{(x^2+y^2)}^{xy} = 1$  

## 3.证明下列极限不存在

$$\lim_{(x,y) \to (0,0)}{\frac{x^2y^2}{x^2y^2+(x - y)^2}}$$
证明:
  $\lim_{(x,y) \to (0,0)}{\frac{x^2y^2}{x^2y^2+(x - y)^2}} = \lim_{(x,y) \to (0,0)}{\frac{1}{1+(\frac{1}{y} - \frac{1}{x})^2}}$
  若$x=y$,则$\lim_{(x,y) \to (0,0)}{\frac{1}{1+(\frac{1}{y} - \frac{1}{x})^2}} = 1$
  若$x \neq y$,则$\lim_{(x,y) \to (0,0)}{\frac{1}{1+(\frac{1}{y} - \frac{1}{x})^2}} = 0$

## 4.讨论下列函数在点$(0,0)$处的连续性

(2)
$$
f(x,y)=
\begin{cases}
  (x+y)\cos\frac{1}{x},   x\neq0\\
  0,                      x=0;
\end{cases}
$$

$\lim_{(x,y) \to (0,0)}{(x+y)\cos\frac{1}{x}} = 0$

则$f(x,y)$在$(0,0)$处连续
(3)
$$
f(x,y)=
\begin{cases}
  \frac{2xy}{x^2+y^2},x^2+y^2\neq 0,\\
  0,x^2+y^2=0.\\
\end{cases}
$$
令$x=ky$,则$\lim_{(x,y) \to (0,0)}{\frac{2xy}{x^2+y^2}} = \lim_{y \to 0}{\frac{2ky^2}{y^2(1+k^2)}}=\lim_{y \to 0}{\frac{2k}{1+k^2}}$
则$f(x,y)$在$(0,0)$处不存在极限，则$f(x,y)$在此处不连续
