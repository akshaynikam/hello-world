#!/usr/bin/python

#
# WaP to accept number from user,accept bit position and also number of bits to TOGGLE that set of bits in given number
#

def toggle_set_of_bits(number, bit_position, number_of_bits):
    mask = 0;
    for i in range(bit_position, bit_position + number_of_bits):
        mask |= (1 << i)

    return number ^ mask

def main():
    number, bit_position, number_of_bits = input("Enter number, bit position and number of bits to toggle from that position : ")
    number = toggle_set_of_bits(number, bit_position, number_of_bits)
    print("Result : %d" % (number))

if __name__ == "__main__":
    main()
