#!/usr/bin/python

# generate zip file using shutil module

import shutil

def main():
    base_name = "test"
    ext = "tar"
    root_dir = "/users/aknikam/aksh/"
    base_dir = "primer"
    print(shutil.make_archive(base_name, ext, root_dir, base_dir))

if __name__ == "__main__":
    main()
