#!/usr/bin/python

#
# WaP to accept number from user and accept bit position to turn OFF in given number
#

def turn_off_bit(n, b):
    mask = ~(1 << b)
    n = n & mask
    return n

def main():
    n, b = input("Enter number and bit position to unset : ")
    n = turn_off_bit(n, b - 1)
    print("after turning %dth bit off, it becomes - %d" % (b, n))

if __name__ == "__main__":
    main()
