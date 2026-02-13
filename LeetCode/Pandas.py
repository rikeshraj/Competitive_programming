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
