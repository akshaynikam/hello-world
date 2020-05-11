#!/usr/bin/python

def pattern(number):
	p = ''
	for i in range(number, 0, -1):
		for j in range(i, 0, -1):
			p += '  '
		for k in range(i, number + 1):
			p += '* '
		p += '\n'
	
	print(p)
		

def main():
	number = input("Enter number : ")
	pattern(number)

if __name__ == "__main__":
	main()
