# Write your MySQL query statement below
# select class , count(student) from Courses group by class having count(student) >= 6 ; 

select class
from 
    (select class, count(distinct student) as num
    from courses
    group by class) as temp
where num >= 5;