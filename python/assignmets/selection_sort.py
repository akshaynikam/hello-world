#!/usr/bin/python

def selectionSortList(l):
    for i in range(len(l)):
        m = i
        for j in range(i + 1, len(l)):
            if l[m] > l[j]:
                m = j
        l[m], l[i] = l[i], l[m]

def main():
    l = input("Enter list : ")
    selectionSortList(l)
    print(l)

if __name__ == "__main__":
    main()
