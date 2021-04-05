# 实验一：OpenGauss的安装与配置

## OpenGauss数据库管理系统简介

openGauss是关系型数据库,采用客户端/服务器，单进程多线程架构，支持单机和一主多备部署方式，备机可读，支持双机高可用和读扩展。

### 产品特点

openGauss相比其他开源数据库主要有复合应用场景、高性能和高可用等产品特点。

- 复合应用场景
  - 行存储，支持业务数据频繁更新场景。
  - 列存储，支持业务数据追加和分析场景。
  - 内存表，支持高吞吐，低时延，极高性能场景。
- 高性能
  - 通过多核数据结构，增量检查点，大内存缓冲区管理实现百万级tpmC。
  - 服务端连接池，支持万级并发。
- 高可用
  - 支持主备同步，异步多种部署模式。
  - 数据页CRC校验，损坏数据页通过备机自动修复。
  - 备机并行恢复，10秒内可升主提供服务。
- AI能力
  - 具备AI4DB能力，包括参数智能调优与诊断、慢SQL发现、索引推荐、时序预测、异常检测等。
  - 具备DB4AI能力，兼容MADlib生态，支持70+算法，性能比原生MADlib有数倍提升，支持XGBoost、GBDT等高级算法。

### 软件架构

openGauss主要包含了openGauss服务器，客户端驱动，OM等模块。openGauss软件的架构如下图所示。

![image-20210322184448662](/home/ljx/.config/Typora/typora-user-images/image-20210322184448662.png)



## 安装环境

- Linux Release: `Centos 7.9.2009`
- 虚拟机: `QEMU/KVM 5.2.0(openSUSE Tumbleweed)`
- Python: `Python 3.6.8`

## 配置过程

### 新建虚拟机

使用`virt-manager`连接`libvirtd`,点击新建新虚拟系统

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322190846072.png" alt="image-20210322190846072" style="zoom:50%;" />

选择安装镜像

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322190831960.png" alt="image-20210322190831960" style="zoom:50%;" />

选择内存和CPU数量

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322190812777.png" alt="image-20210322190812777" style="zoom:50%;" />

选择磁盘大小

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322190751944.png" alt="image-20210322190751944" style="zoom:50%;" />

配置网络，这里我选择了`NAT`而没有像实验手册里那样使用两块网卡创建网络。

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322191052454.png" alt="image-20210322191052454" style="zoom:50%;" />

选择最小化安装，安装完成效果如下图

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322191435548.png" alt="image-20210322191435548" style="zoom:50%;" />

接下来进行一个网络的确认

### 确认网络

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322191930935.png" alt="image-20210322191930935" style="zoom:50%;" />

### 环境准备

#### 修改操作系统版本

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322192217375.png" alt="image-20210322192217375" style="zoom:50%;" />![image-20210322192406960](/home/ljx/.config/Typora/typora-user-images/image-20210322192406960.png)

#### 关闭防火墙

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322192428287.png" alt="image-20210322192428287" style="zoom:50%;" />

#### 设置字符集及环境变量

这里我使用`vim`直接写入

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322192534333.png" alt="image-20210322192534333" style="zoom:50%;" />

验证变量是否生效

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322192734118.png" alt="image-20210322192734118" style="zoom:50%;" />

#### 关闭交换内存

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322192841843.png" alt="image-20210322192841843" style="zoom:50%;" />

#### yum换源

阿里云最近在更新，无法使用于是使用华为云

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322193013313.png" alt="image-20210322193013313" style="zoom:50%;" />

#### 安装必要的包

![image-20210322193312417](/home/ljx/.config/Typora/typora-user-images/image-20210322193312417.png)

#### 更改默认Python版本

![image-20210322193401650](/home/ljx/.config/Typora/typora-user-images/image-20210322193401650.png)

修改`yum`

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322193513577.png" alt="image-20210322193513577" style="zoom:50%;" />

发现`yum`依然不能使用

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322193836468.png" alt="image-20210322193836468" style="zoom:50%;" />

按照报错信息知道，`/usr/libexec/urlgrabber-ext-down`发生了错误，需要进行修改。

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322194131728.png" alt="image-20210322194131728" style="zoom:50%;" />

将上图方框处`python`改为 `python2.7`即可。

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322194252720.png" alt="image-20210322194252720" style="zoom:50%;" />

修改成功

### 正式安装数据库

#### 下载数据库安装包

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322195231637.png" alt="image-20210322195231637" style="zoom:33%;" />

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322195306882.png" alt="image-20210322195306882" style="zoom:67%;" />



#### 解压安装包

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322195605954.png" alt="image-20210322195605954" style="zoom:50%;" />

#### 编写配置文件

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322200113231.png" alt="image-20210322200113231" style="zoom:50%;" />

接下来只需要按照实验手册运行初始化脚本，初始化数据库即可。我们快进到安装结束，验证安装是否正确。

## 验证是否安装正确

#### 登陆数据库节点，启动服务并连接数据库

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322200918770.png" alt="image-20210322200918770" style="zoom:50%;" />

### 修改用户密码

#### 创建数据库

（这里是后补的图所以数据库已经存在了）

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322201658326.png" alt="image-20210322201658326" style="zoom:50%;" />

#### 创建schema

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322201501758.png" alt="image-20210322201501758" style="zoom:50%;" />

#### 创建表，插入数据并查看

<img src="/home/ljx/.config/Typora/typora-user-images/image-20210322201952405.png" alt="image-20210322201952405" style="zoom:50%;" />

## 实验过程中遇到的问题及解决方法

- 按照实验手册修改后的yum并不能正常使用，需要按照[更改默认Python版本](#更改默认python版本)小节中的方法修改`/usr/libexec/urlgrabber-ext-down`yum才可正常使用。

## 参考资料

- 实验手册

- [openGuass官方文档](https://opengauss.org/zh/docs/1.1.0/docs/installation/%E5%AE%89%E8%A3%85openGauss.html)

