#!/usr/bin/python

#
# WaP to check if given number is a Palindrome
#
def reverse_int(number):
    rev = 0;
    sign = 1
    if number < 0:
        sign = -1
        number *= sign

    while number:
        rev = (rev * 10) + (number % 10)
        number /= 10

    return rev * sign

def is_palindrome(number):
    rev = reverse_int(number)
    return rev == number

def main():
    number = input("Enter number to check if its palindrome : ")
    isit = is_palindrome(number)
    if isit:
        print("%d is palindrome." % (number))
    else:
        print("%d is not palindrome." % (number))

if __name__ == "__main__":
    main()
