# Write your MySQL query statement below
SELECT 
    a.id AS 'Id' FROM weather a, weather b
WHERE 
    DATEDIFF(a.recordDate, b.recordDate) = 1 AND a.Temperature > b.Temperature