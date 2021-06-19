CREATE DATABASE BookShop
GO
USE  BookShop
GO
									---   CREATE TABLES + INSERT TABLES   ---

CREATE TABLE Authors
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] NVARCHAR(MAX) NOT NULL,
Surname NVARCHAR(MAX) NOT NULL,
CountryId INT NOT NULL FOREIGN KEY REFERENCES Countries (Id)
);
GO

INSERT INTO Authors ([Name], Surname, CountryId)            
VALUES
('Goober', 'Dohrmann', 3),('Kimberli', 'Worgan', 1),('Sandro', 'McCreath', 5),('Jordain', 'Kayne', 5),('Kimbell', 'Leathwood', 3),
('April', 'De Vries', 5),('Yalonda', 'Anlay', 4),('May', 'Bunning', 2),('Dorris', 'Sutton', 5),('Ranna', 'Raw', 3);
GO

CREATE TABLE Books
(
Id INT PRIMARY KEY IDENTITY (1,1),
[Name] NVARCHAR(MAX) NOT NULL,
Pages INT NOT NULL CHECK (Pages > 0),
Price MONEY NOT NULL CHECK (Price > 0),
PublishDate DATE NOT NULL CHECK (PublishDate <= GETDATE()),
AuthorId INT NOT NULL FOREIGN KEY REFERENCES Authors (Id),
ThemeId INT NOT NULL FOREIGN KEY REFERENCES Themes (Id),
);
GO

INSERT INTO Books ([Name], Pages, Price, PublishDate, AuthorId, ThemeId)
VALUES
('In Search of Lost Time', 593, '$28,0000', '8/11/1990', 11, 1),('Ulysses', 457, '$88,8500', '2/27/2004', 4, 5),('Don Quixote', 656, '$88,1000', '3/28/2009', 5, 2),
('One Hundred Years of Solitude', 640, '$30,7500', '1/6/2016', 11, 2),('The Great Gatsby', 609, '$40,0000', '6/8/2000', 3, 4),('Moby Dick', 512, '$21,9000', '3/8/2014', 1, 1),
('War and Peace', 965, '$137,9900', '9/12/2011', 3, 3),('Hamlet', 878, '$120,8000', '9/2/2014', 4, 2),('The Odyssey', 411, '$91,0000', '4/24/1996', 3, 2),
('Madame Bovary', 866, '$49,6000', '4/7/2011', 4, 2),('The Divine Comedy', 523, '$26,7000', '10/10/2018', 5, 5),('Lolita', 842, '$89,9600', '10/4/2005', 2, 3),
('The Brothers Karamazov', 572, '$98,6000', '10/25/2009', 2, 1),('Crime and Punishment', 222, '$81,0000', '9/22/2003', 11, 4),('Wuthering Heights', 189, '$68,8500', '8/14/2015', 2, 3),
('The Catcher in the Rye', 344, '$15,4000', '3/20/1992', 4, 4),('Pride and Prejudice', 492, '$83,0000', '11/6/1994', 4, 4),('The Adventures of Huckleberry Finn', 163, '$43,7000', '6/17/1993', 5, 3),
('Alice''s Adventures in Wonderland', 878, '$14,9000', '10/3/2007', 3, 3),('The Iliad', 741, '$85,0000', '8/11/2012', 4, 1),('To the Lighthouse', 222, '$41,0000', '2/20/2016', 5, 5),
('Catch-22', 612, '$19,1000', '3/9/1992', 2, 5),('Heart of Darkness', 667, '$93,0000', '11/8/2003', 11, 5),('The Sound and the Fury', 360, '$18,0000', '9/13/2004', 4, 1),
('Nineteen Eighty Four ', 477, '$46,6000', '9/1/2009', 3, 3),('Harry potter and the prisoner of Azkaban', 309, '$81,2000', '1/1/1992', 4, 5),('Harry potter and the half-blood prince', 762, '$70,2000', '1/25/2007', 5, 4);
GO

CREATE TABLE Countries
(
Id INT PRIMARY KEY IDENTITY (1,1),
[Name] NVARCHAR(50) NOT NULL UNIQUE,
);
GO

INSERT INTO Countries ([Name])          
VALUES
('Indonesia'),('United States'),('China'),('Honduras'),('Poland');
GO

CREATE TABLE Sales
(
Id INT PRIMARY KEY IDENTITY (1,1),
Price MONEY NOT NULL CHECK (Price > 0),
Quantity INT NOT NULL CHECK (Quantity > 0),
SaleDate DATE NOT NULL CHECK (SaleDate <= GETDATE()) DEFAULT GETDATE(),
BookId INT NOT NULL FOREIGN KEY REFERENCES Books (Id),
ShopId INT NOT NULL FOREIGN KEY REFERENCES Shops (Id),
);
GO

INSERT INTO Sales (Price, Quantity, SaleDate, BookId, ShopId)-------------------------
VALUES
('$82.22', 7, '7/24/2019', 10, 2),('$86.32', 7, '3/13/2019', 6, 3),('$129.43', 4, '11/18/2015', 20, 4),('$168.11', 1, '11/25/2019', 6, 1),('$88.01', 4, '7/23/2018', 23, 2),
('$176.98', 10, '7/6/2018', 32, 1),('$189.58', 9, '3/4/2016', 19, 1),('$22.51', 8, '10/4/2019', 22, 3),('$128.36', 2, '1/6/2021', 23, 5),('$113.19', 2, '4/5/2019', 7, 2),
('$141.87', 6, '9/23/2017', 9, 3),('$194.68', 9, '9/9/2015', 16, 5),('$128.81', 5, '3/29/2017', 22, 2),('$29.05', 2, '9/26/2016', 6, 1),('$60.47', 8, '1/17/2017', 7, 5),
('$151.07', 5, '12/18/2016', 10, 5),('$34.07', 7, '3/10/2018', 24, 4),('$142.13', 10, '5/30/2019', 32, 4),('$39.86', 6, '6/5/2019', 31, 1),('$171.18', 9, '1/2/2017', 8, 2),
('$125.45', 2, '6/6/2018', 25, 2),('$80.98', 1, '9/27/2019', 15, 5),('$127.83', 3, '10/22/2017', 23, 3),('$26.91', 3, '8/24/2019', 8, 2),('$192.88', 4, '3/21/2019', 14, 2),
('$34.31', 2, '8/6/2020', 16, 3),('$116.22', 6, '5/22/2019', 25, 2),('$119.63', 4, '1/8/2020', 18, 4),('$32.41', 5, '1/1/2017', 22, 5),('$136.89', 6, '12/5/2018', 15, 1),
('$41.25', 8, '2/23/2018', 29, 1),('$46.38', 1, '1/3/2018', 8, 1),('$73.36', 5, '5/30/2016', 26, 4),('$82.60', 9, '10/12/2018', 31, 4),('$184.72', 7, '1/31/2018', 31, 5),
('$110.91', 2, '9/13/2016', 16, 1),('$149.67', 3, '10/24/2015', 7, 2),('$73.52', 1, '10/8/2020', 27, 3),('$90.44', 8, '9/5/2019', 30, 2),('$15.69', 3, '1/13/2019', 13, 2),
('$199.59', 1, '7/28/2017', 24, 4),('$22.70', 2, '7/30/2016', 28, 3),('$178.63', 8, '12/15/2015', 7, 1),('$134.99', 8, '1/20/2017', 18, 5),('$38.16', 1, '9/15/2019', 17, 1),
('$94.33', 7, '6/14/2020', 32, 3),('$32.50', 6, '12/23/2019', 15, 2),('$130.84', 7, '10/13/2019', 29, 3),('$88.05', 6, '1/20/2019', 6, 4),('$178.18', 4, '8/13/2018', 28, 5);
GO

CREATE TABLE Shops
(
Id INT PRIMARY KEY IDENTITY (1,1),
[Name] NVARCHAR(MAX) NOT NULL,
CountryId INT NOT NULL FOREIGN KEY REFERENCES Countries (Id),
);
GO

INSERT INTO Shops ([Name], CountryId)
VALUES
('Great book', 2),('Books of Wonder', 5),('Pioneer Book', 1),('Mother Goose Bookstore', 3),('Second Chance Books', 4),
('The Book Cellar', 2),('The Little Read Book', 5),('Book Barns', 2),('Best of Books', 5),('The Book Haven', 1);
GO

CREATE TABLE Themes
(
Id INT PRIMARY KEY IDENTITY (1,1),
[Name] NVARCHAR(100) NOT NULL UNIQUE,
);
GO

INSERT INTO Themes ([Name])
VALUES
('Mystery'),('Fantasy'),('Horror'),('Science Fiction'),('Romance');
GO

														---   REQUESTS   ---



--- 1. Показать все книги, количество страниц в которых больше 500, но меньше 650.
SELECT [Name] AS 'Book name', Pages FROM Books
WHERE Pages BETWEEN 500 AND 650;

--- 2. Показать все книги, в которых первая буква названия либо «a», либо «d».
SELECT [Name] AS 'Book name' FROM Books
WHERE [Name] LIKE '[a,d]%';

--- 3. Показать все книги жанра «Fantasy», количество про­данных книг более 10 экземпляров.
SELECT b.[Name] AS 'Book name', SUM(s.Quantity) AS 'Number of sold books'
FROM Books AS b JOIN Sales AS s ON b.Id = s.BookId
WHERE ThemeId = (SELECT Id FROM Themes WHERE [Name] = 'Fantasy')
GROUP BY b.[Name]
HAVING SUM(s.Quantity) > 10;

--- 4. Показать все книги, в названии которых есть слово «Potter», но нет слова «Azkaban».
SELECT b.[Name] FROM Books AS b
WHERE b.[Name] LIKE '%Potter%' AND b.[Name] NOT LIKE '%Azkaban%';

--- 5. Показать все книги (название, тематика, полное имя автора в одной ячейке), цена одной страницы которых меньше 5 цента.
SELECT '"' + b.[Name] + '"' + '  ---  ' + t.[Name] + '  ---  ' + a.[Name] + ' ' + a.Surname AS 'Name of book --- Author --- Genre of book'
FROM Books AS b JOIN Sales AS s ON b.Id = s.BookId
				JOIN Themes AS t ON b.ThemeId = t.Id
				JOIN Authors AS a ON b.AuthorId = a.Id
WHERE b.Price / b.Pages < 0.05

--- 6. Показать все книги, название которых состоит из более чем 4-х слов.
SELECT b.[Name] FROM Books AS b
WHERE (LEN(b.[Name]) - LEN(REPLACE(b.[Name], ' ', '')) + 1) > 4;

--- 7.  Показать информацию о продажах в следующем виде:
--- ▷Название книги, но, чтобы оно не содержало букву «А».
--- ▷Тематика, но, чтобы не «Horror».      
--- ▷Автор, но, чтобы не «Sandro McCreath». 
--- ▷Цена, но, чтобы в диапазоне от 50 до 200$.  
--- ▷Количество продаж, но не менее 3 книг.  
--- ▷Название  магазина,  который  продал  книгу,  но  он  не  должен быть в China или Poland. 

SELECT b.[Name] AS 'Book name', 
	   t.[Name] AS 'Genre', 
	   a.[Name] + ' ' + a.Surname AS 'Author', 
	   s.Price AS 'Price', s.Quantity AS 'Quantity', 
	   s.SaleDate, sh.[Name] AS 'Shop name', 
	   c.[Name] AS 'Country of sale'
FROM Sales AS s JOIN Shops AS sh ON s.ShopId = sh.Id
				JOIN Countries AS c ON sh.CountryId = c.Id
				JOIN Books AS b ON s.BookId = b.Id
				JOIN Authors AS a ON b.AuthorId = a.Id
				JOIN Themes AS t ON b.ThemeId = t.Id
WHERE b.[Name] NOT LIKE '%a%' AND
	  t.[Name] NOT LIKE 'Horror' AND
	  a.Surname NOT LIKE 'McCreath' AND
	  s.Price BETWEEN 50 AND 200 AND
	  s.Quantity >= 3 AND
	  c.[Name] NOT LIKE 'China' AND c.[Name] NOT LIKE 'Poland';

--- 8. Показать следующую информацию в два столбца (числа в правом столбце приведены в качестве примера):
--- ▷Количество авторов: 14
--- ▷Количество книг: 47
--- ▷Средняя цена продажи: 85.43 грн.
--- ▷Среднее количество страниц: 650.6.

SELECT 'Number of authors:', COUNT(a.[Name]) 
FROM Authors AS a
UNION SELECT 'Number of books:', COUNT(b.[Name])
FROM Books AS b
UNION SELECT 'Average sale price:', AVG(s.Price)
FROM Sales AS s
UNION SELECT 'Average number of page:', AVG(b.Pages)
FROM Books AS b;

--- 9. Показать  тематики  книг  и  сумму  страниц  всех  книг  по  каждой из них.
SELECT t.[Name] AS 'Genre name', SUM(b.Pages) AS 'Amount pages of books'
FROM Themes AS t JOIN Books AS b ON t.Id = b.ThemeId
GROUP BY t.[Name];

--- 10.Показать количество всех книг и сумму страниц этих книг по каждому из авторов.
SELECT (a.[Name] + ' ' + a.Surname) AS 'Author', COUNT(b.[Name]) AS 'Amount of books', SUM(b.Pages) AS 'Amount of pages'
FROM Authors AS a JOIN Books AS b ON a.Id = b.AuthorId
GROUP BY (a.[Name] + ' ' + a.Surname);

--- 11.Показать книгу тематики «Fantasy» с наиболь­шим количеством страниц.
SELECT TOP 1 b.[Name], b.Pages
FROM Books AS b
WHERE b.ThemeId = (SELECT Id FROM Themes AS t WHERE t.[Name] = 'Fantasy')
ORDER BY b.Pages DESC

--- 12.Показать среднее количество страниц по каждой тематике, которое не превышает 500.
SELECT t.[Name] AS 'Genre name', AVG(b.Pages) AS 'Average pages of books'
FROM Themes AS t JOIN Books AS b ON t.Id = b.ThemeId
GROUP BY t.[Name]
HAVING AVG(b.Pages) < 500

--- 13.Показать сумму страниц по каждой тематике, учитывая только книги с количеством страниц более 500, и чтобы тематики  были
--- «Fantasy»,  «Science Fiction» и «Mystery».
SELECT t.[Name] AS 'Genre', SUM(b.Pages) AS 'Amount of pages'
FROM Themes AS t JOIN Books AS b ON t.Id = b.ThemeId
WHERE b.Pages > 500 AND t.[Name] LIKE '[Fa,Mys,Sci]%'
GROUP BY t.[Name]

--- 14.Показать информацию о работе магазинов: что, где, кем, когда и в каком количестве было продано.
SELECT sh.[Name] AS 'Shop name', 
       c.[Name] AS 'Country of sale',
	   s.SaleDate,
	   s.Price AS 'Price', 
	   s.Quantity AS 'Quantity', 
	   b.[Name] AS 'Book name', 
	   t.[Name] AS 'Genre', 
	   a.[Name] + ' ' + a.Surname AS 'Author'
FROM Sales AS s JOIN Shops AS sh ON s.ShopId = sh.Id
				JOIN Countries AS c ON sh.CountryId = c.Id
				JOIN Books AS b ON s.BookId = b.Id
				JOIN Authors AS a ON b.AuthorId = a.Id
				JOIN Themes AS t ON b.ThemeId = t.Id
ORDER BY sh.[Name]

--- 15.Показать самый прибыльный магазин.
SELECT TOP 1 sh.[Name] AS 'Shop name', SUM(s.Price) AS 'Amount of sales ($)'
FROM Shops AS sh JOIN Sales AS s ON sh.Id = s.ShopId
GROUP BY sh.[Name]
ORDER BY SUM(s.Price) DESC
