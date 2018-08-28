import sys

def main():
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    if n >= 31:
        print(m)
    else:
        print(m%(2**n))
    
if __name__ == ("__main__"):
    main()
