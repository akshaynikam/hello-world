#!/usr/bin/python

l = list()
size = 0
capasity = 5

def push_stack(element):
    global size
    if size == capasity:
        print("Stack is full")
    else:
        l.append(element)
        size += 1

def pop_stack():
    global size
    if size == 0:
        print("Stack is empty")
        return -1
    size -= 1
    return l.pop()

def main():
    while 1:
        ch = input("Push - 1, Pop - 2 : ")
        if ch == 1:
            element = input("Enter element : ")
            push_stack(element)
        elif ch == 2:
            element = pop_stack()
            if element != -1:
                print("Poped element is %d" % (element))
        else:
            break;

if __name__ == "__main__":
    main()
