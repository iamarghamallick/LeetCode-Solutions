# Write your MySQL query statement below
-- select max(salary) as SecondHighestSalary
-- from Employee
-- where salary < (select max(salary) from Employee);

# Solving using window function
WITH RankedSalaries AS (
    SELECT
        salary,
        DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM Employee
)

SELECT MAX(salary) as SecondHighestSalary
FROM RankedSalaries
WHERE rnk = 2;