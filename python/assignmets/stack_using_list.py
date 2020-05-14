#!/usr/bin/python

g_l = list()
g_size = 0
g_capasity = 5

def push_stack(element):
    global g_size
    if g_size == g_capasity:
        print("Stack is full")
    else:
        g_l.append(element)
        g_size += 1

def pop_stack():
    global g_size
    if g_size == 0:
        print("Stack is empty")
        return -1
    g_size -= 1
    return g_l.pop()

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
