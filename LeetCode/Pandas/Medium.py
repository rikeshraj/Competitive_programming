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

# 178. Rank Scores
def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    scores["rank"] = scores["score"].rank(method="dense", ascending=False)
    scores = scores.sort_values(by="score", ascending=False)
    return scores[["score", "rank"]]

# 180. Consecutive Numbers
def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    mask = (
        (logs["num"] == logs["num"].shift(1)) &
        (logs["num"] == logs["num"].shift(2))
    )
    return pd.DataFrame({
        "ConsecutiveNums": logs.loc[mask, "num"].drop_duplicates()
    })

# 184. Department Highest Salary
def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    df = employee.merge(department, left_on="departmentId", right_on="id")
    max_salary = df.groupby("name_y")["salary"].transform("max")
    result = df[df["salary"] == max_salary]
    result = result.rename(columns={
        "name_y": "Department",
        "name_x": "Employee",
        "salary": "Salary"
    })
    return result[["Department", "Employee", "Salary"]]

# 550. Game Play Analysis IV
def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    first = activity.groupby("player_id", as_index=False)["event_date"].min()
    merged = activity.merge(first, on="player_id")
    matched = merged[
        merged["event_date_x"] ==
        merged["event_date_y"] + pd.Timedelta(days=1)
    ]["player_id"].nunique()
    total = activity["player_id"].nunique()
    return pd.DataFrame({
        "fraction": [round(matched / total, 2)]
    })

# 570. Managers with at Least 5 Direct Reports
def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    count = employee.groupby("managerId").size()
    manager_ids = count[count>=5].index
    return employee[employee["id"].isin(manager_ids)][["name"]]

# 1045. Customers Who Bought All Products
def find_customers(customer: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    total = product["product_key"].nunique()
    return (
        customer
        .groupby("customer_id")["product_key"]
        .nunique()
        .reset_index()
        .query("product_key == @total")
        [["customer_id"]]
    )

# 1070. Product Sales Analysis III
def sales_analysis(sales: pd.DataFrame) -> pd.DataFrame:
    first = sales.groupby("product_id")["year"].min().reset_index(name="first_year")
    return (
        sales.merge(first, on="product_id")
        .query("year == first_year")
        [["product_id", "first_year", "quantity", "price"]]
    )

# 1164. Product Price at a Given Date
def price_at_given_date(products: pd.DataFrame) -> pd.DataFrame:
    latest = (
        products[products["change_date"] <= "2019-08-16"]
        .sort_values(["product_id", "change_date"])
        .drop_duplicates("product_id", keep="last")
        [["product_id", "new_price"]]
    )
    return (
        products[["product_id"]]
        .drop_duplicates()
        .merge(latest, on="product_id", how="left")
        .fillna({"new_price": 10})
        .rename(columns={"new_price": "price"})
    )

# 1174. Immediate Food Delivery II
def immediate_food_delivery(delivery: pd.DataFrame) -> pd.DataFrame:
    first_orders = delivery.sort_values('order_date').drop_duplicates('customer_id')
    is_immediate = (first_orders['order_date'] == first_orders['customer_pref_delivery_date'])
    percentage = round(is_immediate.mean()*100, 2)
    return pd.DataFrame({'immediate_percentage': [percentage]})

# 1193. Monthly Transactions I
def monthly_transactions(transactions: pd.DataFrame) -> pd.DataFrame:
    transactions["trans_date"] = pd.to_datetime(transactions["trans_date"])
    transactions["month"] = transactions["trans_date"].dt.to_period("M").astype(str)
    transactions["approved_count"] = (transactions["state"] == "approved").astype(int)
    transactions["approved_amount"] = np.where(transactions["state"] == "approved", transactions["amount"], 0)
    result = (
        transactions.groupby(["month", "country"], dropna=False, as_index=False).agg(
            trans_count=("id", "count"),
            approved_count=("approved_count", "sum"),
            trans_total_amount=("amount", "sum"),
            approved_total_amount=("approved_amount", "sum")
        )
    )
    return result

# 1907. Count Salary Categories
def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    low = (accounts["income"] < 20000).sum()
    avg = ((accounts["income"] >= 20000) & (accounts["income"] <= 50000)).sum()
    high = (accounts["income"] > 50000).sum()

    return pd.DataFrame({
        "category": ["Low Salary", "Average Salary", "High Salary"],
        "accounts_count": [low, avg, high]
    })

# 1934. Confirmation Rate
def confirmation_rate(signups: pd.DataFrame, confirmations: pd.DataFrame) -> pd.DataFrame:
    merged = signups.merge(confirmations, on='user_id', how='left')
    merged['confirmation_rate'] = (merged['action'] == 'confirmed')
    result = merged.groupby('user_id')['confirmation_rate'].mean().reset_index()
    result['confirmation_rate'] = result['confirmation_rate'].fillna(0).round(2)
    return result[['user_id', 'confirmation_rate']]
