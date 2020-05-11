#!/usr/bin/python

#
#* * * *
# * * *
#  * *
#   *
#

def pattern_d(n):
    p = ""
    for i in range(n, 0, -1):
        for j in range(n - i):
            p += '  '
        for k in range(i, 0, -1):
            p += '*' + ' ' + ' ' + ' '
        p += '\n'
    
    print(p)

def main():
    n = input("Enter n : ")
    pattern_d(n)

if __name__ == "__main__":
    main()
