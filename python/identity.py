#!/usr/bin/python

def identity():
	a = [1, 2, 3]
	b = [1, 2, 3]
	c = a
	print (a == b) # True
	print (c == b) # True
	print (a is b) # False # id(a) == id(b)
	print (a is c) # True  # id(a) == id(c)
	print (a is not b) # True

def main():
	identity()

if __name__ == "__main__":
	main()
