#!/usr/bin/python

#
# WaP to check if given number is a Palindrome
#

def is_palindrome(number):
	return str(number) == str(number)[ : : -1]

def main():
	number = input("Enter number to check if its palindrome : ")
	isit = is_palindrome(number)
	if isit:
		print("%d is palindrome." % (number))
	else:
		print("%d is not palindrome." % (number))

if __name__ == "__main__":
	main()
