n1, n2, n3 = input("Enter numbers : ")

if n1 > n2:
	if n1 > n3:
		print ("%d is greatest" % (n1))
	else:
		print ("%d is greatest" % (n3))
elif n3 > n2:
	print ("%d is greatest" % (n3))
else:
	print ("%d is greatest" % (n2))

dd, mm, yy = input("Enter dd, mm, yy : ")
if dd < 1 or dd > 31:
	print ("day %d is invalid" % (dd))
elif mm < 1 or mm > 12:
	print ("month %d is invalid" % (mm))
elif yy < 1:
	print ("year %d is invalid" % (yy))
else:
	print ("date is valid %d:%d:%d" % (dd, mm, yy))
