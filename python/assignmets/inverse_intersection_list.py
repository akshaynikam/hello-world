#!/usr/bin/python

def inverseIntersectionOfLists(l1, l2):
    l3 = list()

    for x in l1:
        if x not in l2:
            l3.append(x)
    
    for x in l2:
        if x not in l1:
            l3.append(x)

    return l3

def main():
    l1 = input("Enter list 1 : ")
    l2 = input("Enter list 2 : ")

    l3 = inverseIntersectionOfLists(l1, l2)
    
    print(l3)

if __name__ == "__main__":
    main()
