#!/usr/bin/python

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

def main():
	number = input("Enter number to reverse : ")
	number = reverse_int(number)
	print("Reverse : %d" % (number))

if __name__ == "__main__":
	main()
