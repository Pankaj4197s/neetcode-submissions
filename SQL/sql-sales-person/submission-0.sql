-- Write your query below
select name from sales_person
where sales_id not in (
select orders.sales_id from orders join company
on orders.com_id = company.com_id
where company.name = 'CRIMSON');