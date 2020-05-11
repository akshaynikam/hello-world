#!/usr/bin/python

#
# Write a program to accept number from user and check if the number is even
#

def is_even(n):
    if n % 2 == 0:
        print("%d is even" % (n))
    else:
        print("%d is odd" % (n))

def main():
    n = input("Enter number : ")
    is_even(n)

if __name__ == "__main__":
    main()
