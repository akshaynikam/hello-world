#!/usr/bin/python

#
# WaP to accept number from user and accept bit position to turn ON in given number
#

def turn_on_bit(number, bit_position):
	mask = 1 << bit_position

	return number | mask

def main():
	number, bit_position = input("Enter number and bit position to turn ON : ")
	number = turn_on_bit(number, bit_position)
	print("Result : %d" % (number))

if __name__ == "__main__":
	main()
