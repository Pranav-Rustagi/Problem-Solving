# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE FROM Person
WHERE id IN (
    SELECT id
    FROM (
        SELECT DISTINCT T1.id AS id
        FROM Person AS T1, Person AS T2
        WHERE T1.id <> T2.id AND T1.id > T2.id AND T1.email = T2.email
    ) AS P
);