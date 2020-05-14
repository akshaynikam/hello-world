#!/usr/bin/python

queue = list()
capasity = 5
size = 0

def enqueue(element):
    global size
    
    if size == capasity:
        print("Queue if full")
    else:
        queue.append(element)
        size += 1

def dequeue():
    global size

    if size == 0:
        print("Queue is empty")
        return -1

    size -= 1
    return queue.pop(0)

def main():
    while 1:
        ch = input("EnQ - 1, DeQ - 2 : ")
        if ch == 1:
            element = input("Enter element : ")
            enqueue(element)
        elif ch == 2:
            element = dequeue()
            if element != -1:
                print("dequeued element is %d" % (element))
        else:
            break;

if __name__ == "__main__":
    main()
