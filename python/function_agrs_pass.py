#!/usr/bin/python

def fun(a, b = 10, c = 20, d = 30):
	print ("%d %d %d %d" % (a, b, c, d))

def main():
	fun(10, 20, 30, 40)
	fun(d = 4, b = 2, a = 1, c = 3)
	fun(100, 200, d = 300)

if __name__ == "__main__":
	main()
