import sys

def main():
    n = int(sys.stdin.readline().strip())
    lst = []
    for x in range(0,n):
        row = []
        if x == 0:
            row = [1] * n
        else:
            for y in range(0,n):
              row.append(sum(lst[x-1][0:y+1]))
        lst.append(row)
    print(lst[n-1][n-1])

    
if __name__ == ("__main__"):
    main()
