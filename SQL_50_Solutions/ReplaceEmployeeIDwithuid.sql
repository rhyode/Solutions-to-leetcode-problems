# 1378. Replace Employee ID With The Unique Identifier
SELECT unique_id, name
FROM Employees as E 
LEFT JOIN EmployeeUNI as U 
ON E.id=U.id
