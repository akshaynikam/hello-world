#!/usr/bin/python

def count_occur_str(text, key):
    occur = 0
    start = text.find(key)
    while start != -1:
        occur += 1
        start = text.find(key, start + len(key))
    
    return occur

def main():
    text = input("Enter input string : ")
    key = input("Enter string to search : ")
    occur = count_occur_str(text, key)
    print("No of occurences : %d" % (occur))

if __name__ == "__main__":
    main()
