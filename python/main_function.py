#!/usr/bin/python

def sum_odd_even(lb, ub):
    esum = 0
    osum = 0
    
    for i in range(lb, ub):
        if i % 2 == 0:
            esum += i
        else:
            osum += i

    return esum, osum;


def main():
    lb, ub = input("Enter lower and Upper bound : ")
    esum, osum = sum_odd_even(lb, ub);
    print("Even sum : %d" % (esum))
    print("Odd sum : %d" % (osum))

if __name__ == "loops_ex":
    print("You have imported the script")

if __name__ == "__main__":
    main()
