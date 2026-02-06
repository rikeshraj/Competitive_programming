#Hello World!
if __name__ == '__main__':
  print("Hello, World!")


#If-Else
if __name__ == '__main__': 
  n = int(input().strip())
  if n%2 == 1:
    print("Weird")
  else:
    if n>=2 and n<6:
      print("Not Weird")
    elif n>=6 and n<21:
      print("Weird")
    else:
      print("Not Weird")


#ArithmeticOperators
if __name__ == '__main__':
  a = int(input())
  b = int(input())
  print(a+b)
  print(a-b)
  print(a*b)


#Division 
if __name__ == '__main__':
  a = int(input())
  b = int(input())
  print(a//b)
  print(a/b)


#Loops
if __name__ == '__main__':
  n = int(input())
  for i in range(n):
    print(i*i)


#Print Function
if __name__ == '__main__':
  n = int(input())
  result = ""
  for i in range(n):
    result += str(i+1)
  print(result)


#ListComprehensions
result = [[i, j, k] for i in range(x+1) for j in range(y+1) for k in range(z+1) if i+j+k != n]
#OR
result = []
for i in range(x+1):
  for j in range(y+1):
    for k in range(z+1):
       if i+j+k!=n:
         result.append([i, j, k])


#RunnerUpScore
if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    unique_socres = set(arr)
    sorted_scores = sorted(list(unique_socres))
    print(sorted_scores[-2])
  

#NestedLists
if __name__ == '__main__':
    records = []
    lowest_grade = 0
    students = []
    scores = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        records.append([name, score])
        scores.append(score)
    second_lowest_score=sorted(list(set(scores)))[1]
    students = [record[0] for record in records if record[1] == second_lowest_score]
    for name in sorted(students):
        print(name)


#FindingPercentage
if __name__ == '__main__':
  n = int(input())
  student_marks = {}
  for _ in range(n):
    name, *line = input().split()
    scores = list(map(float, line))
    student_marks[name] = scores
  query_name = input()
  marks = student_marks[query_name]
  average = sum(marks)/len(marks)
  print("{:.2f}".format(average))


#Lists
if __name__ == '__main__':
    N = int(input())
    result = []
    for i in range(N):
        actions = input().split()
        action = actions[0]
        act = actions[1:]
        if action == 'insert':
            result.insert(int(act[0]), int(act[1]))
        elif action == 'print':
            print(result)
        elif action == 'remove':
            result.remove(int(act[0]))
        elif action == 'append':
            result.append(int(act[0]))
        elif action == 'sort':
            result.sort()
        elif action =='pop':
            result.pop()
        elif action =='reverse':
            result.reverse()


#Tuples
if __name__ == '__main__':
    n = int(raw_input())
    integer_list = map(int, raw_input().split())
    t = tuple(integer_list)
    print(hash(t))

