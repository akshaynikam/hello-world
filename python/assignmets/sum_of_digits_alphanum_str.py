#!/usr/bin/python

def sum_of_digits(text):
    s = 0
    for t in text:
        if t.isdigit():
            s += int(t)
    return s

def main():
    text = input("Enter alpha numeric string : ")
    s = sum_of_digits(text)

    print("sum of digits : %d" % (s))

if __name__ == "__main__":
    main()
