#!/usr/bin/python

def insertionSortList(l):
    for i in range(len(l) - 1):
        j = i
        temp = l[j + 1]
        while j >= 0 and temp < l[j]:
            l[j + 1] = l[j]
            j -= 1
        l[j + 1] = temp

def main():
    l = input("Enter list : ")
    insertionSortList(l)
    print(l)

if __name__ == "__main__":
    main()
