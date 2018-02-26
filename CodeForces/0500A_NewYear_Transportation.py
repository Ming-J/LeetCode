import sys

def main():
    cells, goTo = [int(x) for x in sys.stdin.readline().strip().split()]
    portal = [int(x) for x in sys.stdin.readline().strip().split()]
    ind = 0
    while ind < cells - 1 and ind != goTo-1 :
        ind += portal[ind]
    if ind == goTo - 1:
        print("Yes")
    else:
        print("No")

if __name__ == ("__main__"):
    main()
