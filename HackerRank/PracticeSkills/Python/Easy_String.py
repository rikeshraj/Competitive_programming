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

