CREATE DATABASE Hospital_2
GO
USE Hospital_2
GO

---===================================   CREATING TABLES   ============================================

CREATE TABLE Departmens
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(100) NOT NULL UNIQUE
);

CREATE TABLE Doctors
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(MAX) NOT NULL,
Surname VARCHAR(MAX) NOT NULL,
Salary MONEY NOT NULL CHECK (Salary > 0), 
Premium MONEY NOT NULL CHECK (Premium >= 0) DEFAULT 0
);

CREATE TABLE Specializations
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(100) NOT NULL UNIQUE,
);

CREATE TABLE DoctorsSpecializations
(
Id INT PRIMARY KEY IDENTITY(1,1),
DoctorId INT NOT NULL FOREIGN KEY REFERENCES Doctors (Id)
);
ALTER TABLE DoctorsSpecializations
ADD SpecializationId INT NOT NULL FOREIGN KEY REFERENCES Specializations (Id);


CREATE TABLE Sponsors
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(100) NOT NULL UNIQUE
);

CREATE TABLE Donations
(
Id INT PRIMARY KEY IDENTITY(1,1),
Amount MONEY NOT NULL CHECK (Amount > 0),
[Date] DATE NOT NULL CHECK ([Date] <= GETDATE()) DEFAULT GETDATE(),
DepartmentId INT NOT NULL FOREIGN KEY REFERENCES Departmens (Id),
SponsorId INT NOT NULL FOREIGN KEY REFERENCES Sponsors (Id)
);

CREATE TABLE Vacations
StartDate DATE NOT NULL,
EndDate DATE NOT NULL,
CHECK (EndDate > StartDate),
DoctorId INT NOT NULL FOREIGN KEY REFERENCES Doctors (Id)
);

CREATE TABLE Wards
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(20) NOT NULL UNIQUE,
DepartmentId INT NOT NULL FOREIGN KEY REFERENCES Departmens (Id) 
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

ALTER TABLE DoctorsExaminations
ADD DiseasesId INT NULL FOREIGN KEY REFERENCES Diseases (Id);
ALTER TABLE DoctorsExaminations
ADD [Date] DATE CHECK ([Date] <= GETDATE()); 

CREATE TABLE Examinations
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] NVARCHAR(100) NOT NULL UNIQUE,
);

CREATE TABLE Diseases
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] NVARCHAR(100) NOT NULL UNIQUE,
Severity INT CHECK (Severity >= 1) DEFAULT 1 NOT NULL
);

---===================================   FILLING TABLES   ============================================
INSERT INTO Departmens ([Name])
VALUES
('Intensive Treatment'), ('Cardiology'), ('Ophthalmology'),
('Traumatology'), ('Neurological'), ('Infectious');
ALTER TABLE Departmens ADD Building  INT NOT NULL CHECK (Building BETWEEN 1 AND 5) DEFAULT 1;
UPDATE Departmens SET Building = 2 WHERE Id = 1;
UPDATE Departmens SET Building = 3 WHERE Id = 2;
UPDATE Departmens SET Building = 1 WHERE Id = 3;
UPDATE Departmens SET Building = 2 WHERE Id = 4;
UPDATE Departmens SET Building = 5 WHERE Id = 5;
UPDATE Departmens SET Building = 4 WHERE Id = 6;

INSERT INTO Doctors ([Name], Surname, Salary, Premium)
VALUES
('Ostap', 'Kopach','15000', '700'), ('Igor', 'Bylen','12000', '500'),
('Olga', 'Polyuhivych','25000', '300'),('Oleksandr', 'Sytnyk','18000', '1000'),
('Oksana', 'Stolyarets','14500', '1500'),('Maria', 'Bratchuk','15900', '750'),
('Helen', 'Williams','25500', '1700');

INSERT INTO Specializations ([Name])
VALUES
('Therapist'), ('Cardiologist'), ('Ophthalmologist'),
('Traumatologist'), ('Neurologist'), ('Infectious disease specialist');

INSERT INTO Sponsors ([Name])
VALUES
('Umbrella Corporation'), ('Pfizer'), ('Johnson & Johnson'),
('Sanofi'), ('Novartis'), ('Amgen');

INSERT INTO DoctorsSpecializations (DoctorId, SpecializationId)
VALUES
(1, (SELECT Id FROM Specializations WHERE [Name] LIKE 'Cardiologist')),
(2, (SELECT Id FROM Specializations WHERE [Name] LIKE 'Neurologist')),
(3, (SELECT Id FROM Specializations WHERE [Name] LIKE 'Therapist')),
(4, (SELECT Id FROM Specializations WHERE [Name] LIKE 'Ophthalmologist')),
(5, (SELECT Id FROM Specializations WHERE [Name] LIKE 'Cardiologist')),
(6, (SELECT Id FROM Specializations WHERE [Name] LIKE 'Traumatologist')),
(7, (SELECT Id FROM Specializations WHERE [Name] LIKE 'Infectious%'));

INSERT INTO Donations (Amount, [Date], DepartmentId, SponsorId)---------------------------
VALUES
(125000, '2020-04-25', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Intensive%'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Umbrella%')),
(215000, '2019-01-27', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Cardiology'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Pfizer')),
(80000, '2016-10-06', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Ophthalmology'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Johnson%')),
(565000, '2020-06-20', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Traumatology'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Sanofi')),
(98000, '2020-09-01', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Neurological'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Novartis')),
(70000, '2019-04-16', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Cardiology'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Pfizer')),
(100000, '2020-11-24', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Infectious'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Amgen')),
(91000, '2019-03-25', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Infectious'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Amgen')),
(300000, '2019-04-06', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Intensive%'), (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Johnson%'));
UPDATE Donations SET SponsorId = (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Umbrella%') 
WHERE DepartmentId = (SELECT Id FROM Departmens WHERE [Name] LIKE 'Intensive%') AND Amount = 300000;
UPDATE Donations SET SponsorId = (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Umbrella%') 
WHERE DepartmentId = (SELECT Id FROM Departmens WHERE [Name] LIKE 'Infectious') AND Amount = 91000;
UPDATE Donations SET [Date] = '2021-03-06' WHERE SponsorId = (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Johnson%') AND Amount = 80000;
UPDATE Donations SET [Date] = '2021-03-30' WHERE SponsorId = (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Pfizer') AND Amount = 215000;

INSERT INTO Vacations (StartDate, EndDate, DoctorId)
VALUES
('2020-04-25', '2020-05-18', (SELECT Id FROM Doctors WHERE Surname LIKE 'Kopach')),
('2019-06-06', '2019-07-05', (SELECT Id FROM Doctors WHERE Surname LIKE 'Williams')),
('2017-11-02', '2017-11-29', (SELECT Id FROM Doctors WHERE Surname LIKE 'Polyuhivych')),
('2018-04-12', '2018-05-03', (SELECT Id FROM Doctors WHERE Surname LIKE 'Bylen')),
('2020-10-05', '2020-11-01', (SELECT Id FROM Doctors WHERE Surname LIKE 'Bratchuk')),
('2021-01-10', '2021-02-02', (SELECT Id FROM Doctors WHERE Surname LIKE 'Bylen')),
('2020-04-14', '2020-04-25', (SELECT Id FROM Doctors WHERE Surname LIKE 'Kopach')),
('2021-02-12', '2021-03-01', (SELECT Id FROM Doctors WHERE Surname LIKE 'Bratchuk')),
('2021-03-08', '2021-03-28', (SELECT Id FROM Doctors WHERE Surname LIKE 'Stolyarets')),
('2020-12-25', '2021-01-25', (SELECT Id FROM Doctors WHERE Surname LIKE 'Sytnyk'));
UPDATE Vacations SET StartDate = '2021-04-10', EndDate = '2021-04-30' WHERE DoctorId = (SELECT Id FROM Doctors WHERE Surname LIKE 'Williams');
UPDATE Vacations SET StartDate = '2021-04-22', EndDate = '2021-05-14' WHERE DoctorId = (SELECT Id FROM Doctors WHERE Surname LIKE 'Sytnyk');

INSERT INTO Wards ([Name], DepartmentId)
VALUES
('A1', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Intensive%')),
('B1', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Cardiology')),
('C1', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Infectious')),
('C2', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Infectious')),
('D1', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Traumatology')),
('A3', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Intensive%')),
('A2', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Intensive%')),
('C3', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Infectious')), 
('F1', (SELECT Id FROM Departmens WHERE [Name] LIKE 'Neurological'));
ALTER TABLE Wards ADD Places  INT NULL CHECK (Places > 0);
UPDATE Wards SET Places = 2 WHERE Id = 1;
UPDATE Wards SET Places = 1 WHERE Id = 2;
UPDATE Wards SET Places = 3 WHERE Id = 3;
UPDATE Wards SET Places = 4 WHERE Id = 4;
UPDATE Wards SET Places = 2 WHERE Id = 5;
UPDATE Wards SET Places = 4 WHERE Id = 6;
UPDATE Wards SET Places = 1 WHERE Id = 7;
UPDATE Wards SET Places = 3 WHERE Id = 8;
UPDATE Wards SET Places = 2 WHERE Id = 9;

INSERT INTO Diseases ([Name], Severity)
VALUES
('Gambling disorder', '5'),('Allergic rhinitis', '1'),('Flu', '4'),('Hepatosis', '1'),('Hemarthrosis', '2'),('Hypoglycemia', '2'),
('Bronchopneumonia', '3'),('Panniculitis', '4'),('Osteosarcoma', '2'),('Ornithodorosis', '2'),('Dromomania', '2'),
('Foreign Accent Syndrome', '1'),('Hypertrichosis', '1'),('Urbachs disease - Vite', '2'),('Electromagnetic hypersensitivity', '3'),
('Allotriophagy', '3'),('Twentieth century disease', '1'),('Chorea', '1'),('Porphyria', '5'),('Gulf War Syndrome', '4'),
('Micropsia', '1'),('Cotard syndrome', '3'),('Capgras syndrome', '2'),('Clinical lycanthropy', '2'),('', '1'),
('Fregoli syndrome', '2'),('Alien hand syndrome', '1');
UPDATE Diseases SET [Name] = 'COVID' WHERE Id = 25;

INSERT INTO Examinations ([Name])
VALUES
('Ultrasound examination'),('Electrocardiogram'),
('CT scan'),('Ultrasound examination of the eye'),
('Echocardiography'),('Joint ultrasound'),('CT scan of the chest cavity'),
('Magnetic resonance imaging'),('Spirography'),('Bacteriological research'),
('Tumor markers'),('Jaw x-ray');

INSERT INTO DoctorsExaminations ([DayOfWeek], StartTime, EndTime, DoctorId, ExaminationsId, WardId, DiseasesId, [Date])
VALUES
('3', '10:00:00', '10:30:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Kopach'), (SELECT Id FROM Examinations WHERE [Name] = 'Electrocardiogram'), (SELECT Id FROM Wards WHERE DepartmentId = 2), 1, '2021-01-14'),
('6', '10:00:00', '10:20:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Kopach'), (SELECT Id FROM Examinations WHERE [Name] = 'Echocardiography'), (SELECT Id FROM Wards WHERE DepartmentId = 2), 15, '2021-04-18'),
('2', '16:00:00', '17:30:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Bylen'), (SELECT Id FROM Examinations WHERE [Name] = 'CT scan'), (SELECT Id FROM Wards WHERE DepartmentId = 5), 27, '2020-11-14'),
('6', '10:45:00', '11:50:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Stolyarets'), (SELECT Id FROM Examinations WHERE [Name] = 'Electrocardiogram'), (SELECT Id FROM Wards WHERE DepartmentId = 2), 19, '2021-04-13'),
('5', '11:20:00', '12:50:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Bratchuk'), (SELECT Id FROM Examinations WHERE [Name] = 'Jaw x-ray'), (SELECT Id FROM Wards WHERE DepartmentId = 4), 25, '2021-03-10'),
('6', '10:40:00', '12:00:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Kopach'), (SELECT Id FROM Examinations WHERE [Name] = 'Electrocardiogram'), (SELECT Id FROM Wards WHERE DepartmentId = 2), 13, '2020-08-09'),
('4', '12:30:00', '15:30:00', (SELECT Id FROM Doctors WHERE Surname LIKE 'Bratchuk'), (SELECT Id FROM Examinations WHERE [Name] = 'Magnetic resonance imaging'), (SELECT Id FROM Wards WHERE DepartmentId = 4), 4, '2020-10-04');

---===================================   REQUESTS   ============================================

--- Вывести полные имена врачей и их специализации.
SELECT CONCAT(d.[Name], +' ' + d.Surname) AS 'Full name', s.[Name] AS 'Specialization'
FROM Doctors AS d, Specializations AS s, DoctorsSpecializations AS ds 
WHERE d.Id = ds.DoctorId AND s.Id = ds.SpecializationId;

--- Вывести фамилии и зарплаты (сумма ставки и надбавки) врачей, которые не находятся в отпуске.
SELECT d.Surname, (d.Salary + d.Premium) AS 'Total salary'
FROM Doctors AS d, Vacations AS v
WHERE GETDATE() NOT BETWEEN v.StartDate AND v.EndDate AND d.Id = v.DoctorId;

--- Вывести названия палат, которые находятся в отделении “Intensive Treatment”.
SELECT [Name] FROM Wards WHERE DepartmentId = (SELECT Id FROM Departmens WHERE [Name] LIKE 'Intensive%');

--- Вывести названия отделений без повторений, которые спонсируются компанией “Umbrella Corporation”.
SELECT DISTINCT dep.[Name] FROM Departmens AS dep, Donations AS don
WHERE dep.Id = don.DepartmentId AND don.SponsorId = (SELECT Id FROM Sponsors WHERE [Name] LIKE 'Umbrella%');

--- Вывести все пожертвования за последний месяц в виде: отделение, спонсор, сумма пожертвования, дата пожертвования.
SELECT dep.[Name] AS 'Department', sp.[Name] AS 'Sponsor', don.Amount, don.[Date]
FROM Departmens AS dep, Sponsors AS sp, Donations AS don
WHERE MONTH(don.[Date]) = MONTH(GETDATE()) - 1 AND YEAR(don.[Date]) = YEAR(GETDATE()) AND don.DepartmentId = dep.Id AND don.SponsorId = sp.Id;

--- Вывести фамилии врачей с указанием отделений, в которых они проводят обследования. Необходимо учитывать обследования, проводимые только в будние дни.
 SELECT doc.Surname AS 'Doctors surname', d.[Name] AS 'Department'
 FROM Doctors AS doc JOIN DoctorsExaminations AS de ON de.DoctorId = doc.Id
					 JOIN Wards AS w ON de.WardId = w.Id
					 JOIN Departmens AS d ON w.DepartmentId = d.Id
					 WHERE de.[DayOfWeek] BETWEEN 1 AND 5

--- Вывести названия палат и корпуса отделений, в которых проводит обследования врач “Ostap Kopach”.
SELECT DISTINCT w.[Name], dep.Building
FROM Wards AS w, Departmens AS dep, DoctorsExaminations AS dex
WHERE dex.DoctorId = (SELECT Id FROM Doctors WHERE Surname = 'Kopach') AND w.Id = dex.WardId AND dep.Building =
(SELECT Building FROM Departmens WHERE [Name] = 'Cardiology');

--- Вывести названия отделений, которые получали пожертвование в размере больше 100000, с указанием их врачей.
SELECT d.[Name] AS 'Department', doc.[Name] + ' ' + doc.Surname AS 'Doctors name'
FROM Departmens AS d JOIN Donations AS don ON don.DepartmentId = d.Id
					 JOIN Wards AS w ON w.DepartmentId = d.Id
					 JOIN DoctorsExaminations AS de ON de.WardId = w.Id
					 JOIN Doctors AS doc ON de.DoctorId = doc.Id
					 WHERE don.Amount > 100000

--- Вывести названия отделений, в которых есть врачи не получающие надбавки.
SELECT DISTINCT d.[Name] AS 'Department'
FROM Departmens AS d JOIN Wards AS w ON w.DepartmentId = d.Id
					 JOIN DoctorsExaminations AS de ON de.WardId = w.Id
					 JOIN Doctors AS doc ON de.DoctorId = doc.Id
					 WHERE doc.Premium = 0;

--- Вывести названия специализаций, которые используются для лечения заболеваний со степенью тяжести выше 3.
SELECT DISTINCT s.[Name] AS 'Specialization'
FROM Specializations AS s JOIN DoctorsSpecializations AS ds ON ds.SpecializationId = s.Id
						  JOIN Doctors AS doc ON ds.DoctorId = doc.Id
						  JOIN DoctorsExaminations AS de ON de.DoctorId = doc.Id
						  JOIN Diseases AS dis ON de.DiseasesId = dis.Id
						  WHERE dis.Severity > 3

--- Вывести названия отделений и заболеваний, обследования по которым они проводили за последние полгода.
SELECT d.[Name] AS 'Departments', dis.[Name] AS 'Diseases'
FROM Departmens AS d JOIN Wards AS w ON w.DepartmentId = d.Id
					 JOIN DoctorsExaminations AS de ON de.WardId = w.Id
					 JOIN Diseases AS dis ON de.DiseasesId = dis.Id
					 WHERE DATEDIFF(MONTH, de.[Date], GETDATE()) <= 6 

--- Вывести названия отделений и палат, в которых проводились обследования по заразительным заболеваниям.
SELECT d.[Name] As 'Department', w.[Name] AS 'Wards'
FROM Departmens AS d JOIN Wards AS w ON w.DepartmentId = d.Id
				     JOIN DoctorsExaminations AS de ON de.WardId = w.Id 
					 JOIN Doctors AS doc ON de.DoctorId = doc.Id
					 JOIN DoctorsSpecializations AS ds ON ds.DoctorId = doc.Id
					 JOIN Specializations AS s ON ds.SpecializationId = s.Id
					 WHERE s.[Name] LIKE 'Infectious%'


