# 183. Customers Who Never Order
def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    df = customers[~customers['id'].isin(orders['customerId'])]
    df = df[['name']].rename(columns={'name' : 'Customers'})
    return df
#OR 
def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    ordered_id = set(orders['customerId'])
    never_ordered = []
    for index, row in customers.iterrows():
        if row['id'] not in ordered_id: 
            never_ordered.append(row['name'])
    return pd.DataFrame({'Customers' : never_ordered})

# 586. Customer Placing the Largest Number of Orders
def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    counts = orders.groupby("customer_number").size()
    top_customer = counts.idxmax()
    return pd.DataFrame({"customer_number": [top_customer]})

# 595. Big Countries
def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    return world[(world['area'] >= 3000000) | (world['population'] >= 25000000)][['name', 'population', 'area']]

# 596. Classes With at Least 5 Students
def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    result = (courses.groupby("class", as_index=False).agg(student_count=("student", "count")).query("student_count >= 5")[["class"]])
    return result
 
# 1148. Article Views I
def article_views(views: pd.DataFrame) -> pd.DataFrame:
    viewer = views[views['author_id'] == views['viewer_id']]
    result = viewer[['author_id']].drop_duplicates().rename(columns={'author_id':'id'})
    result = result.sort_values(by='id')
    return result

# 1280. Students and Examinations
def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    base = students.merge(subjects, how="cross")
    count = (examinations.groupby(["student_id", "subject_name"]).size().reset_index(name="attended_exams"))
    result = (base.merge(count, on=["student_id", "subject_name"], how="left").fillna({"attended_exams": 0}))
    result["attended_exams"] = result["attended_exams"].astype(int)
    result = result.sort_values(["student_id", "subject_name"])
    return result[["student_id", "student_name", "subject_name", "attended_exams"]]

# 1378. Replace Employee ID With The Unique Identifier
def replace_employee_id(employees: pd.DataFrame, employee_uni: pd.DataFrame) -> pd.DataFrame:
    return (employees.merge(employee_uni, on="id", how="left")[["unique_id", "name"]])

# 1517. Find Users With Valid E-Mails
def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    pat = r'^[a-zA-Z][a-zA-Z0-9._-]*@leetcode\.com$'
    return users[users['mail'].str.match(pat)]

# 1527. Patients With a Condition
def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    result = patients[patients['conditions'].str.contains(r'(^| )DIAB1', regex=True)]
    return result

# 1633. Percentage of Users Attended a Contest
def users_percentage(users: pd.DataFrame, register: pd.DataFrame) -> pd.DataFrame:
    total_users = len(users)
    if total_users == 0:
        return pd.DataFrame(columns=["contest_id", "percentage"])
    df = (register.groupby("contest_id")["user_id"].count().reset_index(name="registered_count"))
    df["percentage"] = (df["registered_count"] * 100 / total_users).round(2)
    result = (df[["contest_id", "percentage"]].sort_values(by=["percentage", "contest_id"], ascending=[False, True]).reset_index(drop=True))
    return result

# 1667. Fix Names in a Table
def fix_names(users: pd.DataFrame) -> pd.DataFrame:
    users['name'] = users['name'].str.capitalize()
    return users.sort_values(by='user_id')

# 1757. Recyclable and Low Fat Products 
def find_products(products: pd.DataFrame) -> pd.DataFrame:
    return products[(products['low_fats'] == 'Y') & (products['recyclable'] == 'Y')][['product_id']]

#1873. Calculate Special Bonus
def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees.apply(
        lambda x: x['salary'] if x['employee_id']%2==1 and not x['name'].startswith('M')
        else 0, axis = 1
    )
    return employees[['employee_id', 'bonus']].sort_values(by='employee_id')

# 2877. Create a DataFrame from List
def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    df = pd.DataFrame(student_data, columns = ['student_id', 'age'])
    return df
 
# 2878. Get the Size of a DataFrame
def getDataframeSize(players: pd.DataFrame) -> List[int]:
    return list(players.shape)
 
# 2879. Display the First Three Rows
def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.head(3)
 
# 2880. Select Data
def selectData(students: pd.DataFrame) -> pd.DataFrame:
    return students[students['student_id'] == 101][['name', 'age']]

# 2881. Create a New Column
def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees['salary']*2
    return employees
 
# 2882. Drop Duplicate Rows
def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    return customers.drop_duplicates(subset='email', keep='first')
 
# 2883. Drop Missing Data
def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    return students.dropna(subset='name')
 
# 2884. Modify Columns
def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['salary'] = employees['salary']*2
    return employees

# 2885. Rename Columns
def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    students.columns = ['student_id', 'first_name', 'last_name', 'age_in_years']
    return students
#OR
def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    return students.rename(columns={'id':'student_id', 'first':'first_name', 'last':'last_name', 'age':'age_in_years'})
 
# 2886. Change Data Type
def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students['grade'] = students['grade'].astype(int)
    return students
 
# 2887. Fill Missing Data
def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    products['quantity'] = products['quantity'].fillna(0)
    return products
 
# 2888. Reshape Data: Concatenate
def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
    return pd.concat([df1, df2])

# 2889. Reshape Data: Pivot
def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    return weather.pivot(index='month', columns='city', values='temperature')
 
# 2890. Reshape Data: Melt
def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    return pd.melt(report, id_vars=['product'], var_name='quarter', value_name='sales')
 
# 2891. Method Chaining
def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    return animals[animals['weight']>100].sort_values(by='weight', ascending=False)[['name']]

