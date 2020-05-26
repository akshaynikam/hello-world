#!/usr/bin/python

def from_keys(in_dict, value = None):
    out_dict = dict()
    if isinstance(value, list):
        i = 0
        for key in in_dict.keys():
            if (i < len(value)):
                out_dict[key] = value[i]
                i += 1
            else:
                out_dict[key] = None
    else:
        for key in in_dict.keys():
            out_dict[key] = value

    return out_dict

def main():
    d1 = {1 : "A", 2 : "B", 3 : "C", 4 : "D"}
    d2 = from_keys(d1)
    d3 = from_keys(d1, -1)
    d4 = from_keys(d1, [1, 2, 3])
    d5 = from_keys(d1, ['a', 'b', 'c', 'd'])
    d6 = from_keys(d1, [99, 88, 77, 66, 55, 44, 33])
    print(d1)
    print(d2)
    print(d3)
    print(d4)
    print(d5)
    print(d6)

if __name__ == "__main__":
    main()
