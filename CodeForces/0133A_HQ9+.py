import sys

def main():

    n = sys.stdin.readline().strip()
    a = ['H' , 'Q' , '9']
    if any( x in n for x in a):
        print "YES"
    else:
        print "NO"

if __name__ == ('__main__'):
    main()
