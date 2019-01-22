import sys

def main():
    y, b , r = [int(x) for x in sys.stdin.readline().split()]
    result = 0
    for i in range(1,y+1):
        if y >= i and b >= i + 1 and r >=i + 2:
            result = max(result, i * 3 + 3)
    print(result)

if __name__ == "__main__":
    main()