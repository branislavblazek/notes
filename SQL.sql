SELECT * FROM customers;
	vyberie mi vsetko z customers

SELECT contact_name, contact_title, address FROM customers;
	vyberie mi len konkretne stlpce

SELECT DISTINCT country FROM customers;
	vyberie mi len jedinecne udaje

SELECT COUNT(DISTINCT country) FROM customers;
	vrati pocet jedinecnych poloziek

SELECT city FROM customers WHERE country='Germany';
	vrati nazov mesta kde krajina je Germany
SELECT * FROM customers WHERE country IN ('Mexico', 'Germany');
	= rovnake ako
	> vacsie nez
	< mensie nez
	>= vacsie nez
	<= mensie nez
	<> nerovne
	BETWEEN v rozmedzi
	LIKE pattern
	IN viac moznosti v stlpci
SELECT * FROM Customers WHERE Country IN (SELECT Country FROM Suppliers);
	vrati Customers ktorych Country je aj v Country z Suppliers

SELECT * FROM Products WHERE unit_price BETWEEN 20 AND 30 AND category_id NOT BETWEEN 1 AND 3 ORDER BY unit_price;
	riadky kde je unit_price medzi 20 a 30 a cetegory nie je medzi 1 a 3 a usporiadene podla unit_price

SELECT * from customers WHERE country='USA' AND region='WA';
	riadok musi mat country='USA' a region='WA'

SELECT * from customers WHERE country='Canada' OR country='Mexico';
	riadok obsahuje country='Canada' alebo country='Mexico'

SELECT * from customers WHERE country='Canada' AND NOT region='BC';
	riadok kde je country='Canada' a nie je region='BC'

SELECT * FROM Customers WHERE Country='Germany' AND (City='Berlin' OR City='München');
	riaodk kde je country='Germany' a city='Berlin' alebo city='Munchcen'

SELECT * FROM Customers ORDER BY Country;
	vrati riadky usporiadane podla Country

SELECT * FROM Customers ORDER BY Country DESC;
	vrati riadky usporiadane podla Country opacne

SELECT city, country FROM Customers WHERE country IN ('Germany', 'USA') ORDER BY Country DESC, city;
	viacnasobne usporiadanie

SELECT * FROM Customers WHERE fax IS NOT NULL;
	vrati mi vsetko kde fax ma nejaku hodnotu

SELECT * FROM Customers WHERE country='USA' LIMIT 2;
	vrati mi maximalny pocet vysledkov

SELECT MAX(unit_price) FROM Products;
	vrati maximalnu hodnotu stplca

SELECT MIN(unit_price) FROM Products;
	vrati minimalnu hodnotu stplca

SELECT AVG(units_on_order) FROM Products;
	vrati avg stlpca

SELECT COUNT(units_in_stock) FROM Products;
	vrati pocet riadkov podla stlpca

SELECT SUM(units_in_stock) FROM Products;
	vrati sucet vsetkych hodnot v riadkoch podla stlpca

WHERE CustomerName LIKE 'a%'	Finds any values that start with "a"
WHERE CustomerName LIKE '%a'	Finds any values that end with "a"
WHERE CustomerName LIKE '%or%'	Finds any values that have "or" in any position
WHERE CustomerName LIKE '_r%'	Finds any values that have "r" in the second position
WHERE CustomerName LIKE 'a_%'	Finds any values that start with "a" and are at least 2 characters in length
WHERE CustomerName LIKE 'a__%'	Finds any values that start with "a" and are at least 3 characters in length
WHERE ContactName LIKE 'a%o'	Finds any values that start with "a" and ends with "o"



UPDATE Customers SET phone='421904123059' WHERE country='Slovakia';
	updatne vsetky riadky na phone='xxx' kde country='Slovakia'
	bez WHERE mi to premeni vsetky riadky!!!!

UPDATE Customers SET phone='421904123059', fax='123' WHERE country='Slovakia';
	viacnasobny update

DELETE FROM Customers WHERE fax='123';
	Vymaze riadky kde fax='123'
	bez WHERE mi to premeni vsetky riadky!!!!

DELETE FROM Customers;
	Vymaze celu tabulku

INSERT INTO Customers (customer_id, company_name, contact_name, contact_title, address, city, region, postal_code, country) VALUES ('BACDE', 'Tarinkasoft', 'Branislav Blazek', 'Owner', 'Malinova 7', 'Zilina', 'ZA', '01004', 'Slovakia');
	Vlozi do Customers novy riadok. Na zvysne nevyplnene hodnoty mi nastavu null,
	ak vymenujem vsetky potrebne VALUES, nepotrebujem vypisovat column names
