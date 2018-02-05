import sys

def main():
    total = int(sys.stdin.readline().strip())
    steps = total // 5
    if total % 5 != 0 :
        steps += 1
    print(steps) 

if __name__ == ("__main__"):
    main()
