# 176. Second Highest Salary
def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    distinct_sal = employee['salary'].drop_duplicates().sort_values(ascending=False)
    if len(distinct_sal) < 2:
        second_sal = None
    else:
        second_sal = distinct_sal.iloc[1]
    return pd.DataFrame({'SecondHighestSalary': [second_sal]})

# 177. Nth Highest Salary
def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    high = f"getNthHighestSalary({N})"
    df = employee["salary"].drop_duplicates().sort_values(ascending=False)
    return pd.DataFrame({high: [df.iloc[N-1] if N > 0 and N <= len(df) else None]})
 
# 570. Managers with at Least 5 Direct Reports
def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    count = employee.groupby("managerId").size()
    manager_ids = count[count>=5].index
    return employee[employee["id"].isin(manager_ids)][["name"]]

# 1934. Confirmation Rate
def confirmation_rate(signups: pd.DataFrame, confirmations: pd.DataFrame) -> pd.DataFrame:
    merged = signups.merge(confirmations, on='user_id', how='left')
    merged['confirmation_rate'] = (merged['action'] == 'confirmed')
    result = merged.groupby('user_id')['confirmation_rate'].mean().reset_index()
    result['confirmation_rate'] = result['confirmation_rate'].fillna(0).round(2)
    return result[['user_id', 'confirmation_rate']]
