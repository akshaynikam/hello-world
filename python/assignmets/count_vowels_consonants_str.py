#!/usr/bin/python

def count_vowels_consonants(text):
    v = 0
    c = 0
    o = 0
    for t in text:
        if t in ['a', 'e', 'i', 'o', 'u']:
            v += 1
        elif t.isalpha():
            c += 1
        else:
            o += 1
    
    return v, c, o

def main():
    text = input("Enter text : ")
    vowels, consonants, others = count_vowels_consonants(text)
    print("Vowels     : %d" % (vowels))
    print("Consonants : %d" % (consonants))
    print("Others     : %d" % (others))

if __name__ == "__main__":
    main()
