#!/usr/bin/python

import reverse_number

def check_palindrome(number):
	rev = reverse_number.reverse_int(number)
	return rev == number

def main():
	number = input("Enter number to check if it is palindrome : ")
	isit = check_palindrome(number)
	if isit:
		print("%d is palindrome" % (number))
	else:
		print("%d is not palindrome" % (number))

if __name__ == "__main__":
	main()
