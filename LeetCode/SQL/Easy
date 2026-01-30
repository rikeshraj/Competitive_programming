175. Combine Two Tables
select firstName, lastName, city, state from Person p left join Address a on p.personId = a.personId 

181. Employees Earning More Than Their Managers
select e1.name as Employee from Employee e1, Employee e2 where e1.managerId = e2.id and e1.salary > e2.salary

584. Find Customer Referee
select name from Customer where referee_id is null or referee_id != 2

586. Customer Placing the Largest Number of Orders
select customer_number from Orders group by customer_number order by count(order_number) desc limit 1

596. Classes With at Least 5 Students
select class from Courses group by class having count(student)>4

620. Not Boring Movies
select * from Cinema where id % 2 = 1 and description != "boring" order by rating desc

1978. Employees Whose Manager Left the Company
select employee_id from Employees where salary < 30000 and manager_id is not null and manager_id not in (select distinct employee_id from Employees) order by employee_id
