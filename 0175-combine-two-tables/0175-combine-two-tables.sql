# Write your MySQL query statement below
SELECT person.firstname, person.lastname, Address.City, Address.State FROM Person LEFT JOIN Address on Person.PersonId = Address.PersonId