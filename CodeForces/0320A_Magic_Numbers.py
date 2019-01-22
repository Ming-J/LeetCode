import sys

def magic(num):
    while num > 0:
        if num % 1000 == 144 :
            num //= 1000
        elif num % 100 == 14:
            num //= 100
        elif num % 10 == 1:
            num //= 10
        else:
            return False
    return True

def main():
    x = int(sys.stdin.readline())
    print("YES") if magic(x) else print("NO")

if __name__ == "__main__":
    main()