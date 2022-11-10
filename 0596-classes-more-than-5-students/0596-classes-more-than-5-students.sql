# Write your MySQL query statement below
SELECT class
FROM (
    SELECT class, COUNT(*) AS C
    FROM Courses
    GROUP BY class
) AS T1
WHERE T1.C > 4;
