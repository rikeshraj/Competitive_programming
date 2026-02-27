# Q1. Combine Two Tables
def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    result = person.merge(address, on="personId", how="left")
    return result[["firstName", "lastName", "city", "state"]]
 
# Q2. Employees Earning More Than Their Managers
def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    manager_salary = employee.set_index("id")["salary"]
    employee["mgr_salary"] = employee["managerId"].map(manager_salary)
    result = employee.loc[employee["salary"] > employee["mgr_salary"], ["name"]]
    return result.rename(columns={"name": "Employee"})
 
# Q3. Not Boring Movies
def not_boring_movies(cinema: pd.DataFrame) -> pd.DataFrame:
    result = (cinema[(cinema["id"] % 2 == 1) &(cinema["description"] != "boring")].sort_values(by="rating", ascending=False))
    return result
 
# Q4. Find Customer Referee
def find_customer_referee(customer: pd.DataFrame) -> pd.DataFrame:
    result = customer.loc[customer["referee_id"].isna() | (customer["referee_id"] != 2),["name"]]
    return result
