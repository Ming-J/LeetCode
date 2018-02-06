import sys

def main():
    m, n = map( int, sys.stdin.readline().strip().split())
    if  min(m,n)%2 == 1:
        print("Akshat")
    else:
        print("Malvika")
    
if __name__ == ("__main__"):
    main()
