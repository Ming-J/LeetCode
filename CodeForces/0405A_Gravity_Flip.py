import sys

def main():
    n = int(sys.stdin.readline().strip())
    list = [ int(x) for x in sys.stdin.readline().strip().split()]
    list = sorted(list)
    list = [str(n) for n in list]
    print(" ".join(list))

if __name__ == ("__main__"):
    main()
