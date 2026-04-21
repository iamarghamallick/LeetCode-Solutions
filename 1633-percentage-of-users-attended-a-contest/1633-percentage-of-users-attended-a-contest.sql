# Write your MySQL query statement below
with cte as (
    select  count(*) as t from users
) 
select r.contest_id,
round((count(distinct r.user_id) * 100) / u.t, 2) as percentage
from cte u
cross join register r 
group by r.contest_id
order by percentage desc, r.contest_id;