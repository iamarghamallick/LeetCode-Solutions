# Write your MySQL query statement below
-- select distinct
--     l1.Num as ConsecutiveNums
-- from 
--     Logs l1,
--     Logs l2,
--     Logs l3
-- where 
--     l1.Id = l2.Id - 1
--     and l2.Id = l3.Id - 1
--     and l1.Num = l2.Num
--     and l2.Num = l3.Num;

-- Solution using LAG()
WITH PreviousNums AS (
    SELECT
        Num,
        LAG(Num, 1) OVER (ORDER BY Id) AS prev1,
        LAG(Num, 2) OVER (ORDER BY Id) AS prev2
    FROM Logs
)
SELECT DISTINCT Num AS ConsecutiveNums
FROM PreviousNums
WHERE Num = prev1
  AND Num = prev2;