CREATE DATABASE Sport_shop
GO
USE Sport_shop
GO

CREATE TABLE Products
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] NVARCHAR(MAX) NOT NULL,
[Type] NVARCHAR(MAX) NOT NULL,
Amount INT NOT NULL,
Cost_price MONEY NOT NULL CHECK (Cost_price > 0),
Producer NVARCHAR(MAX) NOT NULL,
Price MONEY NOT NULL CHECK (Price > 0)
);
GO

INSERT INTO Products([Name], [Type], Amount, Cost_price, Producer, Price)
VALUES ('��������', '���������', 5, 85, '���������', 150),
		('�������', '���������', 5, 85, '�����', 150),
		('�����', '����', 15, 120, '���������', 250),
		('������', '���������', 10, 450, '������', 700),
		('������� �����', '������', 20, 800, '������', 1500)
GO

CREATE TABLE Employees
(
Id INT PRIMARY KEY IDENTITY(1,1),
FullName NVARCHAR(100) NOT NULL, Check(LEN(FullName) > 0),
HireDate DATE NOT NULL CHECK (HireDate <= GETDATE()),
Gender NVARCHAR(10) NOT NULL,
Position NVARCHAR(MAX) NOT NULL,
Salary MONEY CHECK (Salary > 0)
);
GO

INSERT INTO Employees(FullName, HireDate, Gender, Position, Salary)
VALUES ('������ ���� ��������', '2020-05-30', 'M', '��������', 8500),
('��������� ������� ��������', '2020-05-06', 'F', '��������', 6500),
('������ ������ ���������', '2020-05-07', 'M', '�������', 7000),
('����� ���� ��������', '2020-05-15', 'M', '���������', 5500);
GO

CREATE TABLE Customers
(
Id INT PRIMARY KEY IDENTITY(1,1),
FullName NVARCHAR(100) NOT NULL, Check(LEN(FullName) > 0),
Email VARCHAR(MAX) NOT NULL,
Phone VARCHAR(MAX) NOT NULL,
Gender NVARCHAR(10) NOT NULL,
Discount INT NOT NULL DEFAULT 0,
IsSubscribed BIT DEFAULT 0,
HistoryOfOrders VARCHAR(MAX)
);
GO

INSERT INTO Customers(FullName, Email, Phone, Gender, Discount, IsSubscribed, HistoryOfOrders)
VALUES ('������ ������ ���������', 'ss@c.com', '0971234567', 'M', 10, 0, ''),
('�������� ���� ����������', 'rls@rr.org', '0989876543', 'M', 25, 0, ''),
('�������� ������� ���������', 'fgfgfg@rr.org', '0989876543', 'F', 10, 0, ''),
('����� ��� ��������', 'ggggg@rr.org', '0989876543', 'M', 7, 0, ''),
('��������� ������� �������', 'ttre@rr.org', '0989876543', 'F', 12, 0, ''),
('������� ��� ��������', 'dd@rr.org', '0989876543', 'M', 10, 0, '')
GO

CREATE TABLE Salles
(
Id INT IDENTITY(1, 1) NOT NULL PRIMARY KEY,
ProductId INT REFERENCES Products(Id) NOT NULL,
Price MONEY NOT NULL,
Amount INT NOT NULL,
EmployeeId INT REFERENCES Employees(Id) NOT NULL,
ClientId INT REFERENCES Customers(Id) NOT NULL,
);
GO

INSERT INTO Salles(ProductId, Price, Amount, EmployeeId, ClientId)
VALUES  (1, 10000, 1, 1, 1),
		(1, 100, 1, 1, 1),
		(4, 1800, 1, 2, 2),
		(2, 10000, 3, 4, 2)
GO

CREATE TABLE History
(
	Id INT IDENTITY PRIMARY KEY,
	[Message] NVARCHAR(MAX) NOT NULL,
	[Date] DATETIME DEFAULT(GETDATE()) NOT NULL
)

create table Archive
(
	Id INT IDENTITY PRIMARY KEY,
	[Message] NVARCHAR(MAX) NOT NULL,
	[Date] DATETIME DEFAULT(GETDATE()) NOT NULL
)

--- 1. ���������� ��������� �������� �볺���
CREATE TRIGGER tg_deny_delete_customer
ON Customers
AFTER DELETE
AS
BEGIN
	RAISERROR('Cannot delete customer!', 15, 1);
	ROLLBACK;
END;

DELETE FROM Customers WHERE id = 3

--- 2. ���������� �������� ������ ����������� ���������.
CREATE OR ALTER TRIGGER tg_deny_adding_product_from_china
ON Products
AFTER INSERT
AS
	DECLARE @product_id INT;
	SELECT @product_id = p.Id FROM Products AS p
	IF(SELECT i.Producer FROM inserted AS i WHERE i.Id = @product_id) = '�����'
		BEGIN
			PRINT 'Cannot adding products from China!';
			ROLLBACK
		END


SELECT * FROM Products

INSERT INTO Products([Name], [Type], Amount, Cost_price, Producer, Price)
VALUES ('�������� �����', '������', 2, 523, '���������', 650),
		('������� �''��', '���������', 6, 79, '�����', 110)

--- 3. ��� ������ ��������� ������� ������ � ��������. ���� �� �� ���������, ��� ���������� ������.

CREATE OR ALTER TRIGGER tg_set_amount_of_product
ON Salles
AFTER INSERT
AS
			IF NOT EXISTS (SELECT * FROM Products AS p JOIN inserted AS i ON p.Id = i.ProductId WHERE (p.Amount - i.amount) < 0)
				BEGIN
					UPDATE p
					SET p.Amount -= i.Amount
					FROM inserted AS i JOIN Products AS p ON i.ProductId = p.Id
					WHERE p.Amount >= i.Amount              
				END
			ELSE ROLLBACK

SELECT * FROM Products
SELECT * FROM Salles

INSERT INTO Salles(ProductId, Price, Amount, EmployeeId, ClientId)
VALUES  (1, 10000, 2, 1, 1),
		(2, 279, 1, 1, 2)

--- 4. �� ��������� ���������� ��� ��������� �볺���. ��� ������� ��������� �������� �볺��� �� email.
CREATE OR ALTER TRIGGER tg_check_exist_customer
ON Customers
AFTER INSERT
AS
		IF EXISTS (SELECT i.Id FROM inserted AS i 
					WHERE EXISTS (SELECT Id FROM Customers AS c WHERE c.Email = i.Email AND c.Id <> i.Id))
		BEGIN
		PRINT 'Customer with this email is existed!'
			ROLLBACK
		END

SELECT * FROM Customers

INSERT INTO Customers(FullName, Email, Phone, Gender, Discount, IsSubscribed, HistoryOfOrders)
VALUES ('����� ��������� ��������', 'alex@c.com', '0967217411', 'M', 10, 0, ''),
('�������� ���� �����������', 'Gor@rr.org', '0989876543', 'M', 25, 0, ''),
('�������� ������� ���������', 'fgfgfg@rr.org', '0989876543', 'F', 10, 0, ''),



--- 5. ��� ������ ������, �������� ���������� ��� ������� � ������� ��������. ������� �������� ��������������� ��� ������� ���������� ��� �� ������.

CREATE OR ALTER TRIGGER tg_archive_new_sale
ON Salles
AFTER INSERT
AS
		INSERT INTO History ([Message])
		(SELECT 'Item: ' + (p.[Name]) + ', Price: ' + CAST(i.Price AS VARCHAR(10)) + ', Amount: ' +
		CAST(i.Amount AS VARCHAR(5)) + ', Employyer: ' + (e.[FullName]) + ', Customer: ' + (c.[FullName])
		FROM inserted AS i JOIN Products AS p ON i.ProductId = p.Id
						 JOIN Employees AS e ON i.EmployeeId =e.Id
						 JOIN Customers AS c ON i.ClientId = c.Id)

--- 6. ���� ���� ������� ������ �� ���������� ����� ������� ������ ������, ��������� ��������� ���������� ��� ������� �������� ����� � ������� ������.
CREATE OR ALTER TRIGGER tg_chech_zero_product
ON Salles
AFTER INSERT
AS
			INSERT INTO Archive ([Message])
			(SELECT 'Item: ' + p.[Name] + ', Type: ' + p.[Type] + ', Produser: ' + p.Producer FROM Products AS p JOIN inserted AS i ON i.ProductId = p.Id 
			WHERE (p.Amount - i.Amount) <= 0)


SELECT * FROM Products
SELECT * FROM Salles

INSERT INTO Salles(ProductId, Price, Amount, EmployeeId, ClientId)
VALUES  (2, 10000,11, 1, 1),
		(3, 100, 15, 1, 2)


SELECT * FROM Archive

--- 7. ��� ���� ������� ������ ������� ��������� �������� ���� ������� �볺���. ���� ���� ���������� 50000 ���, ��������� ���������� ������� ������ � 15%

select SUM(Price * Amount)
from Salles
where ClientId = 1

CREATE or ALTER TRIGGER tg_set_sale
ON Salles
AFTER INSERT
AS
	DECLARE @client_id INT;
	DECLARE @sale_id INT;

	SELECT @client_id = i.ClientId, @sale_id = i.Id
	FROM inserted AS i
	IF (SELECT SUM(Price * Amount)
		FROM Salles
		WHERE ClientId = @client_id) > 50000
	BEGIN
		UPDATE Customers
		SET Discount = 15
		WHERE Id = @client_id

		UPDATE Salles
		SET Price -= Price * 0.15
		WHERE Id = @sale_id
	END;














