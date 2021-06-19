---===================================  DB Phone_book   ============================================
/*Задание 1. Создайте базу данных «Телефонный спра­вочник». 
Эта база данных должна содержать одну таблицу «Люди». 
В таблице нужно хранить: ФИО человека, дату рождения, пол, телефон, город проживания, страна про­живания, домашний адрес. 
Для создания базы данных используйте запрос CREATE DATABASE. 
Для создания таблицы используйте запрос CREATE TABLE.*/

CREATE DATABASE Phone_book
GO
USE Phone_book
GO

														----- CREATE TABLES -----

CREATE TABLE People
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(MAX) NOT NULL,
Surname VARCHAR(MAX) NOT NULL,
Gender VARCHAR(MAX) NOT NULL,
Country VARCHAR(MAX) NOT NULL,
City VARCHAR(MAX) NOT NULL,
[Address] VARCHAR(MAX) NOT NULL,
Phone VARCHAR(MAX) NOT NULL,
[BirthDate] DATE NOT NULL CHECK ([BirthDate] <= GETDATE()),
);
GO

															----- INSERT TABLES -----

INSERT INTO People ([Name], Surname, Gender, Country, City, [Address], Phone, BirthDate)
VALUES
('Brnaby', 'Venmore', 'Polygender', 'Kenya', 'Makueni', '0 Bunting Avenue', '482-376-3355', '4/29/1990'),
('Shari', 'Blore', 'Non-binary', 'Brazil', 'Plácido de Castro', '83631 Dennis Circle', '240-575-2186', '7/13/2019'),
('Jacquelin', 'Shory', 'Female', 'China', 'Qidi', '181 Dahle Point', '353-152-0536', '9/27/2018'),
('Emmeline', 'Patullo', 'Non-binary', 'Kuwait', 'Al Jahrā’', '12 Graceland Street', '234-844-3787', '7/28/1998'),
('Holli', 'Rein', 'Genderqueer', 'France', 'Nantes', '0179 Wayridge Avenue', '440-759-7517', '2/20/2019'),
('Iain', 'Cutbirth', 'Non-binary', 'France', 'Saint-Laurent-Blangy', '072 Hooker Road', '280-565-4240', '2/15/2020'),
('Adamo', 'Gounard', 'Non-binary', 'Ukraine', 'Olyshivka', '778 Columbus Hill', '252-469-2070', '5/22/1992'),
('Brigham', 'Lygo', 'Genderfluid', 'Philippines', 'Guijalo', '45 Sutteridge Center', '512-476-2598', '3/15/2010'),
('Ellie', 'Jagiello', 'Female', 'China', 'Huangqiao', '8 Parkside Place', '776-422-0736', '10/27/2005'),
('Darbee', 'Cauldfield', 'Genderqueer', 'Philippines', 'Albuera', '47 Kinsman Terrace', '129-241-6191', '6/30/1997');

---===================================  DB Sales   ============================================
/*Задание 2. Создайте базу данных «Продажи». 
База данных должна содержать информацию о продавцах, покупателях, продажах. Необходимо хранить следующую информацию:
1. О продавцах: ФИО, email, контактный телефон
2. О покупателях: ФИО, email, контактный телефон
3. О продажах: покупатель, продавец, название товара, цена продажи, дата сделки.
Для  создания  базы  данных  используйте  запрос  CREATE  DATABASE.  
Для   создания   таблицы   используйте   запрос   CREATE TABLE. 
Обязательно при создании таблиц задавать связи между ними.*/

CREATE DATABASE Sales
GO
USE Sales
GO

													----- CREATE TABLES -----

CREATE TABLE Seller
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(MAX) NOT NULL,
Surname VARCHAR(MAX) NOT NULL,
Email VARCHAR(MAX) NOT NULL,
Phone VARCHAR(MAX) NOT NULL,
);
GO

CREATE TABLE Buyer
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(MAX) NOT NULL,
Surname VARCHAR(MAX) NOT NULL,
Email VARCHAR(MAX) NOT NULL,
Phone VARCHAR(MAX) NOT NULL,
);
GO

CREATE TABLE Selling
(
Id INT PRIMARY KEY IDENTITY(1,1),
SellerId INT NOT NULL FOREIGN KEY REFERENCES Seller (Id),
BuyerId INT NOT NULL FOREIGN KEY REFERENCES Buyer (Id),
ItemName VARCHAR(MAX) NOT NULL,
Price MONEY NOT NULL CHECK (Price > 0),
[SellingDate] DATE NOT NULL CHECK ([SellingDate] <= GETDATE()),
);
GO

															----- INSERT TABLES -----

INSERT INTO Seller ([Name], Surname, Email, Phone)
VALUES
('Julieta', 'Garci', 'jgarci0@amazon.co.jp', '713-898-6434'),
('Fletch', 'Radish', 'fradish1@reverbnation.com', '947-454-8209'),
('Allayne', 'O''Cuddie', 'aocuddie2@theglobeandmail.com', '987-232-6652'),
('Lowrance', 'Lummus', 'llummus3@ebay.com', '509-522-9069'),
('Miguelita', 'Chessor', 'mchessor4@wix.com', '267-353-4810'),
('Regen', 'Andrivot', 'randrivot5@ow.ly', '441-453-1776'),
('Jasmin', 'Thoma', 'jthoma6@tuttocitta.it', '878-642-9486'),
('Morlee', 'Camois', 'mcamois7@aboutads.info', '173-158-5828'),
('Thomasina', 'Fulle', 'tfulle8@technorati.com', '465-766-7982'),
('Ange', 'Daingerfield', 'adaingerfield9@webeden.co.uk', '178-440-5214');

INSERT INTO Buyer ([Name], Surname, Email, Phone)
VALUES
('Bar', 'Harrisson', 'bharrisson0@people.com.cn', '388-595-6265'),
('Hanan', 'Humbell', 'hhumbell1@nsw.gov.au', '229-300-2985'),
('Vonnie', 'Frosdick', 'vfrosdick2@infoseek.co.jp', '945-202-3630'),
('Brennen', 'Boulger', 'bboulger3@ehow.com', '521-763-3392'),
('Neil', 'Paulmann', 'npaulmann4@canalblog.com', '496-705-9246'),
('Evie', 'Brundell', 'ebrundell5@bing.com', '220-524-1739'),
('Pooh', 'Shewan', 'pshewan6@nyu.edu', '137-931-8752'),
('Francoise', 'Castellan', 'fcastellan7@blog.com', '995-702-7427'),
('Channa', 'Domanek', 'cdomanek8@behance.net', '762-979-4650'),
('Boote', 'Douthwaite', 'bdouthwaite9@nasa.gov', '651-201-8397');

INSERT INTO Selling (SellerId, BuyerId, ItemName, Price, SellingDate)
VALUES
(1, 7, 'Sprouts - Baby Pea Tendrils', '$2.48', '6/15/2020'),
(6, 4, 'Sausage - Meat', '$6.88', '3/8/2021'),
(10, 3, 'Energy Drink - Franks Pineapple', '$8.52', '12/8/2020'),
(4, 10, 'Foie Gras', '$7.75', '11/24/2020'),
(5, 9, 'Tomato - Tricolor Cherry', '$6.76', '12/23/2020'),
(9, 1, 'Pastry - Raisin Muffin - Mini', '$5.05', '11/26/2020'),
(2, 2, 'Beef - Striploin', '$5.84', '6/6/2020'),
(3, 5, 'Pork - Bacon, Sliced', '$2.17', '5/3/2021'),
(8, 6, 'Yams', '$7.13', '3/29/2021'),
(7, 8, 'Spice - Peppercorn Melange', '$3.32', '1/1/2021');


---===================================  DB Music_collection   ============================================

/*Задание 3. Создайте базу данных «Музыкальная коллек­ция». 
База данных должна содержать информацию о музы­кальных дисках, исполнителях, стилях. Необходимо хранить следующую информацию:
1. О музыкальном диске: название диска, исполнитель, дата выпуска, стиль, издатель
2. О стилях: названия стилей
3. Об исполнителях: название
4. Об издателях: название, страна
5. О песнях: название песни, название диска, длительность песни, музыкальный стиль песни, исполнитель.
Продумайте  правильную  структуру  базы  данных.  
Для  создания базы данных используйте запрос CREATE DATA­BASE. 
Для создания таблицы используйте запрос CREATE TABLE.  
Обязательно  при  создании  таблиц  задавать  связи  между ними.*/

CREATE DATABASE Music_collection
GO
USE Music_collection
GO

															----- CREATE TABLES -----

CREATE TABLE Styles
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(MAX) NOT NULL,
);
GO

CREATE TABLE Artists
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(MAX) NOT NULL,
);
GO

CREATE TABLE Publishers
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(MAX) NOT NULL,
Country VARCHAR(MAX) NOT NULL,
);
GO

CREATE TABLE Music_disc
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(MAX) NOT NULL,
ArtistId INT NOT NULL FOREIGN KEY REFERENCES Artists (Id),
StyleId INT NOT NULL FOREIGN KEY REFERENCES Styles (Id),
PublisherId INT NOT NULL FOREIGN KEY REFERENCES Publishers (Id),
Release DATE NOT NULL CHECK (Release <= GETDATE()),
);
GO

CREATE TABLE Songs
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(MAX) NOT NULL,
Disk_name INT NOT NULL FOREIGN KEY REFERENCES Music_disc (Id),
StyleId INT NOT NULL FOREIGN KEY REFERENCES Styles (Id),
ArtistId INT NOT NULL FOREIGN KEY REFERENCES Artists (Id),
Duration INT NOT NULL CHECK (Duration > 1),
);
GO

													----- INSERT TABLES -----

INSERT INTO Styles ([Name])
VALUES
('Hip-hop'),('Indie rock'),('Jazz'),('Metal'),
('Rap'),('Pop'),('R&B'),('Rock'),
('Electronic dance music'), ('Techno');
GO

INSERT INTO Artists([Name])
VALUES
('Eminem'),('Elton John'),('Metallica'),('The Prodigy'),
('Drake'),('The Beatles'),('Coldplay'),('Slipknot'),
('David Guetta'), ('Moby');
GO

INSERT INTO Publishers([Name], Country)
VALUES
('Wixen Music', 'USA'),('Atlas Music', 'USA'),('Kobalt Music', 'USA'),('Downtown Music', 'USA'),
('Sony ATV Music', 'USA'),('Concord Music', 'USA'),('Universal Music', 'USA');
GO

INSERT INTO Music_disc ([Name], ArtistId, StyleId, PublisherId, Release)
VALUES
('Cardify', 9, 5, 16, '7/5/2007'),('Stringtough', 4, 9, 20, '10/8/2020'),('Regrant', 10, 10, 17, '2/22/2021'),
('Asoka', 1, 2, 19, '5/25/2021'),('Zamit', 5, 8, 21, '1/7/2000'),('Zaam-Dox', 8, 5, 22, '10/4/1990'),
('Job', 2, 1, 20, '7/14/2010'),('Wrapsafe', 4, 7, 18, '11/13/2020'),('Temp', 9, 6 , 20, '6/14/2009'),
('Tempsoft', 3, 4, 19, '5/30/1993'),('Domainer', 2, 2, 21, '4/2/2000'),('Bitwolf', 7, 3, 20, '10/10/2014'),
('Sonair', 1, 1, 16, '1/11/1996'),('Fixflex', 7, 1, 19, '9/14/2007'),('Fix San', 6, 6, 22, '5/2/2005');
GO


INSERT INTO Songs ([Name], Disk_name, StyleId, ArtistId, Duration)
VALUES
('Alphazap', 30, 1, 8, 3),('Viva', 22, 10, 3, 4),('Gembucket', 26, 8, 5, 5),('Job', 25, 7, 4, 3),
('Pannier', 22, 5, 5, 4),('Kanlam', 23, 6, 6, 4),('Pannier', 34, 7, 7, 4),('Alphazap', 26, 2, 8, 4),
('It', 30, 5, 9, 3),('Voltsillam', 35, 5, 1, 6),('Daltfresh', 23, 9, 2, 4),('Flowdesk', 29, 4, 5, 4),
('Greenlam',31, 9, 4, 5),('Bigtax', 36, 4, 1, 7),('Biodex', 33, 2, 10, 4),('Aerified', 26, 9, 1, 3),
('Tres-Zap', 30, 7, 10, 7),('Zamit', 32, 6, 3, 8),('Greenlam', 25, 2, 6, 4),('Tampflex', 31, 5, 8, 5),
('Ronstring', 26, 1, 1, 4),('Cardguard', 31, 3, 5, 4),('Sonair', 28, 7, 8, 4),('Bitchip', 24, 2, 2, 6),('Ronstring', 27, 10, 9, 7);
GO

/*Задание 4. Все задания необходимо выполнить по отно­шению к базе данных из третьего задания:
1. Добавьте  к  уже  существующей  таблице  с  информацией  о музыкальном диске столбец с краткой рецензией на него
2. Добавьте к уже существующей таблице с информацией об издателе столбец с юридическим адресом главного офиса
3. Измените в уже существующей таблице с информацией о песнях размер поля, хранящий название песни
4. Удалите из уже существующей таблицы с информацией об  издателе  столбец  с  юридическим  адресом  главного  офиса*/

ALTER TABLE Music_disc
ADD Review VARCHAR(MAX) NULL;
GO

ALTER TABLE Publishers
ADD Head_office VARCHAR(MAX) NULL;
GO

ALTER TABLE Songs
ALTER COLUMN [Name] VARCHAR(MAX) NULL;
GO

ALTER TABLE Publishers
DROP COLUMN Head_office;
GO

/*Задание 5. Создайте следующие представления. 
В качестве базы данных используйте базу данных из третьего задания:
1. Представление отображает названия всех стилей
2. Представление отображает названия всех издателей
3. Представление отображает полную информацию о диске: 
название диска, исполнитель, дата выпуска, стиль, издатель.*/

													----- CREATE VIEWS -----

CREATE OR ALTER VIEW AllStyles ([Style name]) AS 
SELECT DISTINCT [Name] FROM Styles;
GO

CREATE OR ALTER VIEW AllPublisher ([Publiser name]) AS
SELECT DISTINCT [Name] FROM Publishers;
GO

CREATE OR ALTER VIEW DiscFullInfo ([Disc name], Artist, [Release date], [Music style], Publisher) AS
SELECT d.[Name], a.[Name], d.Release, s.[Name], p.[Name]
FROM Music_disc AS d JOIN Artists AS a ON d.ArtistId = a.Id 
					 JOIN Styles AS s ON d.StyleId = s.Id
					 JOIN Publishers AS p ON d.PublisherId = p.Id;
GO

										---   HOME WORK ---
---Представление отображает названия всех исполнителей
CREATE OR ALTER VIEW AllArtists ([Artist name]) AS
SELECT [Name] FROM Artists;

---Представление отображает полную информацию о всех песнях: название песни, название диска, длительность песни, музыкальный стиль песни, исполнитель
CREATE OR ALTER VIEW AllSongsInfo ([Song name], [Disk name], Duration, Style, Artist) AS
SELECT s.[Name], md.[Name], s.Duration, st.[Name], a.[Name]
FROM Songs AS s JOIN Music_disc AS md ON s.Disk_name = md.Id
				JOIN Styles AS st ON s.StyleId = st.Id
				JOIN Artists AS a ON s.ArtistId = a.Id;

---Представление отображает информацию о музыкальных дисках конкретной группы. Например, Te Beatles
CREATE OR ALTER VIEW MobyDisk AS
SELECT * FROM DiscFullInfo
WHERE Artist = 'Moby';

SELECT * FROM MobyDisk
--- Представление отображает название самого популярного в коллекции исполнителя. Популярность определяется по количеству дисков в коллекции
CREATE OR ALTER VIEW TopOneArtist AS
SELECT TOP 1 a.[Name], COUNT(md.Id) AS 'Amount of discs'
FROM Music_disc AS md JOIN Artists AS a ON md.ArtistId = a.Id
GROUP BY a.[Name]
ORDER BY 'Amount of discs' DESC;

--- Представление отображает топ-3 самых популярных в коллекции исполнителей. Популярность определяется по количеству дисков в коллекции
CREATE OR ALTER VIEW TopThreeArtist AS
SELECT TOP 3 a.[Name], COUNT(md.Id) AS 'Amount of discs'
FROM Music_disc AS md JOIN Artists AS a ON md.ArtistId = a.Id
GROUP BY a.[Name]
ORDER BY 'Amount of discs' DESC;

--- Представление отображает самый длиный музыкальный альбом
CREATE OR ALTER VIEW TopDiscByDuration AS
SELECT TOP 1 d.[Name] AS 'Disk name', SUM(s.Duration) AS 'Duration of albom (min)'
FROM Music_disc AS d JOIN Songs AS s ON d.Id = s.Disk_name
GROUP BY d.[Name]
ORDER BY 'Duration of albom (min)' DESC

--- Создайте обновляемое представление, которое позволит вставлять новые стили
CREATE VIEW newStyle AS
SELECT [Name] FROM Styles;

INSERT INTO newStyle ([Name])
VALUES('Disco');

--- Создайте обновляемое представление, которое позволит вставлять новые песни
CREATE VIEW NewSong AS
SELECT [Name], Disk_name, StyleId, ArtistId, Duration
FROM Songs;

INSERT INTO NewSong ([Name], Disk_name, StyleId, ArtistId, Duration)
VALUES('Blue tree', 26, 8, 4, 5);

--- Создайте обновляемое представление, которое позволит обновлять информацию об издателе
CREATE VIEW NewPublisher AS
SELECT Id, [Name], Country
FROM Publishers

UPDATE NewPublisher
SET [Name] = 'Downtown Music Family'
WHERE id = 19

--- Создайте обновляемое представление, которое позволит удалять исполнителей
CREATE VIEW DelArtisr AS
SELECT [Name]
FROM Artists

INSERT INTO DelArtisr
VALUES('Zibrov');

DELETE FROM DelArtisr
WHERE [Name] = 'Zibrov';

--- Создайте обновляемое представление, которое позволит обновлять информацию о конкретном исполнителе. Например, Coldplay.
CREATE OR ALTER VIEW UpdateColdplay AS
SELECT Id, [Name] FROM Artists
WHERE Id = 7
WITH CHECK OPTION;

UPDATE UpdateColdplay
SET [Name] = 'The Coldplay'
WHERE Id = 7;


---=================   USE DB SALES   =================---
--- Создайте обновляемое представление, которое отображает информацию о всех продавцах
CREATE VIEW SellerFullInfo AS
SELECT Id, [Name], Surname, Email, Phone
FROM Seller

SELECT * FROM SellerFullInfo

--- Создайте обновляемое представление, которое отображает информацию о всех покупателях
CREATE VIEW BuyerFullInfo AS
SELECT Id, [Name], Surname, Email, Phone
FROM Buyer

SELECT * FROM BuyerFullInfo

--- Создайте обновляемое представление, которое отображает информацию о всех продажах конкретного товара. Например, яблок
CREATE OR ALTER VIEW BeefFullInfo AS
SELECT s.ItemName, s.Price, s.SellingDate, se.[Name] AS 'Seller name', b.[Name] AS 'Buyer name'
FROM Selling AS s JOIN Seller AS se ON s.SellerId = se.Id
				  JOIN Buyer AS b ON s.BuyerId = b.Id
WHERE ItemName LIKE 'Beef%'

--- Создайте представление, отображающее все осуществленные сделки
CREATE VIEW AllSelling AS
SELECT s.ItemName, s.Price, s.SellingDate, se.[Name] AS 'Seller name', b.[Name] AS 'Buyer name'
FROM Selling AS s JOIN Seller AS se ON s.SellerId = se.Id
				  JOIN Buyer AS b ON s.BuyerId = b.Id

--- Создайте представление, отображающее информацию о самом активном продавце. Определяем самого активного продавца по максимальной общей сумме продаж
CREATE VIEW TopSeller AS
SELECT TOP 1 s.[Name] AS 'Seller name', se.Price AS 'Price'
FROM Seller AS s JOIN Selling AS se ON s.Id = se.SellerId
ORDER BY se.Price DESC

--- Создайте представление, отображающее информацию о самом активном покупателе. Определяем самого активного покупателя по максимальной общей сумме покупок.
CREATE VIEW TopBuyer AS
SELECT TOP 1 b.[Name] AS 'Bayer name', se.Price AS 'Price'
FROM Buyer AS b JOIN Selling AS se ON b.Id = se.BuyerId
ORDER BY se.Price DESC




