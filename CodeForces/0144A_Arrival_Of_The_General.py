import sys

def movedBack(lst,n):
    ind = len(lst)-lst[::-1].index(n)-1
    count = 0;
    for k in range(ind,len(lst)-1):
        lst[k+1], lst[k] = lst[k], lst[k+1]
        count += 1
    return count

def movedFront(lst,n):
    ind = lst.index(n)
    count = 0;
    for k in range(ind,0,-1):
        lst[k-1], lst[k] = lst[k], lst[k-1]
        count += 1
    return count

def main():
    n = int(sys.stdin.readline().strip())
    lst = [int(x) for x in sys.stdin.readline().strip().split()]
    count = movedFront(lst,max(lst))
    count += movedBack(lst,min(lst))
    print(count)

if __name__ == ("__main__"):
    main()
