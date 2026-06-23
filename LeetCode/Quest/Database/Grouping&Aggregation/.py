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


# 

