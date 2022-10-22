# Write your MySQL query statement below
SELECT s.stock_name, SUM(s.price) as capital_gain_loss
FROM 
    (SELECT stock_name,
        CASE
            WHEN operation='Buy' THEN -price
            WHEN operation='Sell' THEN price
        END AS price
    FROM Stocks) AS s
GROUP BY s.stock_name