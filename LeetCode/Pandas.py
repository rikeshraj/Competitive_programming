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

# 595. Big Countries
def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    return world[(world['area'] >= 3000000) | (world['population'] >= 25000000)][['name', 'population', 'area']]
 
# 1757. Recyclable and Low Fat Products 
def find_products(products: pd.DataFrame) -> pd.DataFrame:
    return products[(products['low_fats'] == 'Y') & (products['recyclable'] == 'Y')][['product_id']]

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

