# Write your MySQL query statement below
select e1.name
from employee e1
where (
    select count(e2.managerid)
    from employee e2
    where e1.id = e2.managerid
) >= 5;