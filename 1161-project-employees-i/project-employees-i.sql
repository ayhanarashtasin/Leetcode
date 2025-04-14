# Write your MySQL query statement below
select p.project_id , ROUND(sum(e.experience_years)/count(*),2) as average_years
from Project p
left join Employee e
ON p.employee_id = e.employee_id
Group by p.project_id