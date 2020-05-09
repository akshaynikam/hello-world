#!/usr/bin/python

#
# WaP to accept 2 numbers from user, accept bit position and number of bits to be replaced of number 2 by number 1's corresponding bits
#

def replace_bits(number1, number2, bit_position, number_of_bits):
	for i in range(bit_position, bit_position + number_of_bits):
		bit = number1 & (1 << i)
		if bit:
			number2 |= bit
		else:
			number2 &= ~(1 << i)

	return number2

def main():
	number1, number2, bit_position, number_of_bits = input("Enter two numbers, bit position and number of bits of number1 to be replace with number2 : ")
	number2 = replace_bits(number1, number2, bit_position, number_of_bits)
	print("Result : %d" % (number2))

if __name__ == "__main__":
	main()
