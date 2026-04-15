-- Write your query below
select seller.seller_name
from seller
where seller_id not in (select distinct seller_id from orders
where sale_date between '2020-01-01' AND '2020-12-31')
order by seller.seller_name;