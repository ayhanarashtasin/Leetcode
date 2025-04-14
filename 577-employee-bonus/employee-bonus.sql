# Write your MySQL query statement below
select name , bonus
From Employee
left  join Bonus
On Employee.empID = Bonus.empID
where  Bonus.bonus is null or Bonus.bonus<1000;