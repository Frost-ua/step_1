CREATE DATABASE Hospital_4
GO
USE Hospital_4
GO

---===================================   CREATING AND FILLING TABLES   ============================================

CREATE TABLE Departments
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(100) NOT NULL UNIQUE,
Building INT NOT NULL CHECK (Building BETWEEN 1 AND 5),
Financing MONEY NOT NULL CHECK (Financing >= 0) DEFAULT 0
);
GO
INSERT INTO Departments ([Name], Building, Financing) 
VALUES
('Intensive Treatment', 2, 105000), ('Cardiology', 3, 254000), ('Ophthalmology', 1, 178500),
('Traumatology', 2, 85000), ('Neurological', 5, 256000), ('Infectious', 5, 98500),
('Diagnostic radiology', 1, 56200),('Internal medicine', 5, 41260),('Pediatrics', 4, 129000),
('Physical medicine and rehabilitation', 3, 165000),('Medical genetics', 3, 48500),('Dermatology', 3, 78690),
('Nuclear medicine', 2, 88000),('Pathology', 1, 56200),('Emergency medicine', 5, 111000);
GO
CREATE TABLE Diseases
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] NVARCHAR(100) NOT NULL UNIQUE
);
GO
INSERT INTO Diseases ([Name])
VALUES
('Gambling disorder'),('Allergic rhinitis'),('Flu'),('Hepatosis'),('Hemarthrosis'),('Hypoglycemia'),
('Bronchopneumonia'),('Panniculitis'),('Osteosarcoma'),('Ornithodorosis'),('Dromomania'),
('Foreign Accent Syndrome'),('Hypertrichosis'),('Urbachs disease - Vite'),('Electromagnetic hypersensitivity'),
('Allotriophagy'),('Twentieth century disease'),('Chorea'),('Porphyria'),('Gulf War Syndrome'),
('Micropsia'),('Cotard syndrome'),('Capgras syndrome'),('Clinical lycanthropy'),('COVID'),
('Fregoli syndrome'),('Alien hand syndrome');
GO
CREATE TABLE Doctors
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(MAX) NOT NULL,
Surname VARCHAR(MAX) NOT NULL,
Salary MONEY NOT NULL CHECK (Salary > 0)
);
GO
INSERT INTO Doctors ([Name], Surname, Salary)
VALUES
('Ostap', 'Kopach', '$5200'), ('Igor', 'Bylen', '$4700'),('Olga', 'Polyuhivych', '$1250'),('Oleksandr', '$Sytnyk', '$3550'),('Oksana', 'Stolyarets', '$5600'),
('Maria', 'Bratchuk', '$7500'),('Helen', 'Williams', '$1900'),('Bert', 'Borland', '$9365'),('Jobey', 'Dutson', '$5371'),('Idalina', 'Knappen', '$6258'),
('Grannie', 'McDonagh', '$3472'),('Vance', 'Gritskov', '$5927'),('Cecilia', 'O''Hengerty', '$7592'),('Stacie', 'Wadeling', '$5264'),('Madelon', 'Quinsee', '$2122'),
('Felicia', 'Izhaky', '$5017'),('Madeleine', 'Kertess', '$3063'),('Cullie', 'Gilks', '$1782'),('Krystal', 'Bernasek', '$1342'),('Ester', 'Flade', '$5435'),
('Vaughn', 'Waison', '$8171'),('Nerti', 'Innot', '$9514'),('Ethelda', 'Cubin', '$8180'),('Faun', 'Burgum', '$5510'),('Leroy', 'Ellicombe', '$2156'),('Loren', 'MacMurray', '$6971'),
('Fran', 'Rogers', '$8129');
GO
CREATE TABLE DoctorsExaminations
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Date] DATE NOT NULL CHECK ([Date] <= GETDATE()) DEFAULT GETDATE(), 
DiseaseId INT NOT NULL FOREIGN KEY REFERENCES Diseases (Id),
DoctorId INT NOT NULL FOREIGN KEY REFERENCES Doctors (Id),
ExaminationsId INT NOT NULL FOREIGN KEY REFERENCES Examinations (Id)
);
GO
INSERT INTO DoctorsExaminations ([Date], DiseaseId, DoctorId, ExaminationsId, WardId)
VALUES
('9/22/2020', 9, 15, 8, 111),('8/5/2020', 22, 11, 6, 108),('1/18/2021', 18, 20, 8, 126),('1/14/2021', 18, 2, 5, 135),('2/27/2021', 19, 25, 17, 134),('5/21/2021', 4, 12, 17, 127),
('7/1/2020', 6, 10, 11, 124),('10/12/2020', 4, 4, 13, 119),('5/12/2021', 6, 19, 12, 126),('11/14/2020', 2, 18, 6, 113),('6/1/2020', 12, 1, 7, 135),('8/13/2020', 5, 7, 4, 132),
('6/13/2020', 6, 11, 19, 132),('3/21/2021', 16, 23, 10, 134),('11/26/2020', 25, 13, 8, 132),('11/14/2020', 20, 21, 5, 106),('4/18/2021', 23, 17, 4, 123),('8/17/2020', 6, 12, 2, 120),
('1/8/2021', 14, 15, 1, 135),('6/1/2020', 5, 5, 13, 127),('2/23/2021', 16, 12, 13, 135),('3/28/2021', 4, 24, 12, 118),('4/29/2021', 14, 12, 8, 114),('3/30/2021', 10, 11, 4, 116),
('1/31/2021', 5, 13, 10, 129),('6/27/2020', 19, 7, 7, 121),('1/3/2021', 17, 18, 5, 128),('1/2/2021', 25, 4, 19, 123),('8/9/2020', 21, 2, 7, 117),('2/15/2021', 19, 3, 11, 132),
('6/30/2020', 5, 23, 9, 135),('11/24/2020', 24, 26, 3, 122),('4/13/2021', 27, 4, 12, 132),('9/23/2020', 22, 19, 14, 110),('2/12/2021', 23, 2, 18, 134),('7/5/2020', 3, 3, 9, 128),
('2/19/2021', 27, 7, 2, 118),('5/4/2021', 18, 22, 2, 113),('8/13/2020', 10, 1, 17, 128),('7/29/2020', 14, 16, 8, 112),('11/9/2020', 11, 24, 8, 108),('3/2/2021', 16, 17, 13, 119),
('9/26/2020', 2, 14, 12, 123),('3/10/2021', 24, 13, 2, 112),('2/4/2021', 11, 21, 18, 127),('10/20/2020', 13, 20, 3, 125),('5/3/2021', 8, 20, 15, 114),('5/22/2021', 12, 12, 3, 112),
('11/11/2020', 22, 8, 9, 127),('12/20/2020', 17, 26, 4, 114),('11/13/2020', 12, 23, 13, 123),('9/7/2020', 3, 10, 9, 130),('5/16/2021', 15, 22, 2, 109),('10/7/2020', 26, 3, 14, 111),
('12/9/2020', 16, 18, 19, 107),('12/9/2020', 5, 15, 4, 123),('8/2/2020', 5, 3, 16, 109),('12/15/2020', 19, 4, 13, 116),('5/14/2021', 5, 4, 5, 131),('7/15/2020', 24, 1, 12, 123),
('12/5/2020', 20, 26, 11, 119),('8/28/2020', 6, 16, 9, 130),('8/11/2020', 2, 5, 8, 128),('8/11/2020', 16, 11, 19, 113),('11/2/2020', 3, 10, 9, 116),('4/2/2021', 21, 20, 16, 125),
('3/29/2021', 21, 17, 6, 128),('6/29/2020', 25, 19, 18, 112),('12/12/2020', 12, 12, 18, 112),('6/13/2020', 2, 6, 2, 114),('2/26/2021', 16, 10, 8, 127),('2/24/2021', 4, 12, 5, 113),
('3/15/2021', 3, 8, 9, 124),('12/18/2020', 7, 4, 8, 116),('1/30/2021', 27, 19, 13, 114),('6/8/2020', 23, 8, 19, 116),('7/4/2020', 9, 21, 7, 127),('7/3/2020', 3, 6, 3, 117),
('1/28/2021', 5, 16, 14, 114),('7/2/2020', 10, 13, 4, 130),('4/29/2021', 1, 13, 15, 107),('10/20/2020', 19, 14, 14, 107),('6/9/2020', 11, 19, 5, 121),('10/5/2020', 10, 15, 11, 134),
('7/30/2020', 14, 8, 13, 109),('5/25/2021', 23, 20, 9, 111),('11/17/2020', 23, 19, 19, 133),('7/28/2020', 8, 1, 13, 119),('6/11/2020', 17, 22, 10, 123),('3/5/2021', 2, 7, 16, 131),
('11/3/2020', 26, 26, 18, 112),('1/22/2021', 16, 14, 11, 124),('10/15/2020', 7, 1, 7, 121),('1/15/2021', 4, 15, 12, 127),('2/13/2021', 17, 19, 18, 120),('10/4/2020', 25, 16, 18, 131),
('4/14/2021', 27, 22, 11, 129),('11/16/2020', 11, 7, 19, 116),('2/13/2021', 6, 3, 19, 112),('8/3/2020', 22, 17, 19, 116);
GO
CREATE TABLE Examinations
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] NVARCHAR(100) NOT NULL UNIQUE,
);
GO
INSERT INTO Examinations ([Name])
VALUES
('Ultrasound examination'),('Electrocardiogram'),('CT scan'),('Ultrasound examination of the eye'),('Echocardiography'),('Joint ultrasound'),('CT scan of the chest cavity'),
('Magnetic resonance imaging'),('Spirography'),('Bacteriological research'),('Tumor markers'),('Jaw x-ray'), ('Protein-bound iodine test'),('Brain scanning'),
('Toxicological examination'),('Angiography'),('Thyroid function test'),('Liver function test'),('Gastric fluid analysis');
GO
CREATE TABLE Interns
(
Id INT PRIMARY KEY IDENTITY(1,1),
DoctorId INT NOT NULL FOREIGN KEY REFERENCES Doctors (Id)
)
GO
INSERT INTO Interns (DoctorId)
VALUES
(3),(14),(13),(6),(20),(19),(17),(15),(5),(18),(7),(9),(25),(1),(12),(16),(4),(23),(24),(27);
GO
CREATE TABLE Professors
(
Id INT PRIMARY KEY IDENTITY(1,1),
DoctorId INT NOT NULL FOREIGN KEY REFERENCES Doctors (Id)
)
GO
INSERT INTO Professors (DoctorId)
VALUES
(8),(11),(2),(22),(10),(21),(26);
GO
CREATE TABLE Wards
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] VARCHAR(20) NOT NULL UNIQUE,
Places INT NOT NULL CHECK (Places >= 1),
DepartmentId INT NOT NULL FOREIGN KEY REFERENCES Departments (Id) 
);
GO
INSERT INTO Wards ([Name], Places, DepartmentId)
VALUES
('Konklux', 20, 10),('Daltfresh', 6, 14),('Gembucket', 5, 8),('Aerified', 16, 5),('Redhold', 5, 9),('Domainer', 13, 1),('Fixflex', 17, 5),('Bitwolf', 6, 1),
('Tresom', 13, 12),('Bigtax', 7, 15),('Voltsillam', 16, 7),('Bamity', 12, 10),('Kanlam', 8, 9),('Andalax', 18, 11),('Overhold', 5, 2),('Stringtough', 10, 4),
('Duobam', 17, 6),('Treeflex', 10, 9),('Sub-Ex', 9, 9),('Temp', 10, 10),('Zoolab', 11, 7),('Lotlux', 11, 1),('Flexidy', 20, 6),('Quo Lux', 11, 3),
('Ventosanzap', 13, 7),('Viva', 6, 5),('Cookley', 6, 3),('Zathin', 18, 1),('Sonsing', 9, 10),('Pannier', 7, 4);
GO

---===================================   REQUESTS   ============================================

--- 1.Вывести названия и вместимости палат, расположенных в 5-м корпусе, вместимостью 5 и более мест, если в этом корпусе есть хотя бы одна палата вместимостью более 15 мест.
SELECT w.[Name] AS 'Wards name', w.Places
FROM Wards AS w JOIN Departmens AS d ON w.DepartmentId = d.Id
WHERE d.Building = 5 AND w.Places >= 5
AND EXISTS (SELECT Places
			FROM Wards AS w2 JOIN Departments AS d2 ON w2.DepartmentId = d2.Id
		    WHERE w2.Places > 15 AND d2.Id = d.Id)

--- 2.Вывести названия отделений в которых проводилось хотя бы одно обследование за последний месяц.
SELECT DISTINCT d.[Name] 
FROM Departments AS d JOIN Wards AS w ON w.DepartmentId = d.Id
				      JOIN DoctorsExaminations AS de ON de.WardId = w.Id
WHERE DATEDIFF(MONTH, de.[date], GETDATE()) = 1;

--- 3.Вывести названия заболеваний, для которых не проводятся обследования.
SELECT d.[Name] AS 'Diseases name'
FROM Diseases AS d JOIN DoctorsExaminations AS de ON de.DiseaseId = d.Id
				   JOIN Examinations AS e ON de.ExaminationsId = e.Id
				   WHERE de.DiseaseId != d.Id;

--- 4.Вывести полные имена врачей, которые не проводят обследования.
SELECT d.[Name] + ' ' + d.Surname AS 'Doctors name'
FROM Doctors AS d JOIN DoctorsExaminations AS de ON de.DoctorId = d.Id
				  JOIN Examinations AS e ON de.ExaminationsId = e.Id
				  WHERE de.DoctorId <> d.Id

--- 5.Вывести названия отделений, в которых не проводятся обследования.
SELECT d.[Name] AS 'Department name'
FROM Departments AS d JOIN Wards AS w ON w.DepartmentId = d.Id
					  JOIN DoctorsExaminations AS de ON de.WardId = w.Id
					  JOIN Examinations AS e ON de.ExaminationsId = e.Id
					  WHERE de.WardId != w.Id AND w.DepartmentId <> d.Id;

--- 6.Вывести фамилии врачей, которые являются интернами.
SELECT d.Surname AS 'Doctors surname'
FROM Doctors AS d JOIN Interns As i ON i.DoctorId = d.Id;

--- 7.Вывести фамилии интернов, ставки которых больше, чем ставка хотя бы одного из врачей.            
SELECT DISTINCT d.Surname AS 'Interns name'
FROM Interns AS i JOIN Doctors AS d ON i.DoctorId = d.Id, Professors AS p
				  WHERE (SELECT d.Salary FROM Doctors AS d WHERE i.DoctorId = d.Id) > ANY (SELECT d.Salary FROM Doctors AS d WHERE p.DoctorId = d.Id)
				 
--- 8.Вывести названия палат, чья вместимость больше, чем вместимость каждой палаты, находящейся в 3-м корпусе. 
SELECT w.[Name] AS 'Wards name'
FROM Wards AS w JOIN Departments As d ON w.DepartmentId = d.Id
WHERE w.Places > ALL (SELECT Places FROM Wards AS w, Departments AS d WHERE d.Building = 3)

--- 9.Вывести фамилии врачей, проводящих обследования в отделениях “Ophthalmology” и “Cardiology”.
SELECT doc.Surname
FROM Doctors AS doc JOIN DoctorsExaminations AS de ON de.DoctorId = doc.Id
				    JOIN Wards AS w ON de.WardId = w.Id
					JOIN Departments AS d ON w.DepartmentId = d.Id
					WHERE d.[Name] LIKE 'Cardiology' OR d.[Name] LIKE 'Ophthalmology'


--- 10.Вывести названия отделений, в которых работают интерны и профессоры
SELECT d.[Name] AS 'Department'
FROM Departments AS d JOIN Wards AS w ON w.DepartmentId = d.Id
					  JOIN DoctorsExaminations AS de ON de.WardId = w.Id
					  JOIN Doctors AS doc ON de.DoctorId = doc.Id
					  JOIN Professors AS p ON p.DoctorId = doc.Id
					  JOIN Inrerns AS i ON i.DoctorId = doc.Id
					  WHERE p.DoctorId = doc.Id AND i.DoctorId = doc.Id;

--- 11. Вывести полные имена врачей и отделения в которых они проводят обследования, если отделение имеет фонд финансирования более 100000.
SELECT doc.[Name] + ' ' + doc.Surname AS 'Doctors name', dep.[Name] AS 'Department name'
FROM Doctors AS doc JOIN DoctorsExaminations AS de ON de.DoctorId = doc.Id
					JOIN Wards AS w ON de.WardId = w.Id
					JOIN Departments As dep ON w.DepartmentId = dep.Id
					WHERE dep.Financing > 100000
					ORDER BY 'Doctors name'

--- 12. Вывести название отделения, в котором проводит обследования врач с наибольшей ставкой.
SELECT dep.[Name] AS 'Department name'
FROM Departments AS dep JOIN Wards AS w ON w.DepartmentId = dep.Id
						JOIN DoctorsExaminations AS de ON de.WardId = w.Id
						JOIN Doctors AS d ON de.DoctorId = d.Id
						WHERE d.Salary = (SELECT MAX(d.Salary) FROM Doctors AS d)

--- 13. Вывести названия заболеваний и количество проводимых по ним обследований.
SELECT d.[Name] AS 'Name of disease', COUNT(e.Id) AS 'Amount of examination'
FROM Diseases AS d JOIN DoctorsExaminations AS de ON de.DiseaseId = d.Id
				   JOIN Examinations AS e ON de.ExaminationsId = e.Id
				   GROUP BY d.[Name]