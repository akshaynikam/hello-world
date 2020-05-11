#!/usr/bin/python

def count_occurence(l, e):
    c = 0
    for x in l:
        if x == e:
            c += 1
    
    return c

def main():
    l = input("Enter list : ")
    e = input("Enter element to count : ")
    print("Count using user defined function : %d" % (count_occurence(l, e)))
    print("Count using built in function : %d" % (l.count(e)))

if __name__ == "__main__":
    main()
