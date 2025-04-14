# Write your MySQL query statement below
select e1.name
from Employee e1
inner join Employee e2 
ON e1.id = e2.managerID 
group by e2.managerID
having count(e2.managerId)>=5