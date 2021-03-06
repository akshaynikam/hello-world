#!/usr/bin/python

#
# WaP to accept number from user,accept bit position and also number of bits to turn OFF that set of bits in given number
#

def turn_off_set_of_bits(number, bit_position, number_of_bits):
    mask = ~(((2 ** number_of_bits) - 1) << bit_position);

    return number & mask

def main():
    n, sb, nb = input("Enter number, bit position and number of bits to turn off from that position : ")
    n = turn_off_set_of_bits(n, sb, nb)
    print("Result : %d" % (n))

if __name__ == "__main__":
    main()
