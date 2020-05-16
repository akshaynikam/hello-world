#!/usr/bin/python

def replace_occur_str(statement, old, new):
    i = statement.find(old)
    while i != -1:
        statement = statement[ : i] + new + statement[i + len(old) : ]
        i = statement.find(old, i + len(new))
    
    return statement

def main():
    statement = input("Enter statement : ")
    old, new = input("Enter old and new string to replace : ")
    statement = replace_occur_str(statement, old, new)
    print(statement)

if __name__ == "__main__":
    main()
