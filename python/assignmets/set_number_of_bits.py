#!/usr/bin/python

#
# WaP to accept number from user,accept bit position and also number of bits to turn ON that set of bits in given number
#

def turn_on_set_of_bits(number, bit_position, number_of_bits):
    mask = ((2 ** number_of_bits) - 1) << bit_position;

    return number | mask

def main():
    number, bit_position, number_of_bits = input("Enter number, bit position and number of bits to turn on from that position : ")
    number = turn_on_set_of_bits(number, bit_position, number_of_bits)
    print("Result : %d" % (number))

if __name__ == "__main__":
    main()
