# Write your MySQL query statement below
SELECT T1.name AS Employee
FROM (Employee AS T1) JOIN (Employee AS T2)
WHERE T1.managerId = T2.id AND T1.salary > T2.salary;
