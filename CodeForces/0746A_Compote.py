import sys


def check(a,b,c):
    x = min(a,b//2,c//4)
    return x + x*2 + x*4

def main():
    a = int(sys.stdin.readline())
    b = int(sys.stdin.readline())
    c = int(sys.stdin.readline())
    print(check(a,b,c))

if __name__ == "__main__":
    main()