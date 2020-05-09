def fun(*args):
	print(type(args))
	for x in args:
		print (type(x))
		print (x)

def main():
	#fun(1, 2, 3)
	#fun(1, 'x', 2.35)
	fun(1, '2', [3, 4, 5])

if __name__ == "__main__":
	main()
