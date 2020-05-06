#
# 5 - exceptional
# 4 - outstanding
# 3 - good
# 2 - improvment
# 1 - poor
#

rate = input("Enter rating : ")

if rate > 0 and rate < 6:
	if rate == 5:
		grade = "Exceptional"
	elif rate == 4:
		grade = "Outstanding"
	elif rate == 3:
		grade = "Good"
	elif rate == 2:
		grade = "Improvement"
	else:
		grade = "Poor"
	print ("Grade : %s" % (grade))
else:
	print ("Invalid rating")
