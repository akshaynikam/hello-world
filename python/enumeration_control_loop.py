#!/usr/bin/python

def enum_control_loop(start, end, step):
	for i in range(start, end, step):
		print (i)

def main():
	enum_control_loop(0, 10, 2)

if __name__ == "__main__":
	main()
