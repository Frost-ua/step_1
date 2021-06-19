CREATE DATABASE Hospital;
go
use Hospital;
go
---===================================   CREATE TABLES   ============================================
CREATE TABLE Examinations
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] NVARCHAR(100) NOT NULL UNIQUE,
[DayOfWeek] INT CHECK ([DayOfWeek] >= 1 AND [DayOfWeek] <= 7) NOT NULL,
StartTime TIME CHECK (StartTime >= '8:00:00' AND StartTime <= '18:00:00') NOT NULL,
EndTime TIME NOT NULL,
CHECK (EndTime > StartTime and EndTime < '18:00:00')
);

CREATE TABLE Departments
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] NVARCHAR(100) NOT NULL UNIQUE,
Building INT CHECK (Building >= 1 AND Building <= 5) NOT NULL,
[Floor] INT CHECK([FLOOR] > 0) NOT NULL,
Financing MONEY CHECK (Financing >= 0) DEFAULT 0 NOT NULL
);

CREATE TABLE Diseases
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] NVARCHAR(100) NOT NULL UNIQUE,
Severity INT CHECK (Severity >= 1) DEFAULT 1 NOT NULL
);

CREATE TABLE Doctors
(
Id INT PRIMARY KEY IDENTITY(1,1),
Surname NVARCHAR(MAX) NOT NULL,
[Name] NVARCHAR(MAX) NOT NULL,
Salary MONEY CHECK(Salary > 0) NOT NULL
);
ALTER TABLE Doctors ADD Phone CHAR(10) NOT NULL;
ALTER TABLE Doctors ADD Premium MONEY CHECK(Premium >= 0) NOT NULL;

CREATE TABLE Wards
(
Id INT PRIMARY KEY IDENTITY(1,1),
[Name] NVARCHAR(MAX) DEFAULT 'NoName' NOT NULL,
Building NVARCHAR(10) NOT NULL,
[Floor] int CHECK ([Floor] > 0) NOT NULL
);

---===================================   INSERT TABLES   ============================================

INSERT INTO Examinations ([Name], [DayOfWeek], StartTime, EndTime)
VALUES
('Ultrasound examination', '3', '10:00:00', '10:30:00'),('Electrocardiogram', '1', '10:00:00', '10:20:00'),
('CT scan', '2', '16:00:00', '17:30:00'),('Ultrasound examination of the eye', '3', '14:30:00', '15:15:00'),
('Echocardiography', '4', '11:30:00', '12:20:00'),('Joint ultrasound', '2', '10:45:00', '11:50:00'),
('CT scan of the chest cavity', '5', '11:20:00', '12:50:00'),('Magnetic resonance imaging', '3', '10:40:00', '12:00:00'),
('Spirography', '2', '12:00:00', '12:50:00'),('Bacteriological research', '4', '12:30:00', '15:30:00'),
('Tumor markers', '1', '10:30:00', '12:30:00'),('Jaw x-ray', '5', '10:00:00', '10:30:00');

INSERT INTO Departments ([Name], Building, [Floor], Financing)
VALUES
('Therapeutic', '3', '2', '65000'),('Cardiology', '5', '2', '55000'),('Infectious for adults', '2', '2', '75000'),
('Infectious for children', '2', '3', '125000'),('Ophthalmology', '3', '3', '25000'),('Traumatology', '3', '1', '45000'),
('Urology', '4', '2', '35000'),('Neurological', '4', '3', '29000'),('Dental', '4', '1', '41000'),('Reception', '1', '1', '8000');

INSERT INTO Diseases ([Name], Severity)
VALUES
('Gambling disorder', '5'),('Allergic rhinitis', '1'),('Flu', '4'),('Hepatosis', '1'),('Hemarthrosis', '2'),('Hypoglycemia', '2'),
('Bronchopneumonia', '3'),('Panniculitis', '4'),('Osteosarcoma', '2'),('Ornithodorosis', '2'),('Dromomania', '2'),
('Foreign Accent Syndrome', '1'),('Hypertrichosis', '1'),('Urbachs disease - Vite', '2'),('Electromagnetic hypersensitivity', '3'),
('Allotriophagy', '3'),('Twentieth century disease', '1'),('Chorea', '1'),('Porphyria', '5'),('Gulf War Syndrome', '4'),
('Micropsia', '1'),('Cotard syndrome', '3'),('Capgras syndrome', '2'),('Clinical lycanthropy', '2'),('', '1'),
('Fregoli syndrome', '2'),('Alien hand syndrome', '1');
UPDATE Diseases SET [Name] = 'COVID' WHERE Id = 25;

INSERT INTO Doctors (Surname, [Name], Salary, Phone, Premium)
VALUES
('Kopach','Ostap','15000','09845896','700'),('Bylen','Igor','12000','0864589615','500'),('Polyuhivych','Olga','25000','01258948','300'),
('Sytnyk','Oleksandr','18000','01258565','1000'),('Stolyarets','Oksana','14500','0789652','1500'),('Bratchuk','Maria','15900','04459600','750'),
('Svurudov','Dmytro','21000','04785456','900'),('Semenyuk','Alina','30500','0489652','1200'),('Samusenko','Oksana','12200','01589625','700'),
('Kosyuk','Larisa','26500','01452562','1700'),('Pohodilo','Olga','14500','04787776','2700'),('Prtunenko','Volodymir','26300','04589658','1300'),
('Levkovskiy','Sergiy','45500','0145632045','1000'),('Kyts','Yulia','65000','045896555','960'),('Kopach','Ostap','32500','0145896245','2000'),
('Kazmirchuk','Oksana','23400','0147896525','1700');
DELETE Doctors WHERE Surname = 'Kopach' AND Salary = 15000;

INSERT INTO Wards ([Name], Building, [Floor])
VALUES
('A1', '1', '1'),('A2', '1', '1'),('A3', '1', '1'),('A4', '1', '1'),('A5', '1', '2'),('A6', '1', '2'),('A7', '1', '2'),('A8', '1', '2'),
('B1', '2', '1'),('B2', '2', '1'),('B3', '2', '1'),('B4', '2', '2'),('B5', '2', '3'),('B6', '2', '3'),('B7', '2', '4'),('B8', '2', '4'),
('C1', '3', '1'),('C2', '3', '1'),('C3', '3', '1'),('C4', '3', '2'),('C5', '4', '2'),('C6', '4', '3'),('C7', '4', '4'),('C8', '4', '5'),
('D1', '5', '1'),('D2', '5', '1'),('D3', '5', '1'),('D4', '5', '2'),('D5', '5', '2'),('D6', '5', '2'),('D7', '5', '3'),('D8', '5', '3');

--- Вывести содержимое таблицы палат.
SELECT * FROM Wards;

--- Вывести фамилии и телефоны всех врачей.
SELECT Surname, Phone FROM Doctors;

--- Вывести все этажи без повторений, на которых располагаются палаты(DISTINCT).
SELECT DISTINCT [Floor] FROM Wards;

---	Вывести названия заболеваний под именем “Name of Disease” и степень их тяжести под именем “Severity of Disease”.
SELECT [Name] AS 'Name of Disease', Severity AS 'Severity of Disease' FROM Diseases;

---	Использовать выражение FROM для любых трех таблиц базы данных, используя для них псевдонимы.
SELECT  dep.[Name] AS 'Department name', ex.[Name] AS 'Examenation name', doc.Surname AS 'Doctor name'
FROM Departments AS dep, Examinations AS ex, Doctors AS doc
WHERE dep.Name = 'Cardiology' AND ex.Name = 'Echocardiography' AND doc.Surname = 'Kopach';

--- Вывести названия отделений, расположенных в корпусе 4 и имеющих фонд финансирования менее 30000.
SELECT [Name] FROM Departments
WHERE Building = 4 AND Financing < 30000;

--- Вывести названия отделений, расположенных в 3-м корпусе с фондом финансирования в диапазоне от 20000 до 50000.
SELECT [Name] FROM Departments
WHERE Building = 3 AND Financing BETWEEN 20000 AND 50000;

---	Вывести названия палат, расположенных в корпусах 4 и 5 на 1-м этаже.
SELECT [Name] FROM Wards
WHERE Building IN (4, 5) AND [Floor] = 1;

---	Вывести названия, корпуса и фонды финансирования отделений,
--- расположенных в корпусах 3 или 6 и имеющих фонд финансирования меньше 30000 или больше 60000.
SELECT [Name], Financing, Building FROM Departments
WHERE (Building = 3 OR Building = 6) AND Financing NOT BETWEEN 30000 AND 60000;

--- Вывести фамилии врачей, чья зарплата (сумма ставки и надбавки) превышает 33000.
SELECT Surname FROM Doctors
WHERE Salary + Premium > 33000;

--- Вывести фамилии врачей, у которых третья часть зарплаты превышает десятикрвтную надбавку.
SELECT Surname FROM Doctors
WHERE Salary/3 > Premium*10;

--- Вывести названия обследований без повторений, проводимых в первые три дня недели с 12:00 до 15:00. 
SELECT DISTINCT [Name] FROM Examinations
WHERE [DayOfWeek] IN (1,2,3) AND StartTime >= '12:00:00' AND EndTime <= '15:00:00';

--- Вывести названия и номера корпусов отделений, расположенных в корпусах 1, 3, 8 или 10.
SELECT [Name], Building FROM Departments
WHERE Building IN (1,3,8) OR Building = 10;

--- Вывести названия заболеваний всех степеней тяжести, кроме 1-й и 2-й.
SELECT [Name], Severity FROM Diseases
WHERE NOT Severity = 1 AND NOT Severity = 2;

--- Вывести названия отделений, которые не располагаются в 1-м или 3-м корпусе.
SELECT [Name], Building FROM Departments
WHERE NOT Building = 1 AND NOT Building = 3;

--- Вывести названия отделений, которые располагаются в 1-м или 3-м корпусе.
SELECT [Name], Building FROM Departments
WHERE Building = 1 OR Building = 3;

---	Вывести фамилии врачей, начинающиеся на букву “K”.
SELECT Surname FROM Doctors
WHERE Surname LIKE 'K%';

---	Підвищити заробітну плату лікарям на 20%.
UPDATE Doctors SET Salary = (Salary + (Salary * 0.2));

---	Вилучити  обстеження, проведені у понеділок.
DELETE Examinations WHERE [DayOfWeek] = 1;