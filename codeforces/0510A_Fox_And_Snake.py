import sys

def main():
    n , m = [int(x) for x in sys.stdin.readline().strip().split()]
    left = True
    for i in range(n):
        if i % 2 ==0:
            left = not left
        for j in range(m):
            if i % 2 == 0:
                print("#", end="")
            else:
                if left and j == 0:
                    print("#", end="")
                elif not left and j == m - 1:
                    print("#", end="")
                else:
                    print(".",end="")
        print()
        
if __name__ == ("__main__"):
    main()
