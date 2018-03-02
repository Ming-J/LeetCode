import sys

def main():
    n = int(sys.stdin.readline().strip())
    lst = [0]*26
    for c in sys.stdin.readline().strip():
        lst[ord(c.upper()) - ord("A")] += 1
    for x in lst:
        if x == 0:
            print("NO")
            return
    print("YES")

if __name__ == ("__main__"):
    main()
