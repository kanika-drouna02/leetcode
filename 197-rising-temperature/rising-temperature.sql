# Write your MySQL query statement below
select today.id from Weather today
join Weather yes
on datediff(today.recordDate, yes.recordDate)=1
where today.temperature>yes.temperature;