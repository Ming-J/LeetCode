import sys


def main():
    n = sys.stdin.readline().strip()
    n = int(n)
    dormRoom = 0
    for x in range(0,n):
        peopleIn, roomCap = map(int,sys.stdin.readline().strip().split()) 
        if peopleIn + 2 <= roomCap :
            dormRoom += 1
    print dormRoom

if __name__ == ("__main__"):
    main()
