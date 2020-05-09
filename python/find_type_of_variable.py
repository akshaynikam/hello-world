#!/usr/bin/python

def print_variable_type(var):
	print(type(var))

def main():
	print_variable_type(10)
	print_variable_type("akshay")
	print_variable_type(3.27)
	print_variable_type(10 + 3j)

if __name__ == "__main__":
	main()
