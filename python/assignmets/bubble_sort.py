#!/usr/bin/python

def bubbleSortList(l):
    n = len(l)
    flag = False
    for i in range(n):
        flag = False
        for j in range(1, n - i):
            if l[j - 1] > l[j]:
                l[j - 1], l[j] = l[j], l[j - 1]
                flag = True
        if not flag:
            break

def main():
    l = input("Enter list : ")
    bubbleSortList(l)
    print(l)

if __name__ == "__main__":
    main()
