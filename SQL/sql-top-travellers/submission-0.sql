-- Write your query below
select users.name, COALESCE(temp.travelled_distance, 0) as travelled_distance from users left join (
    select rides.user_id as id, sum(distance) as travelled_distance
    from rides
    group by rides.user_id) temp
on users.id = temp.id
order by travelled_distance desc, name asc;