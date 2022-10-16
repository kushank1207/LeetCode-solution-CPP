# Write your MySQL query statement below
SELECT id, 'Root' AS Type FROM Tree WHERE p_id IS NULL
UNION
SELECT id, 'Leaf' AS Type 
FROM Tree 
WHERE
    id NOT IN (SELECT DISTINCT p_id FROM Tree WHERE p_id IS NOT NULL) AND p_id IS NOT NULL
UNION
SELECT id, 'Inner' AS Type
FROM Tree
WHERE
    id IN (SELECT DISTINCT p_id FROM Tree WHERE p_id IS NOT NULL) AND p_id IS NOT NULL
    