#!/usr/bin/python

def unionOfTwoList(l1, l2):
    l3 = list()
    
    l3.extend(l1)

    for x in l2:
        if x not in l3:
            l3.append(x)
    
    return l3

def main():
    l1 = input("Enter list 1 : ")
    l2 = input("Enter list 2 : ")

    l3 = unionOfTwoList(l1, l2)
    
    print(l3)

if __name__ == "__main__":
    main()
