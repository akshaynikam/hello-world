#!/usr/bin/python

#
# WaP to accept number from user and check if its a special number or not
# Special number is a number in which sum of factorial of the digits is equal to the number.
# Ex: 145
# 1! + 4! + 5! = 145
#

def fact(n):
    if n == 0:
        return 1
    return n * fact(n - 1)

def is_special(number):
    sum_of_fact_of_digits = 0
    original = number
    while number:
        digit = number % 10
        sum_of_fact_of_digits += fact(digit)
        number /= 10
    
    return sum_of_fact_of_digits == original

def main():
    number = input("Enter number to check if it is special number : ")
    isit = is_special(number)
    if isit:
        print("%d is special number" % (number))
    else:
        print("%d is not a special number" % (number))

if __name__ == "__main__":
    main()
