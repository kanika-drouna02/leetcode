# Write your MySQL query statement below
select num
from MyNumbers
group by num
having count(num) =1
UNION ALL SELECT NULL
order by num DESC
limit 1;