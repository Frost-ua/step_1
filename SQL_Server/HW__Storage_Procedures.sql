CREATE DATABASE Music_collection_2
GO
USE Music_collection_2
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
DiskId INT NOT NULL FOREIGN KEY (DiskId) REFERENCES Music_disc (Id) ON DELETE CASCADE,
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
('Cardify', 9, 5, 6, '7/5/2007'),('Stringtough', 4, 9, 2, '10/8/2020'),('Regrant', 10, 10, 7, '2/22/2021'),
('Asoka', 1, 2, 1, '5/25/2021'),('Zamit', 5, 8, 2, '1/7/2000'),('Zaam-Dox', 8, 5, 2, '10/4/1990'),
('Job', 2, 1, 4, '7/14/2010'),('Wrapsafe', 4, 7, 3, '11/13/2020'),('Temp', 9, 6 , 5, '6/14/2009'),
('Tempsoft', 3, 4, 6, '5/30/1993'),('Domainer', 2, 2, 7, '4/2/2000'),('Bitwolf', 7, 3, 5, '10/10/2014'),
('Sonair', 1, 1, 1, '1/11/1996'),('Fixflex', 7, 1, 1, '9/14/2007'),('Fix San', 6, 6, 2, '5/2/2005');
GO
INSERT INTO Music_disc ([Name], ArtistId, StyleId, PublisherId, Release)
VALUES
  ('My Dog', 4, 7, 3, '11/13/2020'), ('Crazy red dog', 4, 7, 3, '11/13/2020')

INSERT INTO Songs ([Name], DiskId, StyleId, ArtistId, Duration)
VALUES
('Alphazap', 1, 1, 8, 3),('Viva', 2, 10, 3, 4),('Gembucket', 6, 8, 5, 5),('Job', 5, 7, 4, 3),
('Pannier', 2, 5, 5, 4),('Kanlam', 3, 6, 6, 4),('Pannier', 4, 7, 7, 4),('Alphazap', 6, 2, 8, 4),
('It', 5, 5, 9, 3),('Voltsillam', 2, 5, 1, 6),('Daltfresh', 3, 9, 2, 4),('Flowdesk', 9, 4, 5, 4),
('Greenlam',1, 9, 4, 5),('Bigtax', 6, 4, 1, 7),('Biodex', 3, 2, 10, 4),('Aerified', 8, 9, 1, 3),
('Tres-Zap', 4, 7, 10, 7),('Zamit', 3, 6, 3, 8),('Greenlam', 5, 2, 6, 4),('Tampflex', 1, 5, 8, 5),
('Ronstring', 6, 1, 1, 4),('Cardguard', 8, 3, 5, 4),('Sonair', 7, 7, 8, 4),('Bitchip', 9, 2, 2, 6),('Ronstring', 10, 10, 9, 7),
('Berzerc', 11, 1, 9, 6),('Rap god', 15, 7, 1, 5),('Wermilion', 14, 10, 7, 6),('Californication', 12, 3, 10, 7),('Big city light', 15, 8, 3, 3),
('Crazy', 12, 8, 10, 7),('Mad world', 13, 4, 5, 4),('Never say never', 13, 2, 4, 3),('Sky', 11, 1, 6, 5),('Super hero', 11, 10, 1, 4)
GO
INSERT INTO Songs ([Name], DiskId, StyleId, ArtistId, Duration)
VALUES
('Job', 20, 7, 4, 3),('Pannier', 20, 7, 7, 4),('Tres-Zap', 20, 7, 10, 7),('Sonair', 20, 7, 8, 4),
('Job', 21, 7, 4, 3),('Pannier', 21, 7, 7, 4),('Tres-Zap', 21, 7, 10, 7),('Sonair', 21, 7, 8, 4)		


																	---   TASKS   ---
						--- ������� �������� ��������� ��������� �� ��������� �� ���� ����� �������� ���������: ---

--- 1. ��������� ������ ����� ���������� �� �������� ������
CREATE OR ALTER PROCEDURE DiscFullInfo
AS
SELECT d.[Name] AS 'Disc name', a.[Name] AS 'Artist', d.Release, s.[Name] AS 'Style', p.[Name] AS 'Publisher'
FROM Music_disc AS d JOIN Artists AS a ON d.ArtistId = a.Id 
					 JOIN Styles AS s ON d.StyleId = s.Id
					 JOIN Publishers AS p ON d.PublisherId = p.Id;

EXEC DiscFullInfo;

--- 2. ��������� ������ ����� ���������� �� ��� �������� ������ ����������� �����������. ����� ����������� ���������� �� ��������
CREATE OR ALTER PROCEDURE DiscFullInfoByPublisher
@publisher VARCHAR(30)
AS
SELECT d.[Name] AS 'Disc name', a.[Name] AS 'Artist', d.Release, s.[Name] AS 'Style', p.[Name] AS 'Publisher'
FROM Music_disc AS d JOIN Artists AS a ON d.ArtistId = a.Id 
					 JOIN Styles AS s ON d.StyleId = s.Id
					 JOIN Publishers AS p ON d.PublisherId = p.Id
					 WHERE p.[Name] = @publisher

EXEC DiscFullInfoByPublisher 'Atlas Music'

--- 3. ��������� ������ ����� ������ ����������� �����. ������������ ����� ����������� �� ������� ����� � ��������
CREATE OR ALTER PROCEDURE TopStyle
AS
SELECT s.[Name], COUNT(s.Id) AS 'Count'
FROM Styles AS s JOIN Music_disc AS d ON d.StyleId = s.Id
GROUP BY s.[Name]
HAVING COUNT(s.Id) = (SELECT TOP 1 COUNT(Id) AS 'Count'
					  FROM Music_disc
					  GROUP BY StyleId
					  ORDER BY 'Count' DESC)

EXEC TopStyle;

--- 4. ��������� �������� ���������� ��� ���� ����������� ����� � ��������� ������� �����. ����� ����� ���������� �� ��������, ���� �������� ����� all, ����� ��� �� ���� �������
CREATE OR ALTER PROCEDURE DiscInfo
@style_name VARCHAR(25)
AS
IF(@style_name != 'All')
BEGIN
		SELECT d.[Name] AS 'Disc name', st.[Name] AS 'Style', a.[Name] AS 'Artist', p.[Name] AS 'Publisher', COUNT(s.Id) AS 'Amount of songs'
		FROM Music_disc AS d JOIN Songs AS s ON s.DiskId = d.Id 
					 JOIN Styles AS st ON d.StyleId = st.Id
					 JOIN Artists AS a ON d.ArtistId = a.Id
					 JOIN Publishers AS p ON d.PublisherId = p.Id
		GROUP BY d.[Name], st.[Name], a.[Name], p.[Name]
		HAVING st.[Name] = @style_name AND COUNT(s.Id) = (SELECT TOP 1 COUNT(s.Id) AS 'Count'
												  FROM
												  Music_disc AS d JOIN Songs AS s ON s.DiskId = d.Id 
												  JOIN Styles AS st ON d.StyleId = st.Id
												  JOIN Artists AS a ON d.ArtistId = a.Id
												  JOIN Publishers AS p ON d.PublisherId = p.Id
												  GROUP BY d.[Name], st.[Name]
												  HAVING st.[Name] = @style_name
												  ORDER BY 'Count' DESC)
END
ELSE
		SELECT d.[Name] AS 'Disc name', st.[Name] AS 'Style', a.[Name] AS 'Artist', p.[Name] AS 'Publisher', COUNT(s.Id) AS 'Amount of songs'
		FROM Music_disc AS d JOIN Songs AS s ON s.DiskId = d.Id 
					 JOIN Styles AS st ON d.StyleId = st.Id
					 JOIN Artists AS a ON d.ArtistId = a.Id
					 JOIN Publishers AS p ON d.PublisherId = p.Id
		GROUP BY d.[Name], st.[Name], a.[Name], p.[Name]

EXEC DiscInfo 'all'

--- 5. ��������� ������� �� ����� �������� �����. ����� ����� ���������� �� ��������. ��������� ������� ������� ��������� �����.
CREATE OR ALTER PROCEDURE DeleteDiskByStyle
@style VARCHAR(30),
@result INT OUTPUT
AS
DECLARE @style_id INT
SET @style_id = (SELECT s.Id FROM Styles AS s WHERE s.[Name] = @style)
SELECT @result = COUNT(d.Id) FROM Music_disc AS d WHERE d.StyleId = (SELECT s.Id FROM Styles AS s WHERE s.[Name] = @style)
DELETE FROM Music_disc WHERE StyleId = @style_id

DECLARE @res INT
EXEC DeleteDiskByStyle 'R&B', @res OUTPUT
SELECT @res AS 'Amount of deleted disks'

--- 6. ��������� �������� ���������� �� ������ �������� ������� � ������ ���������. ������� � �������� ������������ �� ����� �������
CREATE OR ALTER PROCEDURE ShowOldYoungDisc
AS
SELECT 'The oldest album', d.[Name] AS 'Disc name', a.[Name] AS 'Artist', d.Release, s.[Name] AS 'Style', p.[Name] AS 'Publisher'
FROM Music_disc AS d JOIN Artists AS a ON d.ArtistId = a.Id 
					 JOIN Styles AS s ON d.StyleId = s.Id
					 JOIN Publishers AS p ON d.PublisherId = p.Id
					 WHERE d.Release = (SELECT MIN(d.Release) FROM Music_disc AS d)
UNION SELECT 'The youngest album', d.[Name] AS 'Disc name', a.[Name] AS 'Artist', d.Release, s.[Name] AS 'Style', p.[Name] AS 'Publisher'
FROM Music_disc AS d JOIN Artists AS a ON d.ArtistId = a.Id 
					 JOIN Styles AS s ON d.StyleId = s.Id
					 JOIN Publishers AS p ON d.PublisherId = p.Id
					 WHERE d.Release = (SELECT MAX(d.Release) FROM Music_disc AS d)

EXEC ShowOldYoungDisc

--- 7. ��������� ������� �� ����� � ���� ���� � ������ �����. ����� ���������� �� ��������. ��������� ������� ������� ��������� �����.

CREATE OR ALTER PROCEDURE DeleteDiskByName
@name VARCHAR(30),
@result INT OUTPUT
AS
DECLARE @tmp_name VARCHAR(30)

SET @tmp_name = '%' + @name + '%'
SELECT @result = COUNT(d.Id) FROM Music_disc AS d WHERE d.[Name] LIKE @tmp_name
DELETE FROM Music_disc WHERE [Name] LIKE @tmp_name


DECLARE @res INT
EXEC DeleteDiskByName 'Dog', @res OUTPUT
SELECT @res AS 'Amount of deleted disks'
