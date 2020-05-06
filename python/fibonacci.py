n = input("Enter n : ")

if n < 1:
	print("Invalid input")
elif n == 1:
	print("0")
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
	
	print(seq);
