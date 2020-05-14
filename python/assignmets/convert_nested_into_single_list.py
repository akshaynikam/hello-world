#!/usr/bin/python

def convertNestedIntoSingleList(l):
    res = list()

    for x in l:
        if isinstance(x, list):
            res.extend(convertNestedIntoSingleList(x))
        else:
            res.append(x)
    
    return res

def main():
    l = input("Enter nested list : ")
    l = convertNestedIntoSingleList(l)
    print(l)

if __name__ == "__main__":
    main()
