#!/usr/bin/python

def is_str2_is_rotation_of_str1(str1, str2):
    if len(str1) == len(str2):
        return str1 in (str2 + str2)
    return False

def main():
    str1, str2 = input("Enter two strings to check if it is rotation of one another : ")
    if is_str2_is_rotation_of_str1(str1, str2):
        print("%s is rotation of %s" % (str2, str1))
    else:
        print("%s is not a rotation of %s" % (str2, str1))

if __name__ == "__main__":
    main()
