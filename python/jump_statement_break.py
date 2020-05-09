#!/usr/bin/python

def break_example():
	sum = 0
	print("keep entering the numbers, enter 0 to stop")
	while 1:
		i = input()
		if not i:
			break
		sum += i
	
	print("Sum : %d" % (sum))

def main():
	break_example()

if __name__ == "__main__":
	main()
