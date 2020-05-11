#!/usr/bin/python

def sum_of_given_numbers(n):
    i = 0
    addition = 0
    while i < n:
        addition += input()
        i += 1
    print ("Sum of given numbers is %d" % (addition))

def main():
    n = input("Enter n : ")
    sum_of_given_numbers(n)

if __name__ == "__main__":
    main()
