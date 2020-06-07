#!/usr/bin/python
import os.path

def count_char_words_lines(name):
    if os.path.exists(name):
        fd = open(name)
        if fd != None:
            cl = 0
            cw = 0
            cc = 0
            line = fd.readline()
            while line != "":
                line = line.strip('\n')
                cl = cl + 1
                cc = cc + len(line)
                cw = cw + len(line.split())
                line = fd.readline()

            return cc, cw, cl

def main():
    cc, cw, cl = count_char_words_lines(r"file3.txt")
    print("Chars : %d" % (cc))
    print("words : %d" % (cw))
    print("lines : %d" % (cl))

if __name__ == "__main__":
    main()
