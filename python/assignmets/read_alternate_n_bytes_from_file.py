#!/usr/bin/python

def read_alternate_10_bytes(filename):
    fd = open(filename)
    buff = fd.read(10)
    while len(buff) == 10:
        print(buff)
        fd.seek(10, 1)
        buff = fd.read(10)
    else:    
        print(buff)

def main():
    read_alternate_10_bytes(r"file2.txt")

if __name__ == "__main__":
    main()
