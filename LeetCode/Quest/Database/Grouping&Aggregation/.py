# Q1. Students and Examinations
# Write a solution to find the number of times each student attended each exam.
# Return the result table ordered by student_id and subject_name.
def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    df = students.merge(subjects, how='cross')
    exam_count = (
        examinations
        .groupby(['student_id', 'subject_name'])
        .size()
        .reset_index(name='attended_exams')
    )
    result = (
        df.merge(
            exam_count,
            on=['student_id', 'subject_name'],
            how='left'
        )
        .fillna(0)
    )
    result['attended_exams'] = result['attended_exams'].astype(int)
    return result.sort_values(
        ['student_id', 'subject_name']
    )


# Q2. Customers Who Bought All Products
# Write a solution to report the customer ids from the Customer table that bought all the products in the Product table.
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


# Q3. Tree Node
# Each node in the tree can be one of three types:
# "Leaf": if the node is a leaf node.
# "Root": if the node is the root of the tree.
# "Inner": If the node is neither a leaf node nor a root node.
# Write a solution to report the type of each node in the tree.
# Return the result table in any order.
def tree_node(tree: pd.DataFrame) -> pd.DataFrame:
    parents = set(tree["p_id"].dropna())
    result = tree[["id"]].copy()
    result["type"] = "Leaf"
    result.loc[tree["id"].isin(parents), "type"] = "Inner"
    result.loc[tree["p_id"].isna(), "type"] = "Root"
    return result

