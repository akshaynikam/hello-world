#!/usr/bin/python

def get_dict_from_file(file_name):
    out_dict = dict()
    fd = open(file_name)
    lines = fd.readlines()
    for line in lines:
        key, sep, value = line.partition('=')
        out_dict[key] = value.rstrip()
    
    return out_dict

def main():
    d = get_dict_from_file("file1.txt")
    print(d)

if __name__ == "__main__":
    main()
