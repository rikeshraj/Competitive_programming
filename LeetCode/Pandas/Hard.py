# 185. Department Top Three Salaries
def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    df = employee.merge(
        department,
        left_on="departmentId",
        right_on="id"
    )
    df["rnk"] = (
        df.groupby("departmentId")["salary"]
          .rank(method="dense", ascending=False)
    )
    return (
        df[df["rnk"] <= 3]
        .rename(columns={
            "name_y": "Department",
            "name_x": "Employee",
            "salary": "Salary"
        })
        [["Department", "Employee", "Salary"]]
    )
