#!/usr/bin/python

def mergeTwoSortedList(l1, l2):
	l1n = len(l1)
	l2n = len(l2)
	i = 0
	j = 0
	l3 = list()
	while i < l1n and j < l2n:
		if l1[i] < l2[j]:
			l3.append(l1[i])
			i += 1
		else:
			l3.append(l2[j])
			j += 1
	
	if i < l1n:
		l3.extend(l1[i:])

	if j < l2n:
		l3.extend(l2[j:])

	return l3

def main():
	l1 = input("Enter list 1 : ")
	l2 = input("Enter list 2 : ")

	l3 = mergeTwoSortedList(l1, l2)

	for i in l3:
		print i,
	print "\n"

if __name__ == "__main__":
	main()
