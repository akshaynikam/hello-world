#!/usr/bin/python

def longestShortestLines(name):
    fd = open(name)
    if fd != None:
        line = fd.readline()
        maxline = line
        minline = line
        while line != "":
            line = fd.readline()
            if line == "":
                break
            if len(maxline) < len(line):
                maxline = line
            if len(minline) > len(line):
                minline = line
        
        maxline = maxline.strip('\n')
        minline = minline.strip('\n')
        return maxline, minline

def main():
    maxline, minline = longestShortestLines(r"file3.txt")
    print("Maxline : %s" % (maxline))
    print("Minline : %s" % (minline))

if __name__ == "__main__":
    main()
