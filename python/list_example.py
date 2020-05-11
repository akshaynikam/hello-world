#!/usr/bin/python

def example():
    l1 = [1, 2, 3]
    l1.append(4)
    # l1.append(5, 6, 7) #TypeError: append() takes exactly one argument (3 given) 
    l1.append([5, 6, 7]) # [5, 6, 7] treats as single element (nested list)
    l1.extend([8, 9])
    l1.insert(2, 10)
    l1.insert(14, 10)
    l1.insert(-2, 100) # negative indexing is nothing but reverse indexing
    print(type(l1))
    for x in l1:
        print(x)
    print("after poping")
    i = l1.pop()
    print(i)
    print(type(l1))
    for x in l1:
        print(x)
    i = l1.index(3)
    print("%d is at index %d" % (3, i))
    #i = l1.index(1000) # ValueError: 1000 is not in list

def main():
    example()

if __name__ == "__main__":
    main()
