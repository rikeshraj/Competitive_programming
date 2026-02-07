#What's Your Name
def print_full_name(a, b):
    print("Hello {} {}! You just delved into python.".format(a,b))


#SwapCase
def swap_case(s):
    return s.swapcase()
#OR
def swap_case(s):
    result = ''
    for character in s:
        if character.isupper():
            result += character.lower()
        elif character.islower():
            result += character.upper()
        else: 
            result += character
    return result


#StringSplitJoin
def split_and_join(line):
    # write your code here
    line = line.split(" ")
    line = "-".join(line)
    return line


#Mutations
def mutate_string(string, position, character):
    string = string[:position] + character + string[position+1:]
    return string


#Find a string



#String Validators
if __name__ == '__main__':
    s = input().strip()
    print(any(c.isalnum() for c in s))
    print(any(c.isalpha() for c in s))
    print(any(c.isdigit() for c in s))
    print(any(c.islower() for c in s))
    print(any(c.isupper() for c in s))


#Text Alignment
thickness = int(input()) #This must be an odd number
c = 'H'
#Top Cone
for i in range(thickness):
    print((c*i).rjust(thickness-1)+c+(c*i).ljust(thickness-1))
#Top Pillars
for i in range(thickness+1):
    print((c*thickness).center(thickness*2)+(c*thickness).center(thickness*6))
#Middle Belt
for i in range((thickness+1)//2):
    print((c*thickness*5).center(thickness*6))    
#Bottom Pillars
for i in range(thickness+1):
    print((c*thickness).center(thickness*2)+(c*thickness).center(thickness*6))    
#Bottom Cone
for i in range(thickness):
    print(((c*(thickness-i-1)).rjust(thickness)+c+(c*(thickness-i-1)).ljust(thickness)).rjust(thickness*6))


#Text Wrap
return textwrap.fill(string, max_width)
#OR
return "\n".join([string[i : i+max_width]for i in range (0, len(string), max_width)])
#OR
result = []
for i in range(0, len(string), max_width):
  result.append(string[i : i+max_width])
return "\n".join(result)


#Designer Doormat
n, m = map(int, input().split())
#Top
for i  in range(1, n, 2):
    print((".|."*i).center(m, "-"))
#Middle
print("WELCOME".center(m, "-"))
#Bottom
for i in range(n-2, 0, -2):
    print((".|."*i).center(m, "-"))


#String Formatting
def print_formatted(number):
# your code goes here
width = len(bin(number)[2:])
for i in range(1, number+1):
  decimal = str(i).rjust(width)
  octal = oct(i)[2:].rjust(width)
  hexadecimal = hex(i)[2:].upper().rjust(width)
  binary = bin(i)[2:].rjust(width)
  print(f"{decimal} {octal} {hexadecimal} {binary}")


#Alphabet Rangoli



#Capitalize


