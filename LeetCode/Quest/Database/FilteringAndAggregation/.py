# Q1. Customer Placing the Largest Number of Orders
def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    counts = orders.groupby("customer_number").size()
    top_customer = counts.idxmax()
    return pd.DataFrame({"customer_number": [top_customer]})

# Q2. Classes With at Least 5 Students
def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    result = (courses.groupby("class", as_index=False).agg(student_count=("student", "count")).query("student_count >= 5")[["class"]])
    return result

# Q3. Monthly Transactions I
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

# Q4. User Activity for the Past 30 Days I
def user_activity(activity: pd.DataFrame) -> pd.DataFrame:
    mask = (activity['activity_date'] > '2019-06-27') & (activity['activity_date'] <= '2019-07-27')
    result = activity[mask]
    result = result.groupby('activity_date')['user_id'].nunique().reset_index()
    result.columns = ['day', 'active_users']
    return result
