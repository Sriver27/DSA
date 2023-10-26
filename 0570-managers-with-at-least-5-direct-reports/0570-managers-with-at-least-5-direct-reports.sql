# Write your MySQL query statement below

#SELECT e2.name FROM Employee e1 INNER JOIN Employee e2 
#ON e1.managerId = e2.id 
#GROUP BY e1.managerId
#HAVING COUNT(e1.id)>=5;

SELECT e1.name
from Employee e1
WHERE e1.id IN (
    SELECT e2.managerId 
    FROM employee e2
    GROUP BY e2.managerID
    HAVING COUNT(e2.id) >= 5
);


