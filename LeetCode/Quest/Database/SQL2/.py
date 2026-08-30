-- Q1. Investments in 2016
def find_investments(insurance: pd.DataFrame) -> pd.DataFrame:
    tiv_count = insurance.groupby('tiv_2015')['pid'].transform('count')
    location_count = insurance.groupby(
        ['lat', 'lon']
    )['pid'].transform('count')
    df = insurance[
        (tiv_count > 1) &
        (location_count == 1)
    ]
    return pd.DataFrame({
        'tiv_2016': [round(df['tiv_2016'].sum(), 2)]
    })

-- Q2. Department Highest Salary
def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    df = employee.merge(
        department,
        left_on='departmentId',
        right_on='id'
    )
    max_salary = df.groupby('departmentId')['salary'].transform('max')
    df = df[df['salary'] == max_salary]
    return df[['name_y', 'name_x', 'salary']].rename(
        columns={
            'name_y': 'Department',
            'name_x': 'Employee',
            'salary': 'Salary'
        }
    )

-- Q3. Product Sales Analysis III
def sales_analysis(sales: pd.DataFrame) -> pd.DataFrame:
    first_year = (
        sales.groupby('product_id')['year']
        .min()
        .reset_index()
        .rename(columns={'year': 'first_year'})
    )
    result = sales.merge(
        first_year,
        on='product_id'
    )
    result = result[result['year'] == result['first_year']]
    return result[
        ['product_id', 'first_year', 'quantity', 'price']
    ]

-- Q4. Human Traffic of Stadium
def human_traffic(stadium: pd.DataFrame) -> pd.DataFrame:
    df = stadium[stadium['people'] >= 100].copy()
    df = df.sort_values('id')
    df['row_num'] = range(1, len(df) + 1)
    df['grp'] = df['id'] - df['row_num']
    group_size = df.groupby('grp')['id'].transform('count')
    return (
        df[group_size >= 3]
        [['id', 'visit_date', 'people']]
        .sort_values('visit_date')
    )
