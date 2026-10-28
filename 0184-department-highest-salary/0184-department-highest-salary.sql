# Write your MySQL query statement below
-- select d.name as Department, e.name as Employee, e.salary as Salary
-- from employee e
-- join department d
-- on e.departmentId = d.id
-- where e.salary = (select max(salary)
--     from employee
--     where departmentId = e.departmentId);

-- Solution using window functions
with RankedSalaries as (
    select 
        e.name as Employee,
        e.salary as Salary,
        e.departmentId,
        dense_rank() over (
            partition by e.departmentId
            order by e.salary desc
        ) as rnk
    from Employee e
)

select 
    d.name as Department,
    rs.Employee,
    rs.Salary
from RankedSalaries rs
join Department d
    on rs.departmentId = d.id
where rs.rnk = 1;