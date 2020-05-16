#!/usr/bin/python

def recursive_length_encode_str(text):
    if "" == text:
        return text
    if 1 == len(text):
         return text + '1'
    new_str = recursive_length_encode_str(text[1:])
    if text[0] == new_str[0]:
        return new_str[0] + str(int(new_str[1]) + 1) + new_str[2:]
    return text[0] + '1' + new_str

def main():
    text = input("Enter string : ")
    print(recursive_length_encode_str(text))

if __name__ == "__main__":
    main()
