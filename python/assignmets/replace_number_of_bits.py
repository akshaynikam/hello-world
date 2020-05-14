#!/usr/bin/python

#
# WaP to accept 2 numbers from user, accept bit position and number of bits to be replaced of number 2 by number 1's corresponding bits
#

def replace_bits(number1, number2, bit_position, number_of_bits):
    #
    # | .. x1 .. | .. y1 .. | .. z1 .. | -> number1
    # | .. x2 .. | .. y2 .. | .. z2 .. | -> number2
    # | .. x2 .. | .. y1 .. | .. z2 .. | -> result (number2)
    #
    y1 = number1 & ((2 ** number_of_bits) - 1 << bit_position)
    x2y0z2 = number2 & (~((2 ** number_of_bits) - 1 << bit_position))
    number2 = x2y0z2 | y1

    return number2

def main():
    number1, number2, bit_position, number_of_bits = input("Enter two numbers, bit position and number of bits of number1 to be replace with number2 : ")
    number2 = replace_bits(number1, number2, bit_position, number_of_bits)
    print("Result : %d" % (number2))

if __name__ == "__main__":
    main()
