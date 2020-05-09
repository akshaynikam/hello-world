#!/usr/bin/python

#
# WaP to print Fibonacci series upto n (n - Accept from user)
#

def fib(n):
	seq = ""
	if n < 1:
		seq = "Invalid input"
	elif n == 1:
		seq = "0"
	else:
		fib = 1
		prev = 0
		n -= 2
		seq = "0 1"
		while n:
			temp = fib
			fib += prev
			prev = temp
			n -= 1
			seq += " " + str(fib)
		
	return seq;

def main():
	n = input("Enter n : ")
	seq = fib(n)
	print(seq);

if __name__ == "__main__":
	main()
