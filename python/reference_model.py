#!/usr/bin/python

a = 1000
print(id(a))
#a = 10
#a = "Hi"
#b = 1000
b = a
print(id(b))

l1 = [1, 2, 3]
l2 = [1, 2, 3]
l3 = l1

print(id(l1))
print(id(l2))
print(id(l3))
