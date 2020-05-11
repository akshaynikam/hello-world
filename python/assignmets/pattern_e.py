#!/usr/bin/python

#
#    *
#    *      *
#    *      *       *
#    *      *       *       *
#

def pattern_e(n):
    p = ""
    for i in range(n):
        for j in range(i + 1):
            p += '*' + ' '
        p += '\n'
    
    print(p)

def main():
    n = input("Enter n : ")
    pattern_e(n)

if __name__ == "__main__":
    main()
