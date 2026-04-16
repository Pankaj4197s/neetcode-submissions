-- Write your query below
select name, coalesce(sum(distance), 0) as travelled_distance
from users left join rides
on rides.user_id = users.id
group by rides.user_id, users.name
order by travelled_distance desc, name asc;