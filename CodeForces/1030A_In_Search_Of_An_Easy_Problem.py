import sys

def main():
    x = int(sys.stdin.readline().strip())
    opt = [int(z) for z in sys.stdin.readline().split()]
    if opt.count(1) >= 1:
        print("HARD")
    else:
        print("EASY")

if __name__ == "__main__":
    main()