import sys

'''

'''

def main():
    n = int(sys.stdin.readline())
    moon = [int(x) for x in sys.stdin.readline().split()]
    if n is 1:
        if moon[0] != 15:
            print(-1)
        else:
            print("DOWN")
    else:
        last1 = moon[n-1]
        last2 = moon[n-2]
        if last1 != 0 and last1 != 15:
            if last2 > last1:
                print("DOWN")
            else:
                print("UP")
        elif last1 == 15:
            print("DOWN")
        else:
            if (last1 == 0 and last2 == 1):
                print("UP")
            else:
                print("DOWN")

if __name__ == ("__main__"):
    main()
