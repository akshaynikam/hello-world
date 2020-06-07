#!/usr/bin/python

import os.path

count_ext = {}

def callback(extensions, dirname, fnames):
    global count_ext
    for fname in fnames:
        ext = os.path.splitext(fname)[1]
        if ext != '' and ext in extensions:
            count_ext[ext] += 1
        else:
            count_ext["others"] += 1

def main():
    global count_ext
    top = "/users/aknikam/aksh/mango/hello-world"
    extensions = [".cpp", ".c", ".py"]
    count_ext = dict.fromkeys(extensions, 0)
    count_ext['others'] = 0
    os.path.walk(top, callback, extensions)
    print(count_ext)

if __name__ == "__main__":
    main()
