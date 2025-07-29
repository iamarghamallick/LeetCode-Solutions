# Write your MySQL query statement below
delete email1
from Person email1, Person email2
where email1.email = email2.email and email1.id > email2.id;