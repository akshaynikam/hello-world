#!/usr/bin/python

def compare_2_dict(d1, d2):
    if not isinstance(d1, dict) or not isinstance(d2, dict) or len(d1) != len(d2):
        return False
    
    for key in d1.keys():
        if d2.has_key(key) and (d1[key] == d2[key]):
            continue
        return False
    
    return True

def main():
    d1 = input("Enter first dictionary : ")
    d2 = input("Enter second dictionary : ")

    assert isinstance(d1, dict), "Dictionary required"
    assert isinstance(d2, dict), "Dictionary required"

    if compare_2_dict(d1, d2):
        print("Dictionaries are same")
    else:
        print("Dictionaries are not same")

if __name__ == "__main__":
    main()
