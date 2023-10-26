# Write your MySQL query statement below
SELECT e2.name FROM Employee e1 INNER JOIN Employee e2 
ON e1.managerId = e2.id 
GROUP BY e1.managerId
HAVING COUNT(e1.id)>=5;
