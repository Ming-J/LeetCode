import sys

def checkPos(right, left, time):
    dif = right - left
    if time % 2  == 0:
        return dif * time//2
    else:
        return (dif * (time//2)) + right 


def main():
    t = int(sys.stdin.readline())
    for y in range(t): 
        a,b,k = [int(x) for x in sys.stdin.readline().split()]
        print(checkPos(a,b,k))

if __name__ == "__main__":
    main()