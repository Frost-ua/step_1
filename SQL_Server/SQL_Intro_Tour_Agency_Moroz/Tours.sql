---#1--- Вибрати всі тури, впорядкувати по країні, потім по числу днів
SELECT * FROM Tours
ORDER BY Country, Numbers_of_days ASC;   

---#2--- Вибрати всі тури тривалістю від 5 до 7 днів, впорядкувати по числу днів
SELECT * FROM Tours
WHERE Numbers_of_days >= 5 and Numbers_of_days <= 7
ORDER BY Numbers_of_days ASC;           

---#3--- Вибрати всі тури у задану країну, впорядкувати по ціни(по спаданню)
SELECT * FROM Tours
WHERE Country = 'Egypt'
ORDER BY Price DESC;               

---#4--- Вибрати всі тури у задану країну, де "все включено"
SELECT * FROM Tours
WHERE Country = 'Egypt' and Food = 'True';   

---#5--- Вибрати недорогі тури  у задану країну, починаючи з вказаної дати
SET DATEFORMAT dmy;
SELECT * FROM Tours
WHERE Country = 'Egypt' and Price < 700 and Start_date >= '25/05/2021';   

---#6--- Вибрати літні тури (функція Month(дата)), впорядкувати по місяцю
SELECT * FROM Tours
WHERE MONTH(Start_date) BETWEEN 6 and 8
ORDER BY Start_date; 

---#7--- Знайти максимальну, мінімальну, середню  ціни турів(використати аліаси для обчислених значень - as)
SELECT MAX(Price) as 'Max tour price',
MIN(Price) as 'Min tour price',
AVG(Price) as 'Avarage tour price' FROM Tours;  

---#8--- Вибрати літні тури (функція Month(дата)), впорядкувати по місяцю
SELECT AVG(Price) as 'Avarage tour price ot Egypt' FROM Tours WHERE Country = 'Egypt';

---#9--- Знайти кількість турів, ціна яких менша деякої суми
SELECT COUNT(*) as 'Number of tours where price < 700 EUR' FROM Tours WHERE Price < 700;

---#10--- Вивести  дані  про тури у Іспанію, Францію або Італію(використати операцію IN)
SELECT * FROM Tours
WHERE Country IN ('Spain', 'France', 'Italy')
ORDER BY Country;

---#11--- Вивести  ціни усіх турів у Європу у гривнях, евро та доларах
SELECT Country, Price as 'Price EUR', Price * 1.2 as 'Price USD', Price * 27.8 as 'Price UAN'
FROM Tours WHERE Country IN ('Spain', 'France', 'Italy')
ORDER BY Country;

---#12--- Вивести тури, у описах яких є деяке слово(н-д, гори), LIKE  
SELECT * FROM Tours
WHERE Details LIKE '%Rivne%';

---#13--- Вибрати назви країн, у які пропонуються тури, без повторів( SELECT  DISTINCT ) 
SELECT DISTINCT Country FROM Tours;

---#14--- Знайти кількість країн, у які агенція пропонує тури
SELECT COUNT(DISTINCT Country) as 'Number of unique countries' FROM Tours;

---#15--- Знайти три найдорожчих тури
SELECT TOP 3 * FROM Tours
ORDER BY Price DESC;

---#16--- Знайти перших три тури зимових тури
SELECT TOP 3 * FROM Tours
WHERE MONTH(Start_date) = '12' OR MONTH(Start_date) = '1' OR MONTH(Start_date) = '2'
ORDER BY Start_date;