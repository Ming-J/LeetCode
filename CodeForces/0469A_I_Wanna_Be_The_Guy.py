import sys

def main():
    lv = set()
    n = int(sys.stdin.readline().strip())
    lilX = [ int(x) for x in sys.stdin.readline().strip().split()]
    lilX.pop(0)
    lilY = [ int(x) for x in sys.stdin.readline().strip().split()]
    lilY.pop(0)
    lv = set(lilX) | set(lilY)
    for l in range(1,n+1):
        if l not in lv:
            print("Oh, my keyboard!")
            return
    print ("I become the guy.")

if __name__ == ("__main__"):
    main()
