#!/usr/bin/python

#"www.google.com"
#"www.facebook.com"

def get_domain(url):
    print (url[4 : -4])
    print (url[-5 : 3 : -1])

def main():
    url = input("Enter URL : ")
    get_domain(url)

if __name__ == "__main__":
    main()
