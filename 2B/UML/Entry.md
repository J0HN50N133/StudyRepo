
# Table of Contents

1.  [UML](#orgaba0464)
    1.  [Lecture01](#org110d3ad)
    2.  [Lecture02](#org20ac3ed)
        1.  [关系](#org24ff387)
        2.  [公共机制](#orgd7cf213)


<a id="orgaba0464"></a>

# UML


<a id="org110d3ad"></a>

## Lecture01

-   SDLC: software design language cycle


<a id="org20ac3ed"></a>

## Lecture02

-   ****keywords**:** 关系，公共机制，图
-   Text Ch 5,6,7


<a id="org24ff387"></a>

### 关系

-   对事物进行抽象的时候会发现事物，如类，很少单独存在。相反大多数事物（类）都以某些方式相互协作。
    -   不仅要识别形成系统词汇的事物，而且还必须对这些事物如何相互联系建模
-   四种最基本的关系
    1.  依赖关系(dependency)
        符号：--&#x2013;&#x2014;>
    2.  泛化关系(generalization)
        符号：————————▷
    3.  关联关系(association)
        符号：————————
    4.  实现关系(realization)
        符号：---&#x2013;&#x2014;▷
-   关系可以进行修饰和描述

1.  依赖关系

    -   符号: A-&#x2013;&#x2014;>B
    -   依赖关系是一种使用关系，说明A使用B的信息和服务。
    -   依赖关系具有时效性。

2.  泛化关系

    -   符号: A——————B
    -   是一般事物（称为超类或父类）和该事物的较为特殊的种类（称为子类）之间的关系
    -   Or "is-a-kind-of"

3.  关联关系

    -   关联关系是一种结构关系
        -   指明一个事物的对象与另一个的对象间的关系
        -   用一条实现连接两个类符号，表示这两个类之间的关联关系
        -   由于是结构性的，这种关系一般是比较稳定的，不像依赖关系一样容易改变。
    
    -   自身关联关系 reflexive association
        -   关联的两端都连到同一个类是完全合法的
        -   表明同一个类的不同对象之间有关系
        -   例如目录，目录可以有子目录，这两者就是同一个类的不同对象之间的关系
    
    1.  关联关系的修饰
    
        -   名称及其方向
        -   角色
            -   在关联的每一端，表明相连的类在该关联关系中的作用
            -   可见性
        
        -   多重性
            多重性是对于关联关系 **另一端** 的类的每个对象， **本端的类可能有多少个对象** 出现。
            
            <table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">
            
            
            <colgroup>
            <col  class="org-left" />
            
            <col  class="org-left" />
            </colgroup>
            <thead>
            <tr>
            <th scope="col" class="org-left">adommment</th>
            <th scope="col" class="org-left">semantics</th>
            </tr>
            </thead>
            
            <tbody>
            <tr>
            <td class="org-left">A..B</td>
            <td class="org-left">from A to B</td>
            </tr>
            
            
            <tr>
            <td class="org-left">\*</td>
            <td class="org-left">zero or more</td>
            </tr>
            </tbody>
            </table>
        
        -   聚合/组合关系(Aggregation/composition)
            -   聚合： **整体** 有管理 **部分** 的特有的职责。用端点带有空菱形的线段表示， **空菱形** 和
                **整体** 类相连接
                -   例如学校和学生的关系，学校没了学生还在。
            -   组合： 整体 拥有 部分 的生命；它用端点带有实菱形的线段表示， **实菱形** 和整体相连。
                -   例如手和手指的关系，手没了手指也就不存在了。
        -   导航性 navigability
            表示运行时可以从链接另一端的实例有效地访问链接这
            一端的分类器实例。
            一般不建议使用，除非导航的意义特别的明确和重要。

4.  连接 Link

    -   Link是关联和关联角色的 **实例**


<a id="orgd7cf213"></a>

### 公共机制

1.  概述

    UML的公共机制有四类
    
    1.  修饰 adornments
        -   注释（Note）
        -   可见性、角色、多重性等，常见于（但不限于）关联中的说明
    
    2.  扩充机制 extensibility mechanisms
        -   构造型（衍型，stereotype)
        -   标记值(tagged value)
        -   约束（constraint)
    
    3.  规格说明 specifications
    4.  公用划分 common divisions
        -   类和对象的划分、接口和实现的划分
        -   类型和角色的划分(略)
    
    `=========`
    本章介绍其中的两种
    修饰和扩充机制

2.  修饰

    -   可见性
        
        <table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">
        
        
        <colgroup>
        <col  class="org-left" />
        
        <col  class="org-left" />
        </colgroup>
        <thead>
        <tr>
        <th scope="col" class="org-left">visability</th>
        <th scope="col" class="org-left">notation</th>
        </tr>
        </thead>
        
        <tbody>
        <tr>
        <td class="org-left">private</td>
        <td class="org-left">-</td>
        </tr>
        
        
        <tr>
        <td class="org-left">protect</td>
        <td class="org-left">#</td>
        </tr>
        
        
        <tr>
        <td class="org-left">public</td>
        <td class="org-left">+</td>
        </tr>
        
        
        <tr>
        <td class="org-left">implementation</td>
        <td class="org-left">~</td>
        </tr>
        </tbody>
        </table>

3.  扩充机制：构造型、标记值、约束

    1.  构造型(stereotype)
        -   可以扩充现有的建模元素，对特定建模问题产生特有的建模元素
        -   这种建模元素就是构造型
        -   定义：类似于现有的UML建模元素，但又对特定的问题领域具有特殊含义的新的建模元素。
        -   构造型的方法：
            -   在标准建模元素的图形上，放置双尖括号&laquo; xxx &raquo; , 括号内是构造型的名字xxx
    
    1.  TODO 补充对三种形式的理解
    
        -   构造型的形式:
            1.  记名的构造型(named stereotype)
            2.  构造型的图标样式(stereotyped element as icon)
            3.  带有图标的记名构造型
        
        1.  标记值(tagged value)
            -   标记值的组成： {标记值的名称, 分隔符, 取值}
                tag = value
                tag是标签名字，value是字面量
            -   tag一般用{}包裹
        2.  公共机制(common mechanism)
            -   约束条件例如： {speed > 100M}, {secure}

