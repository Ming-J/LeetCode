import sys

def main():
    a = sys.stdin.readline().strip()
    b = sys.stdin.readline().strip()

    a = a.upper()
    b = b.upper()

    if a == b:
        res = 0
    if a > b:
        res = 1
    if a < b:
        res = -1
        
    print res

if __name__ == ("__main__"):
    main()
