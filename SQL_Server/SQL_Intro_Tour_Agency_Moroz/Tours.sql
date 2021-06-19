---#1--- ������� �� ����, ������������ �� ����, ���� �� ����� ���
SELECT * FROM Tours
ORDER BY Country, Numbers_of_days ASC;   

---#2--- ������� �� ���� ��������� �� 5 �� 7 ���, ������������ �� ����� ���
SELECT * FROM Tours
WHERE Numbers_of_days >= 5 and Numbers_of_days <= 7
ORDER BY Numbers_of_days ASC;           

---#3--- ������� �� ���� � ������ �����, ������������ �� ����(�� ��������)
SELECT * FROM Tours
WHERE Country = 'Egypt'
ORDER BY Price DESC;               

---#4--- ������� �� ���� � ������ �����, �� "��� ��������"
SELECT * FROM Tours
WHERE Country = 'Egypt' and Food = 'True';   

---#5--- ������� ������� ����  � ������ �����, ��������� � ������� ����
SET DATEFORMAT dmy;
SELECT * FROM Tours
WHERE Country = 'Egypt' and Price < 700 and Start_date >= '25/05/2021';   

---#6--- ������� ��� ���� (������� Month(����)), ������������ �� �����
SELECT * FROM Tours
WHERE MONTH(Start_date) BETWEEN 6 and 8
ORDER BY Start_date; 

---#7--- ������ �����������, ��������, �������  ���� ����(����������� ����� ��� ���������� ������� - as)
SELECT MAX(Price) as 'Max tour price',
MIN(Price) as 'Min tour price',
AVG(Price) as 'Avarage tour price' FROM Tours;  

---#8--- ������� ��� ���� (������� Month(����)), ������������ �� �����
SELECT AVG(Price) as 'Avarage tour price ot Egypt' FROM Tours WHERE Country = 'Egypt';

---#9--- ������ ������� ����, ���� ���� ����� ����� ����
SELECT COUNT(*) as 'Number of tours where price < 700 EUR' FROM Tours WHERE Price < 700;

---#10--- �������  ���  ��� ���� � ������, ������� ��� �����(����������� �������� IN)
SELECT * FROM Tours
WHERE Country IN ('Spain', 'France', 'Italy')
ORDER BY Country;

---#11--- �������  ���� ��� ���� � ������ � �������, ���� �� �������
SELECT Country, Price as 'Price EUR', Price * 1.2 as 'Price USD', Price * 27.8 as 'Price UAN'
FROM Tours WHERE Country IN ('Spain', 'France', 'Italy')
ORDER BY Country;

---#12--- ������� ����, � ������ ���� � ����� �����(�-�, ����), LIKE  
SELECT * FROM Tours
WHERE Details LIKE '%Rivne%';

---#13--- ������� ����� ����, � �� ������������ ����, ��� �������( SELECT  DISTINCT ) 
SELECT DISTINCT Country FROM Tours;

---#14--- ������ ������� ����, � �� ������� ������� ����
SELECT COUNT(DISTINCT Country) as 'Number of unique countries' FROM Tours;

---#15--- ������ ��� ����������� ����
SELECT TOP 3 * FROM Tours
ORDER BY Price DESC;

---#16--- ������ ������ ��� ���� ������� ����
SELECT TOP 3 * FROM Tours
WHERE MONTH(Start_date) = '12' OR MONTH(Start_date) = '1' OR MONTH(Start_date) = '2'
ORDER BY Start_date;