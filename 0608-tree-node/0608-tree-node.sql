# Write your MySQL query statement below
# SELECT id, 'Root' AS Type FROM Tree WHERE p_id IS NULL
# UNION
# SELECT id, 'Leaf' AS Type 
# FROM Tree 
# WHERE
#     id NOT IN (SELECT DISTINCT p_id FROM Tree WHERE p_id IS NOT NULL) AND p_id IS NOT NULL
# UNION
# SELECT id, 'Inner' AS Type
# FROM Tree
# WHERE
#     id IN (SELECT DISTINCT p_id FROM Tree WHERE p_id IS NOT NULL) AND p_id IS NOT NULL

SELECT id, 
    CASE 
        WHEN tree.id = (SELECT t1.id FROM tree t1 WHERE t1.p_id IS NULL)
            THEN 'Root'
        WHEN tree.id IN (SELECT t1.p_id FROM tree t1)
            THEN 'Inner'
        ELSE 'Leaf'
    END AS type
FROM
    tree
ORDER BY 'Id'
    