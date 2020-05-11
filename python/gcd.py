#!/usr/bin/python

def gcd_iterator(number1, number2):
	while number1 != number2:
		if number1 > number2:
			number1 -= number2
		else:
			number2 -= number1
	
	return number1

def gcd_recursive(number1, number2):
	if number1 == number2:
		return number1
	if number1 > number2:
		return gcd(number1 - number2, number2)
	return gcd(number1, number2 - number1)

def main():
	number1, number2 = input("Enter two numbers to find gcd : ")
	assert isinstance(number1, int), 'Expected int'
	assert isinstance(number2, int), 'Expected int'
	#result = gcd_recursive(number1, number2)
	result = gcd_iterator(number1, number2)
	print("Result : %d" % (result))

if __name__ == "__main__":
	main()
