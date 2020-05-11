#!/usr/bin/python

def max_min(l):
    mx = 0
    mn = l[0]
    for i in l:
        if mx < i:
            mx = i
        if mn > i:
            mn = i
    
    return mx, mn

def main():
    l = input("Enter list : ")
    mx, mn = max_min(l)
    print("Max : %d\nMin : %d" % (mx, mn))

if __name__ == "__main__":
    main()
