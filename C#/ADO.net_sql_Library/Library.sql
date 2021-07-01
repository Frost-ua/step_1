CREATE DATABASE Library_1
GO
USE  Library_1
GO

--Books (Id, Name, Quantity, YearOfPrinting, Pages, AuthorId, VisitorId )
--Authors (Id, Name, LastName )
--Visitors (Id, FirstName, LastName, Phone, IsDebtor)
--BooksAuthors (Id, BookId, AuthorId)
--BooksVisitors (Id, BookId, VisitorId)

CREATE TABLE Authors
(
Id INT PRIMARY KEY IDENTITY(1,1),
FirstName NVARCHAR(MAX) NOT NULL,
LastName NVARCHAR(MAX) NOT NULL
);
GO

INSERT INTO Authors (FirstName, LastName)            
VALUES
('Goober', 'Dohrmann'),('Kimberli', 'Worgan'),('Sandro', 'McCreath'),('Jordain', 'Kayne'),('Kimbell', 'Leathwood'),
('April', 'De Vries'),('Yalonda', 'Anlay'),('May', 'Bunning'),('Dorris', 'Sutton'),('Ranna', 'Raw');
GO

CREATE TABLE Visitors
(
Id INT PRIMARY KEY IDENTITY(1,1),
FirstName NVARCHAR(MAX) NOT NULL,
LastName NVARCHAR(MAX) NOT NULL,
Phone NVARCHAR(20) NOT NULL,
IsDebtor BIT NOT NULL DEFAULT 0
);
GO

INSERT INTO Visitors (FirstName, LastName, Phone, IsDebtor)            
VALUES
('Alejandrina', 'Itzik', '+7 (981) 226-8034', 1),('Briant', 'Filchakov', '+62 (615) 215-4778', 1),('Tiebold', 'Waltho', '+967 (667) 776-6902', 0),('Kellen', 'Devericks', '+255 (284) 742-6040', 0),
('Ado', 'Swin', '+351 (568) 544-5568', 0),('Bone', 'Bonus', '+378 (259) 130-8283', 1),('Lindy', 'Whooley', '+850 (197) 962-1283', 1),('Etan', 'Bremmell', '+62 (287) 524-8054', 1),
('Darcey', 'Shawel', '+86 (153) 503-7845', 0),('Palmer', 'Nicolson', '+351 (849) 552-2457', 0),('Dallis', 'Gaddie', '+62 (844) 392-5583', 1),('Les', 'Leatherborrow', '+86 (352) 202-9306', 1),
('Raynard', 'Wreiford', '+30 (779) 438-0637', 0),('Rachel', 'Tingly', '+81 (753) 693-2883', 0),('Robinett', 'Earey', '+234 (979) 903-8462', 0),('Diandra', 'Curado', '+1 (203) 522-6625', 0),
('Babb', 'Sindell', '+1 (571) 926-3490', 1),('Eldon', 'Olney', '+7 (736) 658-6728', 0),('Kary', 'Bleasdale', '+357 (989) 448-8946', 0),('Daron', 'Clarkson', '+1 (646) 647-2851', 0),
('Eimile', 'Martellini', '+420 (211) 689-0410', 0),('Damara', 'Geyton', '+967 (564) 697-6046', 0),('Daniela', 'Brennans', '+31 (642) 239-9243', 1),('Lyndell', 'Pie', '+41 (984) 503-8519', 1),
('Maribelle', 'Kornousek', '+86 (219) 512-8371', 0),('Logan', 'MacGahy', '+381 (538) 533-4716', 0),('Jon', 'McAree', '+62 (923) 300-9080', 1),('Brietta', 'Tomasek', '+64 (842) 320-3546', 1),
('Kristoffer', 'Jansen', '+54 (120) 708-8335', 1),('Clair', 'Wilfling', '+62 (482) 212-1176', 1),('Coop', 'Stoffels', '+260 (877) 595-2209', 0),('Shem', 'Haruard', '+1 (801) 152-5269', 1),
('Ernst', 'Rideout', '+374 (649) 167-8723', 0),('Eustacia', 'Ludwig', '+52 (979) 455-9134', 1),('Robbyn', 'Paxton', '+86 (786) 467-5422', 0),('Patrick', 'Pumphreys', '+86 (242) 145-0931', 0),
('Cesar', 'Kroon', '+234 (651) 690-2551', 0),('Haleigh', 'Bell', '+1 (809) 936-8440', 0),('Brooke', 'Gresch', '+385 (450) 402-8011', 1),('Jordana', 'Durnall', '+81 (502) 812-0039', 1),
('Marga', 'Allwell', '+46 (404) 499-5754', 0),('Lyndel', 'Loosely', '+7 (466) 316-9547', 0),('Alejoa', 'Garken', '+1 (703) 449-3552', 0),('Clari', 'Wybron', '+48 (173) 696-8363', 0),
('Hilary', 'Gian', '+86 (741) 962-6571', 1),('Welbie', 'Thumann', '+386 (822) 998-9506', 1),('Eugine', 'Brandsen', '+86 (156) 767-0698', 0),('Janeczka', 'Collison', '+48 (170) 135-0609', 0),
('Enrika', 'Ferris', '+86 (224) 432-6294', 0),('Dorey', 'Boykett', '+358 (551) 883-8494', 0)
GO

CREATE TABLE Books
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] NVARCHAR(MAX) NOT NULL,
Pages INT NOT NULL CHECK (Pages > 0),
PublishDate DATE NOT NULL CHECK (PublishDate <= GETDATE()),
PriceForLoss MONEY NOT NULL,
);
GO

INSERT INTO Books ([Name], Pages, PublishDate, PriceForLoss)            
VALUES
('Flowdesk', 618, '3/21/2011','$80.85'),('Quo Lux', 403, '3/2/2000','$58.54'),('Biodex', 379, '7/9/2005','$81.53'),('In Search of Lost Time', 593, '8/11/1990', '$28'),
('Ulysses', 457, '2/27/2004', '$14'),('Don Quixote', 656, '3/28/2009','$88,1000'),
('One Hundred Years of Solitude', 640, '1/6/2016', '$30,7500'),('The Great Gatsby', 609, '6/8/2000', '$40,0000'),('Moby Dick', 512, '3/8/2014', '$21,9000'),
('War and Peace', 965, '9/12/2011', '$21'),('Hamlet', 878, '9/2/2014', '$32,8000'),('The Odyssey', 411, '4/24/1996', '$91,0000'),
('Madame Bovary', 866, '4/7/2011', '$49'),('The Divine Comedy', 523, '10/10/2018', '$26,7000'),('Lolita', 842, '10/4/2005','$89,9600'),
('The Brothers Karamazov', 572, '10/25/2009','$98,6000'),('Crime and Punishment', 222,  '9/22/2003','$81,0000'),('Wuthering Heights', 189,  '8/14/2015', '$68,8500'),
('The Catcher in the Rye', 344,  '3/20/1992', '$15,4000'),('Pride and Prejudice', 492,  '11/6/1994', '$83,0000'),('The Adventures of Huckleberry Finn', 163,  '6/17/1993', '$43,7000'),
('Alice''s Adventures in Wonderland', 878,  '10/3/2007', '$14,9000'),('The Iliad', 741,  '8/11/2012', '$85,0000'),('To the Lighthouse', 222,  '2/20/2016', '$41,0000'),
('Catch-22', 612,  '3/9/1992', '$19,1000'),('Heart of Darkness', 667,  '11/8/2003', '$93,0000'),('The Sound and the Fury', 360,  '9/13/2004', '$18,0000'),
('Nineteen Eighty Four ', 477,  '9/1/2009', '$46,6000'),('Harry potter and the prisoner of Azkaban', 309,  '1/1/1992', '$81,2000'),
('Harry potter and the half-blood prince', 762,  '1/25/2007', '$70,2000');
GO

CREATE TABLE BooksAuthors
(
Id INT PRIMARY KEY IDENTITY(1,1),
BookId INT NOT NULL FOREIGN KEY REFERENCES Books (Id),
AuthorId INT NOT NULL FOREIGN KEY REFERENCES Authors (Id),
);
GO

INSERT INTO BooksAuthors (BookId, AuthorId)            
VALUES
(8, 3),(30, 4),(10, 2),(2, 3),(5, 2),(5, 4),(7, 6),(23, 9),(2, 5),(9, 7),(4, 3),(15, 7),(29, 7),(23, 9),(30, 6),(22, 2),(19, 4),(28, 7),(30, 4),(5, 1),(5, 2),(18, 8),(17, 2),(9, 9),
(9, 5),(4, 3),(25, 2),(21, 8),(22, 9),(4, 8),(11, 3),(18, 1),(20, 9),(8, 5),(12, 8),(14, 1),(26, 1),(3, 8),(7, 5),(30, 3),(2, 7),(1, 3),(28, 9),(18, 4),(14, 10),(27, 1),(3, 8),(28, 5),
(7, 9),(29, 10)
GO

CREATE TABLE BooksVisitors
(
Id INT PRIMARY KEY IDENTITY(1,1),
BookId INT NOT NULL FOREIGN KEY REFERENCES Books (Id),
VisitorId INT NOT NULL FOREIGN KEY REFERENCES Visitors (Id) DEFAULT 0,
);
GO

INSERT INTO BooksVisitors (BookId, VisitorId)            
VALUES
(2, 46),(2, 40),(17, 32),(3, 14),(29, 37),(6, 28),(25, 12),(6, 40),(19, 46),(25, 12),(28, 17),(20, 43),(13, 23),(27, 49),(11, 43),(9, 21),(11, 26),(17, 18),(27, 29),(1, 49),(9, 14),
(25, 1),(12, 40),(21, 11),(20, 43),(12, 23),(22, 28),(12, 43),(19, 36),(8, 24),(2, 50),(21, 34),(27, 22),(14, 44),(26, 45),(4, 13),(27, 42),(12, 2),(17, 14),(16, 27),(29, 38),(10, 19),
(13, 41),(9, 34),(3, 4),(21, 36),(30, 10),(10, 44),(24, 44),(19, 23)
GO

