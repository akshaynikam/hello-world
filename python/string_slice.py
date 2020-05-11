#!/usr/bin/python

def string_slice():
    str = "akshay"
    
    print(str[0]) #a
    print(str[1]) #k
    print(str[2]) #s
    print(str[3]) #h
    print(str[4]) #a
    print(str[5]) #y
    #print(str[6]) #IndexError: string index out of range
    
    #str[3] = 'x' #TypeError: 'str' object does not support item assignment
    
    # -6 -5 -4 -3 -2 -1
    #  a  k  s  h  a  y
    #  0  1  2  3  4  5
    
    print ("-6 -5 -4 -3 -2 -1")
    print (" a  k  s  h  a  y")
    print (" 0  1  2  3  4  5")
    
    print(str[-1]) #y
    print(str[-2]) #a
    print(str[-3]) #h
    print(str[-4]) #s
    print(str[-5]) #k
    print(str[-6]) #a
    
    print ("### slice ###")
    # syntax
    # [start index : end index : step value]
    #  inclusive     exclusive   increment
    #  default 0     default n   default 1
    
    print ("[2:] = " + str[2 : ]) # shay
    print ("[2:5] = " + str[2 : 5]) # sha
    print ("[2:1] = " + str[2 : 1]) # no output
    print ("[-5 : -2] = " + str[-5 : -2]) # ksh
    print ("[ : : 1] = " + str[ : : 1]) # akshay
    print ("[ : : 2] = " + str[ : : 2]) # asa
    print ("[5 : 1 : -1] = " + str[5 : 1 : -1]) # yahs
    print ("[-2 : -5 : -2] = " + str[-2 : -5 : -2]) # as
    print ("[-1 : -6 : -1] = " + str[-1 : -6 : -1]) # yahsk
    print ("[ : : -1] = " + str[ : : -1]) # yahska

def main():
    string_slice()

if __name__ == "__main__":
    main()
