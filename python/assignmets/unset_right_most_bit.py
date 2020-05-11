#!/usr/bin/python

#
# WaP to turnoff right most one bit in a number
#

def turn_off_righmost_bit(number):
    return number & (~1)

def main():
    number = input("Enter number to turn off its rightmost bit : ")
    number = turn_off_righmost_bit(number)
    print("Result : %d" % (number))

if __name__ == "__main__":
    main()
