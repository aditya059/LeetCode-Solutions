# Write your MySQL query statement below
SELECT Users.name, ifnull(sum(distance), 0) as travelled_distance
FROM Users LEFT Join Rides
ON Users.id = Rides.user_id
GROUP BY Users.id
ORDER BY travelled_distance desc, name asc;