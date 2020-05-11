#!/usr/bin/python

#
# WaP to print following patterns:
#    1
#    1    2
#    1    2    3
#    1    2    3    4
#

def pattern_a(n):
    p = ""
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            p += str(j) + " "
        p += "\n"

    print(p)

def main():
    n = input("Enter n : ")
    pattern_a(n)

if __name__ == "__main__":
    main()
