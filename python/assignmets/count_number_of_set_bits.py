#!/usr/bin/python

#
# WaP to count number of 1 bits in a given number
#

def count_on_bits(number):
	count = 0;
	while (number):
		count += number & 1
		number = number >> 1

	return count

def main():
	number = input("Enter number to count its on bits : ")
	count = count_on_bits(number)
	print("Number of ON bits : %d" % (count))

if __name__ == "__main__":
	main()
