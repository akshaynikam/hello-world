#!/usr/bin/python

def reverse_list(l):
    i = 0;
    j = len(l) - 1
    while i < j:
        l[i], l[j] = l[j], l[i]
        i += 1
        j -= 1

def main():
    l = input("Enter list to reverse : ")
    #reverse_list(l)
    #l2 = l[ : : -1]
    l.reverse()
    print "Reverse list : ",
    print(l)

if __name__ == "__main__":
    main()
