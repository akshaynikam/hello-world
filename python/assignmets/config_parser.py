#!/usr/bin/python

def parse(filename):
    fd = open(filename)
    lines = fd.readlines()
    config = dict()
    section = ""

    for line in lines:
        line = line.strip('\n')

        comment = line.find('#')
        if comment != -1:
            line = line[:comment]

        if line == "":
            continue

        if line.startswith('['):
            line = line[1:-1]
            section = line
            config[section] = dict()
        else:
            #print(line)
            key_value = line.split('=')
            config[section][key_value[0]] = key_value[1]

    return config

def main():
    config = parse(r"main.conf")
    print(config)

if __name__ == "__main__":
    main()
