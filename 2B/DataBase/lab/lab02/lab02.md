# 实验一: OpenGauss的基本操作

## 实验内容

- 连接OpenGauss数据库服务器
- 创建和使用数据库
- 查询数据库和数据表的信息
- 创建和删除表
- 向数据表中插入数据
- 从数据表中删除数据
- 基本的查询操作
- OpenGauss语句的批处理

## 实验步骤

完成步骤所需的代码如下。

```sql
-- 1. Show All database
\l

-- 2. Create a new database called "ABCTrading"
DROP database IF EXISTS ABCTrading;
CREATE DATABASE ABCTrading;

-- 3. Set the "ABCTrading" database as the default database.
\c ABCTrading

-- 4. Show all the table in the default database.
\dt

-- 5. Create a new table called "products"
DROP TABLE IF EXISTS products;
CREATE TABLE products(
id int,
category char(3),
name varchar(20),
quantity int,
price float
);

-- 6. Show the table describtion
\d+ products

-- 7. Insert records and list all the records
INSERT INTO products(id, category, name, quantity, price)
VALUES(1001, 'PEN', 'Pen Red', 5000, 1.23);
INSERT INTO products(id, category, name, quantity, price)
VALUES(1001, 'PEN', 'Pen Blue', 8000, 1.25);
INSERT INTO products(id, category, name, quantity, price)
VALUES(1001, 'PEN', 'Pen Black', 2000, 1.25);
INSERT INTO products(id, category, name, quantity, price)
VALUES(1001, 'PCL', 'Pencil 2B', 10000, 0.49);
INSERT INTO products(id, category, name, quantity, price)
VALUES(1001, 'PCL', 'Pencil 2H', 9000, 0.48);
SELECT * FROM products;

-- 8. List records with name containing "Pencil"
SELECT * FROM products WHERE name LIKE '%Pencil%';

-- 9. List records with price >= 1.0
SELECT * FROM products WHERE price >= 1.0;

-- 10. Increase the price of all items by 10%, and list all the records.
UPDATE products SET price = price * 1.1;
SELECT * FROM products;

-- 11. Remove "Pen Red" from the table, and list all the records.
DELETE FROM products WHERE name='Pen Red';
SELECT * FROM products;
```

## 实验结果

运行脚本，输出结果如下：

```
                          List of databases
    Name    | Owner | Encoding | Collate | Ctype | Access privileges 
------------+-------+----------+---------+-------+-------------------
 abctrading | joe   | UTF8     | C       | C     | 
 db_tpcc    | joe   | UTF8     | C       | C     | 
 postgres   | omm   | UTF8     | C       | C     | 
 studentdb  | joe   | UTF8     | C       | C     | 
 template0  | omm   | UTF8     | C       | C     | =c/omm           +
            |       |          |         |       | omm=CTc/omm
 template1  | omm   | UTF8     | C       | C     | =c/omm           +
            |       |          |         |       | omm=CTc/omm
(6 rows)

DROP DATABASE
CREATE DATABASE
You are now connected to database "abctrading" as user "joe".
No relations found.
gsql:trade.sql:15: NOTICE:  table "products" does not exist, skipping
DROP TABLE
CREATE TABLE
                               Table "public.products"
  Column  |         Type          | Modifiers | Storage  | Stats target | Description 
----------+-----------------------+-----------+----------+--------------+-------------
 id       | integer               |           | plain    |              | 
 category | character(3)          |           | extended |              | 
 name     | character varying(20) |           | extended |              | 
 quantity | integer               |           | plain    |              | 
 price    | double precision      |           | plain    |              | 
Has OIDs: no
Options: orientation=row, compression=no

INSERT 0 1
INSERT 0 1
INSERT 0 1
INSERT 0 1
INSERT 0 1
  id  | category |   name    | quantity | price 
------+----------+-----------+----------+-------
 1001 | PEN      | Pen Red   |     5000 |  1.23
 1001 | PEN      | Pen Blue  |     8000 |  1.25
 1001 | PEN      | Pen Black |     2000 |  1.25
 1001 | PCL      | Pencil 2B |    10000 |   .49
 1001 | PCL      | Pencil 2H |     9000 |   .48
(5 rows)

  id  | category |   name    | quantity | price 
------+----------+-----------+----------+-------
 1001 | PCL      | Pencil 2B |    10000 |   .49
 1001 | PCL      | Pencil 2H |     9000 |   .48
(2 rows)

  id  | category |   name    | quantity | price 
------+----------+-----------+----------+-------
 1001 | PEN      | Pen Red   |     5000 |  1.23
 1001 | PEN      | Pen Blue  |     8000 |  1.25
 1001 | PEN      | Pen Black |     2000 |  1.25
(3 rows)

UPDATE 5
  id  | category |   name    | quantity | price 
------+----------+-----------+----------+-------
 1001 | PEN      | Pen Red   |     5000 | 1.353
 1001 | PEN      | Pen Blue  |     8000 | 1.375
 1001 | PEN      | Pen Black |     2000 | 1.375
 1001 | PCL      | Pencil 2B |    10000 |  .539
 1001 | PCL      | Pencil 2H |     9000 |  .528
(5 rows)

DELETE 1
  id  | category |   name    | quantity | price 
------+----------+-----------+----------+-------
 1001 | PEN      | Pen Blue  |     8000 | 1.375
 1001 | PEN      | Pen Black |     2000 | 1.375
 1001 | PCL      | Pencil 2B |    10000 |  .539
 1001 | PCL      | Pencil 2H |     9000 |  .528
(4 rows)

total time: 5512  ms

```

## 总结

增删改查等语句上，psql与我们在课本上学到的别无二致。比较特别的是以下这些命令

| Syntax | Semantics            |
| ------ | -------------------- |
| \l     | 列出所有数据库       |
| \d     | 查看表结构           |
| \d+    | 查看表的详细信息     |
| \dt    | 列出当前数据库所有表 |
| \c     | 切换数据库           |

## 参考资料

[`OpenGauss中的简单数据管理`](https://opengauss.org/zh/docs/1.1.0/docs/Quickstart/%E7%AE%80%E5%8D%95%E6%95%B0%E6%8D%AE%E7%AE%A1%E7%90%86.html)