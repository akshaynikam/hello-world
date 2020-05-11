#!/usr/bin/python

def for_else(n):
    for i in range(6):
        if i == n:
            break;
    else:
        print("Loop executed completely")

def main():
    n = input("enter number : ")
    for_else(n)

if __name__ == "__main__":
    main()
