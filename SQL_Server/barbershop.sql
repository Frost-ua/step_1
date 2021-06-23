--Tables:
-- 1 - Barbers (Id, FirstName, LastName, Phone, Gender, Email, BirthDate, HireDate, PositionId) - 10 inserts
-- 2 - Positions (Id, Name) - 3 inserts
-- 3 - Services - (Id, Name, Price, Duration) - 10 inserts
-- 4 - BarberServices (BarberId, ServiceId) - 30 inserts
-- 5 - Schedule - (Id, Date, StartTime, EndTime, BarberId) - 50 inserts
-- 6 - Clients - (Id, FirstName, LastName, Phone, Email) - 20 inserts
-- 7 - Bookings - (Id, ClientId, BarberId, Date, Time, ServiceId) 50 inserts
-- 8 - Feedbacks - (Id, ClientId, BarberId, Text, MarkId) - 30 inserts
-- 9 - Marks - (Id, FeetbackId) - 20 inserts
-- 10 - Archive - (Id, ServiceId, BookingId, Price, FeedbackId) 40 inserts

CREATE DATABASE barbershop
GO
USE barbershop
GO

CREATE TABLE Positions
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(20) NOT NULL UNIQUE
);
GO

INSERT INTO Positions([Name])
VALUES
('Chief barber'),('Senior barber'),('Junior barber')
GO

CREATE TABLE Barbers
(
Id INT PRIMARY KEY IDENTITY(1,1),
FirstName VARCHAR(30) NOT NULL,
LastName VARCHAR(30) NOT NULL,
Phone VARCHAR(20) NOT NULL,
Gender VARCHAR(10) NOT NULL,
Email VARCHAR(MAX) NOT NULL,
BirthDate DATE NOT NULL CHECK (DATEDIFF(YEAR, BirthDate, GETDATE()) >= 14),
HireDate DATE NOT NULL CHECK (HireDate <= GETDATE()),
PositionId INT NOT NULL FOREIGN KEY REFERENCES Positions (Id)
);
GO

INSERT INTO Barbers(FirstName, LastName, Phone, Gender, Email, BirthDate, HireDate, PositionId)
VALUES
('Elinor', 'Evemy', '178-146-2116', 'Female', 'eevemy0@google.com', '4/14/1996', '5/30/2019', 3),
('Clemmie', 'Brewse', '391-404-3886', 'Female', 'cbrewse1@live.com', '12/6/2004', '3/12/2018', 2),
('Billi', 'O''Callaghan', '827-891-1701', 'Female', 'bocallaghan2@themeforest.net', '6/25/2004', '11/2/2018', 2),
('Mirabella', 'Hidderley', '458-279-1392', 'Male', 'mhidderley3@latimes.com', '6/5/1990', '6/28/2018', 3),
('Ivette', 'Stewart', '423-922-7244', 'Female', 'istewart4@shutterfly.com', '10/22/1982', '3/19/2016', 2),
('Wyn', 'Moorman', '391-932-5537', 'Male', 'wmoorman5@bluehost.com', '6/13/2004', '5/31/2016', 2),
('Allison', 'Firminger', '895-295-3242', 'Female', 'afirminger6@salon.com', '5/17/2002', '6/26/2018', 3),
('Rodie', 'Affuso', '462-776-4917', 'Female', 'raffuso7@github.com', '11/29/1985', '9/4/2017', 2),
('Chic', 'Bruford', '267-307-3795', 'Male', 'cbruford8@meetup.com', '5/11/2006', '8/8/2016', 1),
('Benjamin', 'Martensen', '696-713-9598', 'Male', 'bmartensen9@ameblo.jp', '12/1/1990', '4/15/2020', 3)
GO

CREATE TABLE [Services]
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(MAX) NOT NULL,
Price MONEY NOT NULL CHECK (Price > 0),
Duration INT NOT NULL CHECK (Duration > 0)
);
GO

INSERT INTO [Services]([Name], Price, Duration)
VALUES
('Haircut', 250, 60),('Kid Cut', 200, 30),('Clipper Cut', 300, 75),('Skin Fade', 1000, 120),('Skin Fade Sides', 500, 60),
('Hot Towel Head Shave', 550, 120),('Hot Towel Face Shave', 350, 60),('Beard Trim', 320, 45),('Beard Styling', 200, 30),('Shoe Shine', 150, 30)
GO

CREATE TABLE BarberServices
(
Id INT PRIMARY KEY IDENTITY(1,1),
BarberId INT NOT NULL FOREIGN KEY REFERENCES Barbers (Id),
ServiceId INT NOT NULL FOREIGN KEY REFERENCES [Services] (Id)
);
GO

INSERT INTO BarberServices (BarberId, ServiceId)
VALUES
(3, 2),(1, 3),(10, 10),(3, 2),(5, 6),(4, 8),(10, 5),(4, 10),(5, 5),(5, 3),(1, 8),(7, 3),(2, 10),(2, 6),(1, 4),
(7, 4),(3, 10),(8, 1),(5, 7),(7, 10),(3, 4),(4, 4),(5, 10),(8, 5),(7, 1),(6, 7),(9, 4),(2, 5),(9, 8),(7, 1)
GO

CREATE TABLE Schedule																	--- Barbershop works from 10 am to 8 pm
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Date] DATE NOT NULL CHECK ([Date] >= GETDATE()),
StartTime TIME CHECK (StartTime >= '10:00:00' AND StartTime <= '19:30:00') NOT NULL,
EndTime TIME  NOT NULL,
CHECK (EndTime > StartTime AND EndTime <= '20:00:00'),
BarberId INT NOT NULL FOREIGN KEY REFERENCES Barbers (Id)
);
GO

INSERT INTO Schedule ([Date], StartTime, EndTime, BarberId)
VALUES
('6/28/2021', '14:00', '18:00', 2),('8/16/2021', '12:00', '20:00', 9),('8/8/2021', '13:00', '19:00', 10),('7/28/2021', '10:00', '16:00', 3),('7/6/2021', '14:30', '17:00', 7),('6/28/2021', '10:20', '17:30', 7),
('7/8/2021', '11:20', '16:45', 9),('8/18/2021', '14:30', '20:00', 5),('6/28/2021', '15:00', '19:30', 9),('6/30/2021', '16:00', '20:00', 3),('7/29/2021', '10:12', '19:40', 6),('8/14/2021', '12:00', '18:20', 9),
('8/17/2021', '16:00', '20:00', 2),('7/8/2021', '12:30', '19:30', 6),('8/25/2021', '15:00', '19:00', 2),('7/15/2021', '10:00', '19:00', 1),('8/5/2021', '11:00', '17:00', 4),('7/16/2021', '10:00', '16:30', 10),
('8/13/2021', '11:10', '19:20', 6),('8/22/2021', '10:40', '17:00', 6),('7/13/2021', '11:00', '18:50', 3),('8/11/2021', '11:30', '18:30', 9),('7/1/2021', '12:00', '17:00', 8),('8/3/2021', '10:00', '17:00', 5),
('7/17/2021', '11:00', '17:30', 4),('6/30/2021', '11:00', '18:00', 7),('7/4/2021', '10:30', '17:00', 5),('8/20/2021', '11:00', '19:40', 8),('8/5/2021', '12:00', '18:40', 5),('7/27/2021', '10:05', '17:05', 7),
('8/3/2021', '11:00', '19:00', 5),('7/15/2021', '11:40', '20:00', 3),('7/22/2021', '10:30', '19:30', 6),('7/30/2021', '12:00', '16:00', 1),('8/13/2021', '13:00', '16:00', 5),('7/24/2021', '14:00', '18:00', 3),
('7/28/2021', '14:00', '20:00', 4),('7/13/2021', '11:15', '16:15', 4),('7/16/2021', '11:30', '19:30', 4),('8/8/2021', '12:0', '20:00', 2),('7/23/2021', '10:30', '17:30', 1),('8/19/2021', '11:20', '19:45', 7),
('8/18/2021', '11:20', '18:20', 4),('7/6/2021', '11:20', '19:40', 5),('8/21/2021', '10:20', '18:40', 8),('7/22/2021', '11:20', '18:20', 6),('7/8/2021', '11:00', '19:00', 2),('6/28/2021', '11:00', '20:00', 9),
('8/19/2021', '11:30', '19:30', 6),('7/28/2021', '11:00', '19:55', 3)
GO

CREATE TABLE Clients
(
Id INT PRIMARY KEY IDENTITY(1,1),
FirstName VARCHAR(30) NOT NULL,
LastName VARCHAR(30) NOT NULL,
Email VARCHAR(MAX) NOT NULL,
Phone VARCHAR(20) NOT NULL
);
GO

INSERT INTO Clients (FirstName, LastName, Email, Phone)
VALUES
('Renard', 'Kuhn', 'rkrzyzaniak5@de.vu', '210-921-1257'),('Chanda', 'Wolfit', 'chazeman6@engadget.com', '510-238-3132'),('Boone', 'Skeats', 'bdocherty7@livejournal.com', '650-112-6148'),
('Thomasin', 'Jesson', 'tkiehnlt8@linkedin.com', '692-509-8135'),('Matty', 'Duggon', 'mdyke9@purevolume.com', '785-493-4891'),('Diane', 'Andrusyak', 'draviliousa@istockphoto.com', '380-852-1794'),
('Lelah', 'Arnaez', 'llidellb@sourceforge.net', '855-906-2406'),('Nikkie', 'Hyam', 'nmannionc@un.org', '692-790-9077'),('Goldarina', 'Pigot', 'geamd@youku.com', '842-325-8141'),
('Rafe', 'Youings', 'rcandline@stanford.edu', '413-596-2736'),('Linell', 'Eaken', 'lmacnultyf@paypal.com', '947-994-2577'),('Grata', 'Fricke', 'gbrimsg@nytimes.com', '118-851-3496'),
('Shaughn', 'Curgenuer', 'slangdonh@seattletimes.com', '888-592-7784'),('Lisha', 'Parfrey', 'ljillissi@samsung.com', '596-887-3423'),('Gail', 'Hugues', 'gbartrumj@so-net.ne.jp', '172-941-9434'),
('Ham', 'Reader', 'hbenchk@businessweek.com', '342-930-8585'),('Baron', 'Dudgeon', 'bwhewayl@pbs.org', '597-969-0154'),('Ewell', 'Annon', 'ebardm@usatoday.com', '974-114-1597'),
('Maury', 'Works', 'msitlingtonn@ftc.gov', '749-963-5025'),('Ilise', 'Kilmurray', 'itanfieldo@sohu.com', '190-227-1181'),('Lek', 'Boram', 'llindstromp@addthis.com', '268-577-7911'),
('Vidovic', 'Frier', 'vhaineyq@nba.com', '350-230-6282'),('Avril', 'Bercher', 'amelbournr@oakley.com', '184-606-5514'),('Jess', 'Hartegan', 'jseniors@google.com.br', '617-378-3380'),
('Avril', 'Bercher', 'amaergbournr@oakley.com', '184-606-5514'),('Jess', 'Hartegan', 'jsergors@google.com.br', '617-378-3380'),('Lucienne', 'Gerard', 'lsrreggrlast@artisteer.com', '606-888-8176')
GO

CREATE TABLE Bookings
(
Id INT PRIMARY KEY IDENTITY(1,1),
ClientId INT NOT NULL FOREIGN KEY REFERENCES Clients (Id),
BarberId INT NOT NULL FOREIGN KEY REFERENCES Barbers (Id),
ServiceId INT NOT NULL FOREIGN KEY REFERENCES [Services] (Id),
[Date] DATE NOT NULL CHECK ([Date] >= GETDATE()),
[Time] TIME NOT NULL CHECK ([Time] >= '10:00:00' AND [Time] <= '19:30:00')
);
GO

INSERT INTO Bookings(ClientId, BarberId, ServiceId, [Date], [Time])
VALUES
(1, 2, 5, '7/5/2021', '10:50'),(27, 8, 5, '6/24/2021', '14:40'),(23, 10, 5, '6/27/2021', '16:10'),(13, 2, 4, '6/25/2021', '16:10'),(27, 1, 2, '7/18/2021', '12:00'),(20, 8, 9, '7/3/2021', '16:00'),
(19, 4, 10, '7/14/2021', '15:10'),(22, 8, 3, '7/1/2021', '14:40'),(20, 8, 9, '7/7/2021', '13:30'),(25, 4, 9, '7/6/2021', '18:30'),(4, 7, 8, '7/15/2021', '16:20'),(12, 1, 2, '7/15/2021', '10:30'),
(20, 9, 5, '7/2/2021', '15:30'),(17, 1, 10, '6/25/2021', '11:10'),(9, 6, 7, '6/27/2021', '14:35'),(2, 5, 4, '7/12/2021', '14:00'),(4, 2, 8, '6/25/2021', '11:20'),(11, 1, 7, '7/8/2021', '16:10'),
(2, 1, 8, '6/26/2021', '11:00'),(1, 3, 4, '6/26/2021', '12:40'),(4, 7, 7, '7/1/2021', '18:30'),(4, 8, 8, '7/16/2021', '15:05'),(10, 10, 4, '7/13/2021', '11:30'),(5, 1, 3, '6/26/2021', '18:40'),
(12, 2, 4, '6/26/2021', '11:40'),(7, 3, 1, '7/1/2021', '15:50'),(8, 4, 5, '7/4/2021', '16:20'),(7, 2, 6, '6/27/2021', '11:50'),(10, 3, 4, '7/13/2021', '11:50'),(5, 3, 7, '7/4/2021', '14:20'),
(1, 8, 3, '6/28/2021', '15:10'),(4, 1, 4, '7/12/2021', '10:50'),(12, 9, 6, '7/2/2021', '14:10'),(27, 5, 10, '6/26/2021', '11:50'),(26, 7, 5, '7/13/2021', '16:20'),(23, 8, 9, '6/29/2021', '12:30'),
(8, 8, 9, '7/2/2021', '15:40'),(4, 4, 2, '7/10/2021', '17:05'),(8, 1, 5, '6/30/2021', '16:50'),(8, 5, 3, '6/24/2021', '14:15'),(20, 5, 6, '6/28/2021', '13:20'),(6, 6, 2, '7/14/2021', '17:20'),
(11, 2, 2, '7/14/2021', '15:40'),(22, 4, 4, '6/25/2021', '12:00'),(24, 3, 7, '7/12/2021', '16:30'),(2, 10, 9, '6/29/2021', '11:15'),(27, 7, 9, '6/28/2021', '16:45'),(1, 7, 5, '7/15/2021', '11:25'),
(11, 2, 7, '6/25/2021', '15:25'),(13, 1, 9, '7/16/2021', '10:15')
GO

CREATE TABLE Marks
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(15) NOT NULL
);
GO

INSERT INTO Marks([Name])
VALUES
('Very bad'), ('Bad'), ('Normal'), ('Good'), ('Great')
GO

CREATE TABLE Feedbacks
(
Id INT PRIMARY KEY IDENTITY(1,1),
ClientId INT NOT NULL FOREIGN KEY REFERENCES Clients (Id),
BarberId INT NOT NULL FOREIGN KEY REFERENCES Barbers (Id),
[Text] VARCHAR(MAX) DEFAULT '',
MarkId INT NOT NULL FOREIGN KEY REFERENCES Marks (Id)
);
GO

INSERT INTO Feedbacks(ClientId, BarberId, MarkId)
VALUES
(17, 8, 2),(1, 3, 4),(12, 6, 4),(6, 1, 5),(17, 2, 1),(11, 1, 5),(20, 9, 3),(21, 5, 2),(24, 8, 3),(16, 1, 2),(15, 10, 4),(7, 10, 3),(27, 4, 4),(14, 6, 3),(22, 6, 1),(10, 6, 5),(15, 3, 2),(19, 5, 1),
(25, 2, 1),(23, 2, 4),(23, 6, 5),(18, 5, 4),(16, 5, 2),(2, 1, 3),(11, 10, 2),(15, 4, 4),(16, 2, 5),(20, 8, 5),(1, 8, 2),(14, 6, 4),(21, 7, 1),(23, 10, 3),(6, 4, 5),(2, 8, 2),(23, 5, 1),(8, 1, 2),
(14, 3, 4),(26, 9, 2),(1, 8, 4),(15, 7, 3),(18, 3, 4),(21, 1, 3),(5, 7, 3),(10, 2, 5),(10, 3, 1),(26, 10, 5),(15, 2, 1),(3, 2, 4),(24, 1, 5),(7, 5, 5)
GO

CREATE TABLE Archive
(
Id INT PRIMARY KEY IDENTITY(1,1),
ServiceId INT NOT NULL FOREIGN KEY REFERENCES [Services] (Id),
BookingId INT NOT NULL FOREIGN KEY REFERENCES Bookings (Id),
Price MONEY NOT NULL CHECK (Price > 0),
FeedbackId INT NOT NULL FOREIGN KEY REFERENCES Feedbacks (Id)
);
GO

INSERT INTO Archive(ServiceId, BookingId, Price, FeedbackId)
VALUES
(2, 39, 940, 15),(6, 27, 1040, 14),(2, 29, 450, 40),(7, 45, 1230, 30),(7, 42, 1000, 3),(7, 13, 1090, 30),(2, 24, 1350, 47),(9, 17, 550, 33),(3, 25, 650, 15),(6, 15, 1090, 26),(10, 9, 1350, 5),(6, 41, 780, 33),
(6, 3, 510, 27),(8, 47, 1050, 18),(4, 42, 1130, 38),(9, 34, 700, 22),(9, 25, 1400, 44),(3, 20, 400, 26),(6, 42, 340, 14),(1, 18, 690, 39),(1, 37, 1140, 40),(4, 19, 1000, 9),(2, 31, 250, 33),(3, 29, 350, 3),
(7, 5, 450, 14),(8, 30, 500, 3),(9, 11, 470, 46),(10, 16, 300, 50),(4, 49, 450, 3),(10, 42, 300, 40),(9, 2, 550, 11),(8, 18, 250, 9),(4, 30, 300, 31),(8, 32, 350, 17),(8, 18, 400, 22),(6, 36, 420, 10),
(8, 43, 290, 8),(6, 13, 300, 19),(7, 46, 400, 18),(10, 5, 250, 35),(1, 25, 560, 50),(2, 9, 380, 18),(8, 12, 560, 23),(3, 41, 750, 19),(3, 34, 860, 41),(1, 7, 290, 26),(4, 15, 860, 16),(7, 8, 360, 37),
(4, 16, 420, 29),(6, 45, 300, 10)
GO

---==============================================================================================================================================================================
--- Используя триггеры, пользовательские функции, хранимые процедуры реализуйте следующую функциональность:
--- 1. Вернуть ФИО всех барберов салона
CREATE OR ALTER PROCEDURE sp_ShowAllBarbers
AS
SELECT b.FirstName + ' ' + b.LastName AS 'Barbers' FROM Barbers AS b

EXEC sp_ShowAllBarbers;

--- 2. Вернуть информацию о всех синьор-барберах
CREATE OR ALTER PROCEDURE sp_ShowAllSeniors
AS
SELECT b.FirstName + ' ' + b.LastName AS 'Full name', b.Gender, p.[Name] AS 'Position', b.Email, b.Phone, b.BirthDate, b.HireDate
FROM Barbers AS b JOIN Positions AS p ON b.PositionId = p.Id
WHERE p.[Name] LIKE '%senior%'

EXEC sp_ShowAllSeniors

--- 3. Вернуть информацию о всех барберах, которые могут предоставить услугу традиционного бритья бороды (Beard Trim)
CREATE OR ALTER PROCEDURE sp_ShowBeardTrimBarbers
AS
SELECT DISTINCT b.FirstName + ' ' + b.LastName AS 'Full name', b.Gender, p.[Name] AS 'Position', b.Email, b.Phone, b.BirthDate, b.HireDate, s.[Name] AS 'Service'
FROM Barbers AS b JOIN Positions AS p ON b.PositionId = p.Id
				  JOIN BarberServices AS bs ON bs.BarberId = b.Id
				  JOIN Services AS s ON s.Id = bs.ServiceId
				  WHERE s.[Name] LIKE '%Beard Trim%'

EXEC sp_ShowBeardTrimBarbers

--- 4. Вернуть информацию о всех барберах, которые могут предоставить конкретную услугу. Информация о требуемой услуге предоставляется в качестве параметра
CREATE OR ALTER FUNCTION udf_ShowSpecificService (@name VARCHAR(30))
RETURNS @result TABLE (Id int PRIMARY KEY IDENTITY, FullName VARCHAR(30), Gender VARCHAR(10), Position VARCHAR(30), Email VARCHAR(30), Phone VARCHAR(15), BirthDate DATE, HireDate DATE)
AS
BEGIN
		DECLARE @tmp_name VARCHAR(30)
		SET @tmp_name = '%' + @name + '%'
		INSERT INTO @result (FullName, Gender, Position, Email, Phone, BirthDate, HireDate)
				SELECT DISTINCT b.FirstName + ' ' + b.LastName, b.Gender, p.[Name], b.Email, b.Phone, b.BirthDate, b.HireDate
				FROM Barbers AS b JOIN Positions AS p ON b.PositionId = p.Id
								  JOIN BarberServices AS bs ON bs.BarberId = b.Id
				                  JOIN Services AS s ON s.Id = bs.ServiceId
							      WHERE s.[Name] LIKE @tmp_name
RETURN;
END;

SELECT * FROM udf_ShowSpecificService ('Kid Cut')

--- 5. Вернуть информацию о всех барберах, которые работают свыше указанного количества лет. Количество лет передаётся в качестве параметра
CREATE OR ALTER FUNCTION udf_BarbersByWorkedYears (@years INT)
RETURNS @result TABLE (Id int PRIMARY KEY IDENTITY, FullName VARCHAR(30), Gender VARCHAR(10), Position VARCHAR(30), Email VARCHAR(30), Phone VARCHAR(15), BirthDate DATE, HireDate DATE)
AS
BEGIN
		INSERT INTO @result (FullName, Gender, Position, Email, Phone, BirthDate, HireDate)
				SELECT DISTINCT b.FirstName + ' ' + b.LastName, b.Gender, p.[Name], b.Email, b.Phone, b.BirthDate, b.HireDate
				FROM Barbers AS b JOIN Positions AS p ON b.PositionId = p.Id
								  JOIN BarberServices AS bs ON bs.BarberId = b.Id
				                  JOIN Services AS s ON s.Id = bs.ServiceId
							      WHERE DATEDIFF(YEAR, b.HireDate, GETDATE()) >= @years
RETURN;
END;

SELECT * FROM udf_BarbersByWorkedYears (5)

--- 6. Вернуть количество синьор-барберов и количество джуниор-барберов
CREATE OR ALTER PROCEDURE sp_AmountJuniorsSeniors
AS
	SELECT 'Amount of Senior barbers' AS 'Position', COUNT (b.Id) AS 'Amount'
	FROM Barbers AS b JOIN Positions AS p ON b.PositionId = p.Id 
	GROUP BY p.[Name]
	HAVING p.[Name] LIKE '%Senior%'
	UNION SELECT 'Amount of Junior barbers' AS 'Position', COUNT (b.Id) AS 'Amount'
	FROM Barbers AS b JOIN Positions AS p ON b.PositionId = p.Id 
	GROUP BY p.[Name]
	HAVING p.[Name] LIKE '%Junior%'

EXEC sp_AmountJuniorsSeniors

--- 7. Вернуть информацию о постоянных клиентах. Критерий постоянного клиента: был в салоне заданное количество раз. Количество передаётся в качестве параметра
CREATE OR ALTER FUNCTION udf_GetRegularClients (@count INT)
RETURNS @result TABLE (FirstName VARCHAR(20), LastName VARCHAR(20), Phone VARCHAR(15), Email VARCHAR(30), CountOfVisits INT)
AS
BEGIN
INSERT INTO @result (FirstName, LastName, Phone, Email, CountOfVisits)
		SELECT c.FirstName, c.LastName, c.Phone, c.Email, COUNT(c.Id)
		FROM Clients As c JOIN Bookings As b ON b.ClientId = c.Id
		GROUP BY c.FirstName, c.LastName, c.Phone, c.Email
		HAVING COUNT(c.Id) = @count
RETURN;
END;

SELECT * FROM udf_GetRegularClients (3)

--- 8. Запретить возможность удаления информации о чиф-барбере, если не добавлен второй чиф-барбер
CREATE OR ALTER TRIGGER tg_DenyDeleteChief
ON Barbers
AFTER DELETE
AS
	DECLARE @count_chiefs_in_barbershop INT
	DECLARE @count_chiefs_for_delete INT
	SET @count_chiefs_in_barbershop = (SELECT COUNT(b.Id)
				  FROM Barbers AS b JOIN Positions AS p ON b.PositionId = p.Id
				  WHERE p.[Name] LIKE '%Chief%')
	SET @count_chiefs_for_delete = (SELECT COUNT(d.Id) 
				  FROM deleted AS d JOIN Positions AS p ON d.PositionId = p.Id 
				  WHERE p.[Name] LIKE 'Chief')
	
	IF(@count_chiefs_in_barbershop < 2 AND @count_chiefs_for_delete > 0)
	BEGIN
		PRINT 'Deny to delete Chief barber!'
		ROLLBACK
	END;

--- 9. Запретить добавлять барберов младше 21 года.
CREATE OR ALTER TRIGGER tg_DenyAddYongerThan21
ON Barbers
AFTER INSERT
AS
		SELECT * FROM inserted
		DECLARE @amount_young_barbers INT
		SET @amount_young_barbers = (SELECT COUNT(i.Id) 
									 FROM inserted AS i 
									 WHERE DATEDIFF(YEAR, i.BirthDate, GETDATE()) < 21)
		IF(@amount_young_barbers > 0)
		BEGIN
			PRINT 'Deny to add barber yonger than 21 years!'
			ROLLBACK
		END

INSERT INTO Barbers(FirstName, LastName, Phone, Gender, Email, BirthDate, HireDate, PositionId)
VALUES
('Entony', 'Philips', '128-454-3698', 'Male', 'Phil@google.com', '6/20/1992', '5/25/2021', 3),
('Edward', 'Blade', '458-499-3363', 'Male', 'blade@live.com', '12/6/2006', '3/12/2018', 2)


























