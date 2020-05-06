lb, up = input("Enter lower and Upper bound : ")

esum = 0
osum = 0

for i in range(lb, up):
	if i % 2 == 0:
		esum += i
	else:
		osum += i

print("Even sum : %d" % (esum))
print("Odd sum : %d" % (osum))
