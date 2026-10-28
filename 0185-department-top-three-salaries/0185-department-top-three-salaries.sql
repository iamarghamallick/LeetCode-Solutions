# Write your MySQL query statement below
with RankedSalaries as (
    select 
        e.name as Employee,
        e.salary as Salary,
        d.name as Department,
        d.id,
        dense_rank() over (
            partition by d.id
            order by e.salary desc
        ) as rnk
    from Employee e
    join Department d
    on e.departmentId = d.id
)

select 
    Department,
    Employee,
    Salary
from RankedSalaries
where rnk <= 3;