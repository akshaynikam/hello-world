#!/usr/bin/python

def compareTwoList(l1, l2):
	if type(l1) != type(list) or type(l2) != type(list):
		print("arguments should be of type list")
		return False

	l1n = len(l1)
	l2n = len(l2)
	if l1n != l2n:
		return False
	for i in range(l1n):
		if l1[i] != l2[i]:
			break
	else:
		return True
	return False


def main():
	l1 = input("enter list 1 : ")
	l2 = input("enter list 2 : ")

	if compareTwoList(l1, l2):
		print("lists are same")
	else:
		print("lists are not same")

if __name__ == "__main__":
	main()
