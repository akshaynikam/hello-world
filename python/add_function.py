def add(a, b = 10):
	return a + b

def fun():
	return 1, 2, 3, 4

if __name__ == "__main__":
	print("Its a main function")
	a, b = input()
	print(add(a, b))
	print(add(b))
	print(add(b = 1, a = 0))
	a, b, c, d = fun()
	print("%d %d %d %d" % (a, b, c, d))
