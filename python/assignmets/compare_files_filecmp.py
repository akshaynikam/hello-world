#!/usr/bin/python

# Compare two files using filecmp module

import filecmp

def main():
    print "file1.txt and file2.txt :",
    if filecmp.cmp(r"file1.txt", r"file2.txt"):
        print "Same"
    else:
        print "Not same"

    print "file1.txt and file1_cpy.txt :",
    if filecmp.cmp(r"file1.txt", r"file1_cpy.txt"):
        print "Same"
    else:
        print "Not same"

if __name__ == "__main__":
    main()
