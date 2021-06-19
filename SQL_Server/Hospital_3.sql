CREATE DATABASE Hospital_3
GO
USE Hospital_3
GO
---===================================   CREATING TABLES   ============================================
CREATE TABLE Departmens
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(100) NOT NULL UNIQUE,
Building INT NOT NULL CHECK (Building BETWEEN 1 AND 5)
);

CREATE TABLE Doctors
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(MAX) NOT NULL,
Surname VARCHAR(MAX) NOT NULL,
Salary MONEY NOT NULL CHECK (Salary > 0), 
Premium MONEY NOT NULL CHECK (Premium >= 0) DEFAULT 0
);
ALTER TABLE Doctors ADD DepartmentId INT NULL FOREIGN KEY REFERENCES Departmens (Id);

CREATE TABLE Sponsors
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(100) NOT NULL UNIQUE
);

CREATE TABLE Wards
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(20) NOT NULL UNIQUE,
Places INT NOT NULL CHECK (Places >= 1),
DepartmentId INT NOT NULL FOREIGN KEY REFERENCES Departmens (Id) 
);

CREATE TABLE Donations
(
Id INT PRIMARY KEY IDENTITY(1,1),
Amount MONEY NOT NULL CHECK (Amount > 0),
[Date] DATE NOT NULL CHECK ([Date] <= GETDATE()) DEFAULT GETDATE(),
DepartmentId INT NOT NULL FOREIGN KEY REFERENCES Departmens (Id),
SponsorId INT NOT NULL FOREIGN KEY REFERENCES Sponsors (Id)
);

CREATE TABLE Examinations
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] NVARCHAR(100) NOT NULL UNIQUE,
);

CREATE TABLE DoctorsExaminations
(
Id INT PRIMARY KEY IDENTITY(1,1),
[DayOfWeek] INT CHECK ([DayOfWeek] >= 1 AND [DayOfWeek] <= 7) NOT NULL,
StartTime TIME CHECK (StartTime >= '8:00:00' AND StartTime <= '18:00:00') NOT NULL,
EndTime TIME NOT NULL,
CHECK (EndTime > StartTime and EndTime < '18:00:00'),
DoctorId INT NOT NULL FOREIGN KEY REFERENCES Doctors (Id),
ExaminationsId INT NOT NULL FOREIGN KEY REFERENCES Examinations (Id),
WardId INT NOT NULL FOREIGN KEY REFERENCES Wards (Id)
);

---===================================   FILLING TABLES   ============================================

INSERT INTO Departmens ([Name], Building) 
VALUES
('Intensive Treatment', 2), ('Cardiology', 3), ('Ophthalmology', 5),
('Traumatology', 2), ('Neurological', 3), ('Infectious', 5);

INSERT INTO Doctors ([Name], Surname, Salary, Premium)
VALUES
('Ostap', 'Kopach','15000', '700'), ('Igor', 'Bylen','12000', '500'),
('Olga', 'Polyuhivych','25000', '300'),('Oleksandr', 'Sytnyk','18000', '1000'),
('Oksana', 'Stolyarets','14500', '1500'),('Maria', 'Bratchuk','15900', '750'),
('Helen', 'Williams','25500', '1700');
UPDATE Doctors SET DepartmentId = (SELECT Id FROM Departmens WHERE [Name] LIKE '%Cardiology') WHERE Surname = 'Kopach';
UPDATE Doctors SET DepartmentId = (SELECT Id FROM Departmens WHERE [Name] LIKE '%Intensive Treatment') WHERE Surname = 'Bylen';
UPDATE Doctors SET DepartmentId = (SELECT Id FROM Departmens WHERE [Name] LIKE '%Neurological') WHERE Surname = 'Polyuhivych';
UPDATE Doctors SET DepartmentId = (SELECT Id FROM Departmens WHERE [Name] LIKE '%Traumatology') WHERE Surname = 'Sytnyk';
UPDATE Doctors SET DepartmentId = (SELECT Id FROM Departmens WHERE [Name] LIKE '%Cardiology') WHERE Surname = 'Stolyarets';
UPDATE Doctors SET DepartmentId = (SELECT Id FROM Departmens WHERE [Name] LIKE '%Ophthalmology') WHERE Surname = 'Bratchuk';
UPDATE Doctors SET DepartmentId = (SELECT Id FROM Departmens WHERE [Name] LIKE '%Infectious') WHERE Surname = 'Williams';


INSERT INTO Sponsors ([Name])
VALUES
('Umbrella Corporation'), ('Pfizer'), ('Johnson & Johnson'),
('Sanofi'), ('Novartis'), ('Amgen');

INSERT INTO Wards ([Name], Places, DepartmentId)
VALUES
('A1', 2, (SELECT Id FROM Departmens WHERE [Name] LIKE 'Intensive%')),
('B1', 1, (SELECT Id FROM Departmens WHERE [Name] LIKE 'Cardiology')),
('C1', 3, (SELECT Id FROM Departmens WHERE [Name] LIKE 'Infectious')),
('C2', 4, (SELECT Id FROM Departmens WHERE [Name] LIKE 'Infectious')),
('D1', 2, (SELECT Id FROM Departmens WHERE [Name] LIKE 'Traumatology')),
('A3', 4, (SELECT Id FROM Departmens WHERE [Name] LIKE 'Intensive%')),
('A2', 1, (SELECT Id FROM Departmens WHERE [Name] LIKE 'Intensive%')),
('C3', 3, (SELECT Id FROM Departmens WHERE [Name] LIKE 'Infectious')), 
('F1', 2, (SELECT Id FROM Departmens WHERE [Name] LIKE 'Neurological'));

INSERT INTO Donations (Amount, [Date], DepartmentId, SponsorId)---------------------------
VALUES
(125000, '2020-04-25', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Intensive%'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Umbrella%')),
(215000, '2019-01-27', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Cardiology'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Pfizer')),
(80000, '2016-10-06', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Ophthalmology'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Johnson%')),
(565000, '2020-06-20', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Traumatology'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Sanofi')),
(98000, '2020-09-01', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Neurological'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Novartis')),
(70000, '2021-03-30', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Cardiology'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Pfizer')),
(100000, '2020-11-24', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Infectious'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Amgen')),
(91000, '2019-03-25', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Infectious'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Amgen')),
(300000, '2021-03-06', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Intensive%'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Johnson%'));

INSERT INTO Examinations ([Name])
VALUES
('Ultrasound examination'),('Electrocardiogram'),
('CT scan'),('Ultrasound examination of the eye'),
('Echocardiography'),('Joint ultrasound'),('CT scan of the chest cavity'),
('Magnetic resonance imaging'),('Spirography'),('Bacteriological research'),
('Tumor markers'),('Jaw x-ray');

INSERT INTO DoctorsExaminations ([DayOfWeek], StartTime, EndTime, DoctorId, ExaminationsId, WardId)
VALUES
('3', '10:00:00', '10:30:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Kopach'),
(SELECT Id FROM Examinations WHERE [Name] = 'Electrocardiogram'), (SELECT Id FROM Wards WHERE DepartmentId = 2)),
('6', '10:00:00', '10:20:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Kopach'),
(SELECT Id FROM Examinations WHERE [Name] = 'Echocardiography'), (SELECT Id FROM Wards WHERE DepartmentId = 2)),
('2', '16:00:00', '17:30:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Bylen'),
(SELECT Id FROM Examinations WHERE [Name] = 'CT scan'), (SELECT Id FROM Wards WHERE DepartmentId = 5)),
('6', '10:45:00', '11:50:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Stolyarets'),
(SELECT Id FROM Examinations WHERE [Name] = 'Electrocardiogram'), (SELECT Id FROM Wards WHERE DepartmentId = 2)),
('5', '11:20:00', '12:50:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Bratchuk'),
(SELECT Id FROM Examinations WHERE [Name] = 'Jaw x-ray'), (SELECT Id FROM Wards WHERE DepartmentId = 4)),
('6', '10:40:00', '12:00:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Kopach'),
(SELECT Id FROM Examinations WHERE [Name] = 'Electrocardiogram'), (SELECT Id FROM Wards WHERE DepartmentId = 2)),
('4', '12:30:00', '15:30:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Bratchuk'),
(SELECT Id FROM Examinations WHERE [Name] = 'Magnetic resonance imaging'), (SELECT Id FROM Wards WHERE DepartmentId = 4));

---===================================   REQUESTS   ============================================
---⦁	Вывести количество палат, вместимость которых больше 3.
SELECT COUNT(Places) AS 'Wards with places > 2' FROM Wards WHERE Places > 2; 

---⦁	Вывести названия отделений и количество палат в каждом из них.
SELECT d.[Name] AS 'Departments name', COUNT(Places) AS 'Count of wards'
FROM Departmens AS d, Wards AS w
WHERE w.DepartmentId = d.Id
GROUP BY d.[Name];

---⦁	Вывести названия отделений и суммарную надбавку врачей в каждом из них.
SELECT d.[Name] AS 'Departments name', SUM(Premium) AS 'Doctors premium'
FROM Departmens AS d, Doctors AS doc
WHERE doc.DepartmentId = d.Id
GROUP BY d.[Name];

---⦁	Вывести названия отделений, в которых проводят обследования больше 1 врача.
SELECT d.[Name] AS 'Department'
FROM Departmens AS d JOIN Doctors AS doc ON doc.DepartmentId = d.Id
					 JOIN DoctorsExaminations AS de ON de.DoctorId = d.Id
					 GROUP BY d.[Name]
					 HAVING COUNT(de.Id) > 1
					 
---⦁	Вывести количество врачей и их суммарную зарплату (сумма ставки и надбавки).
SELECT COUNT(Id) AS 'Count of doctors', SUM(Salary + Premium) AS 'Sum of doctors salary'
FROM Doctors;

---⦁	Вывести среднюю зарплату (сумма ставки и надбавки) врачей.
SELECT AVG(Salary + Premium) AS 'AVG salary' FROM Doctors;

---⦁	Вывести названия палат с минимальной вместительностью.
SELECT w.[Name] AS 'Wards name'
FROM Wards AS w
GROUP BY w.[Name]
HAVING MIN(Places) = (SELECT TOP 1 Places FROM Wards ORDER BY Places);

---⦁	Вывести названия отделений, что находятся в том же корпусе, что и отделение “Cardiology”.
SELECT d.[Name] AS 'Department'
FROM Departmens AS d
WHERE d.Building = (SELECT d.Building FROM Departmens As d WHERE d.[Name] LIKE 'Cardiology')

---⦁	Вывести названия отделений, что находятся в том же корпусе, что и отделения “Traumatology” и “Ophthalmology”.
SELECT d.[Name] AS 'Department'
FROM Departmens AS d
WHERE d.Building = (SELECT d.Building FROM Departmens As d WHERE d.[Name] LIKE 'Traumatology') OR
d.Building = (SELECT d.Building FROM Departmens As d WHERE d.[Name] LIKE 'Ophthalmology')

---⦁	Вывести название отделения, которое получило меньше всего пожертвований.
SELECT d.[Name]
FROM Departmens AS d JOIN Donations AS don ON don.DepartmentId = d.Id
WHERE don.Amount = (SELECT TOP 1 Amount FROM Donations ORDER BY Amount)

---⦁	Вывести фамилии врачей, ставка которых больше, чем у врача “Oleksandr Sytnyk”.
SELECT doc.Surname As 'Doctors'
FROM Doctors As doc
WHERE (doc.Salary) > (SELECT d.Salary FROM Doctors AS d WHERE d.Surname = 'Sytnyk');

---⦁	Вывести полные имена врачей, зарплаты которых (сумма ставки и надбавки) превышают более чем на 100 зарплату врача “Oleksandr Sytnyk”.
SELECT doc.[Name] + ' ' + doc.Surname As 'Doctors'
FROM Doctors As doc
WHERE (doc.Salary + doc.Premium) - (SELECT (d.Salary + d.Premium) FROM Doctors AS d WHERE d.Surname = 'Sytnyk') > 100;

---⦁	Вывести названия отделений, в которых проводит обследования врач “Helen Williams”.
SELECT DISTINCT d.[Name] AS 'Departments'
FROM Departmens AS d JOIN Doctors AS doc ON doc.DepartmentId = d.Id 
					 JOIN DoctorsExaminations AS de ON de.DoctorId = d.Id
					 JOIN Examinations AS e ON de.ExaminationsId = e.Id
					 WHERE doc.Surname = 'Williams'

---⦁	Вывести названия спонсоров, которые не делали пожертвования отделениям “Cardiology” и “Traumatology”.
SELECT DISTINCT s.[Name] AS 'Sponsors name'
FROM Sponsors AS s JOIN Donations AS d ON d.SponsorId = s.Id
				   JOIN Departmens As de ON d.DepartmentId = de.Id
				   WHERE de.[Name] NOT LIKE 'Cardiology' AND de.[Name] NOT LIKE 'Traumatology' 

---⦁	Вывести фамилии врачей, которые проводят обследования в период с 12:00 до 15:00.
SELECT doc.Surname
FROM Doctors AS doc JOIN DoctorsExaminations AS de ON de.DoctorId = doc.Id
WHERE de.StartTime BETWEEN '12:00:00' AND '15:00:00'








