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


#RunnerUpScore
if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    unique_socres = set(arr)
    sorted_scores = sorted(list(unique_socres))
    print(sorted_scores[-2])
  

#NestedLists


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


#Tuples
if __name__ == '__main__':
    n = int(raw_input())
    integer_list = map(int, raw_input().split())
    t = tuple(integer_list)
    print(hash(t))


#SwapCase


#StringSplitJoin


