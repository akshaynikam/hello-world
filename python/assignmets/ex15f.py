#!/usr/bin/python

#
#   *
#  * *
# * * *
#* * * *
#

def pattern_f(n):
	p = ""
	for i in range(n):
		for j in range(n - i):
			p += '  '
		for k in range(i):
			p += '*' + ' ' + ' ' + ' '
		p += '\n'
	
	print(p)

def main():
	n = input("Enter n : ")
	pattern_f(n)

if __name__ == "__main__":
	main()
