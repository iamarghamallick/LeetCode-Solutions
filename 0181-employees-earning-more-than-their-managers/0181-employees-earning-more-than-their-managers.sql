# Write your MySQL query statement below
select
    e1.name as Employee
from
    Employee e1
where 
    e1.salary > (
        select 
            e2.salary
        from
            Employee e2
        where 
            e1.managerId = e2.id
    );