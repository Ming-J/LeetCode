import sys

def main():
    lst = [int(x) for x in sys.stdin.readline().strip().split()]
    lst = set(lst)
    print(4-len(lst))

if __name__ ==("__main__"):
    main()
