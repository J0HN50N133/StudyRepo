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
