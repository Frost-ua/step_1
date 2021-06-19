CREATE DATABASE Music_collection_3
GO
USE Music_collection_3
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
DiskId INT NOT NULL FOREIGN KEY REFERENCES Music_disc (Id),
StyleId INT NOT NULL FOREIGN KEY REFERENCES Styles (Id),
ArtistId INT NOT NULL FOREIGN KEY REFERENCES Artists (Id),
Duration INT NOT NULL CHECK (Duration >= 1),
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
('Sonair', 1, 1, 1, '1/11/1996'),('Fixflex', 7, 1, 1, '9/14/2007'),('Fix San', 6, 6, 2, '5/2/2005'),
('My Dog', 4, 7, 3, '11/13/2020'), ('Crazy red dog', 4, 7, 3, '11/13/2020'), ('Asoka', 3, 1, 5, '2/5/2012'),('Zamit', 4, 2, 4, '11/3/2020')
GO

INSERT INTO Songs ([Name], DiskId, StyleId, ArtistId, Duration)
VALUES
('Alphazap', 1, 1, 8, 3),('Viva', 2, 10, 3, 4),('Gembucket', 6, 8, 5, 5),('Job', 5, 7, 4, 3),
('Pannier', 2, 5, 5, 4),('Kanlam', 3, 6, 6, 4),('Pannier', 4, 7, 7, 4),('Alphazap', 6, 2, 8, 4),
('It', 5, 5, 9, 3),('Voltsillam', 2, 5, 1, 6),('Daltfresh', 3, 9, 2, 4),('Flowdesk', 9, 4, 5, 4),
('Greenlam',1, 9, 4, 5),('Bigtax', 6, 4, 1, 7),('Biodex', 3, 2, 10, 4),('Aerified', 8, 9, 1, 3),
('Tres-Zap', 4, 7, 10, 7),('Zamit', 3, 6, 3, 8),('Greenlam', 5, 2, 6, 4),('Tampflex', 1, 5, 8, 5),
('Ronstring', 6, 1, 1, 4),('Cardguard', 8, 3, 5, 4),('Sonair', 7, 7, 8, 4),('Bitchip', 9, 2, 2, 6),('Ronstring', 10, 10, 9, 7),
('Berzerc', 11, 1, 9, 6),('Rap god', 15, 7, 1, 5),('Wermilion', 14, 10, 7, 6),('Californication', 12, 3, 10, 7),('Big city light', 15, 8, 3, 3),
('Crazy', 12, 8, 10, 7),('Mad world', 13, 4, 5, 4),('Never say never', 13, 2, 4, 3),('Sky', 11, 1, 6, 5),('Super hero', 11, 10, 1, 4),
('Jobson', 16, 7, 4, 3),('Moon', 16, 7, 7, 4),('Earth', 16, 7, 10, 7),('The poor man', 16, 7, 8, 4),
('Julia', 17, 7, 4, 3),('Mars', 17, 7, 7, 4),('The Sun', 17, 7, 10, 7),('Gold', 17, 7, 8, 4);
GO
INSERT INTO Songs ([Name], DiskId, StyleId, ArtistId, Duration)
VALUES
('Big city light', 17, 2, 6, 1),('You, sky and fire', 1, 1, 8, 3),('Sky fall', 2, 10, 3, 4),('Flying in the sky', 6, 8, 5, 5),
('Dark sky', 5, 7, 4, 3), ('Big city light', 6, 2, 2, 2), ('Big city light', 17, 2, 6, 1)


																		---   TASKS   ---
									--- Створит наступні користувацькі функції по відношенню до бази даних «Music Collection»:

--- 1. Функція повертає всі диски заданого року. Рік передається як параметр

CREATE OR ALTER FUNCTION GetDiscByYear (@year INT)
RETURNS TABLE
AS
RETURN
(SELECT d.[Name] AS 'Disc name', a.[Name] AS 'Artist', d.Release, s.[Name] AS 'Style', p.[Name] AS 'Publisher'
FROM Music_disc AS d JOIN Artists AS a ON d.ArtistId = a.Id 
					 JOIN Styles AS s ON d.StyleId = s.Id
					 JOIN Publishers AS p ON d.PublisherId = p.Id
					 WHERE DATEPART(YEAR, d.Release) = @year);

SELECT * FROM GetDiscByYear(2007);

--- 2. Функція повертає інформацію про диски з однаковою назвою альбому, але різними виконавцями

CREATE OR ALTER FUNCTION GetSameAlbum ()
RETURNS TABLE
AS
RETURN
SELECT d.[Name] AS 'Disc name', a.[Name] AS 'Artist', d.Release, s.[Name] AS 'Style', p.[Name] AS 'Publisher'
FROM Music_disc AS d JOIN Artists AS a ON d.ArtistId = a.Id 
					 JOIN Styles AS s ON d.StyleId = s.Id
					 JOIN Publishers AS p ON d.PublisherId = p.Id
					 WHERE EXISTS (SELECT md.[Name], ar.[Name] 
								   FROM Music_disc AS md JOIN Artists AS ar ON md.ArtistId = ar.Id 
								   WHERE md.[Name] = d.[Name] AND ar.[Name] <>a.[Name])
					
SELECT * FROM GetSameAlbum()

--- 3. Функція повертає інформацію по всіх піснях в назві яких зустрічається задане слово. Слово передається як параметр

CREATE OR ALTER FUNCTION GetSongsByName (@name VARCHAR(30))
RETURNS @result TABLE (Id int PRIMARY KEY IDENTITY, [Song_name] VARCHAR(30), [Disk_name] VARCHAR(30), [Style_name] VARCHAR(30), [Artist] VARCHAR(30), Duration INT)
AS
BEGIN
	DECLARE @tmp_name VARCHAR(30)
	SET @tmp_name = '%' + @name + '%'
	INSERT INTO @result([Song_name], [Disk_name], [Style_name], [Artist], Duration)
		(SELECT s.[Name], d.[Name], st.[Name], a.[Name], s.Duration
		FROM Songs AS s JOIN Music_disc AS d ON s.DiskId = d.Id
										JOIN Styles AS st ON s.StyleId = st.Id
										JOIN Artists AS a ON s.ArtistId = a.Id
									    WHERE s.[Name] LIKE @tmp_name)
RETURN;
END

SELECT * FROM GetSongsByName('Sky')

--- 4. Функція повертає кількість дисків в стилях 'Hip-hop' та 'Rap'

CREATE OR ALTER FUNCTION GetRapHipHopDisc()
RETURNS @result TABLE (Style VARCHAR(10), Amount_of_album INT) 
AS
BEGIN
		INSERT INTO @result (Style, Amount_of_album)
		(SELECT 'Rap', COUNT(d.Id) AS 'Amount' FROM Music_disc AS d JOIN Styles AS s ON d.StyleId = s.Id WHERE s.[Name] = 'Rap'
		UNION SELECT 'Hip_hop', COUNT(d.Id) AS 'Amount' FROM Music_disc AS d JOIN Styles AS s ON d.StyleId = s.Id WHERE s.[Name] = 'Hip-hop')
RETURN
END

SELECT * FROM GetRapHipHopDisc();

--- 5. Функція повертає інформацію по середній тривалості пісні заданого виконавця. Назва виконавця передається як параметр

CREATE OR ALTER FUNCTION AvgDuration(@artist VARCHAR(30))
RETURNS TABLE
AS
RETURN(
		SELECT a.[Name] AS 'Artist', AVG(s.Duration) AS 'Average duration of song' 
		FROM Songs AS s JOIN Artists AS a ON s.ArtistId = a.Id
		GROUP BY a.[Name]
		HAVING a.[Name] = @artist
)

SELECT * FROM AvgDuration('Moby');

--- 6. Функція повертає інформацію про найдовшу і найкоротшу пісню

CREATE OR ALTER FUNCTION GetLongestShortestSong()
RETURNS @result TABLE (Info VARCHAR(30), Song_name VARCHAR(30), Duration INT, Disk_name VARCHAR(30), Artist VARCHAR(30))
AS
BEGIN
		INSERT INTO @result (Info, Song_name, Duration, Disk_name, Artist)
			
			SELECT 'The longest song', s.[Name], s.Duration, d.[Name], a.[Name]
							FROM Songs AS s JOIN Music_disc AS d ON s.DiskId =d.Id
							JOIN Artists AS a ON s.ArtistId = a.Id
							WHERE s.Duration = (SELECT TOP 1 s.Duration FROM Songs AS s ORDER BY s.Duration DESC)
			
			UNION SELECT 'The shortest song', s.[Name], s.Duration, d.[Name], a.[Name]
							FROM Songs AS s JOIN Music_disc AS d ON s.DiskId =d.Id
							JOIN Artists AS a ON s.ArtistId = a.Id
							WHERE s.Duration = (SELECT TOP 1 s.Duration FROM Songs AS s ORDER BY s.Duration)	
RETURN
END

SELECT * FROM GetLongestShortestSong()

--- 7. Функція повертає інформацію про виконавців, які створили альбоми в двох і більше стилях.

CREATE OR ALTER FUNCTION GetArtistByMoreThenTwoStyle()
RETURNS TABLE
AS
RETURN(
		SELECT a.[Name] AS 'Artist', COUNT(d.Id) AS 'Amount of styles' 
		FROM Artists AS a JOIN Music_disc AS d ON d.ArtistId = a.Id
						  JOIN Styles AS s ON d.StyleId = s.Id
						  GROUP BY a.[Name]
						  HAVING COUNT(d.Id) >= 2
)

SELECT * FROM GetArtistByMoreThenTwoStyle();
