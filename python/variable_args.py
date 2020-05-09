def fun(*args):
	print(type(args))
	for x in args:
		print (type(x))
		print (x)

#fun(1, 2, 3)
#fun(1, 'x', 2.35)
fun(1, '2', [3, 4, 5])
