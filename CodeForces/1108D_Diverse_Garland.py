import sys


def c(lo, mid, hi):
    col = ["R", "B", "G"]
    for c in col:
        mid = c
        if lo != mid and mid != hi:
            return mid

def recolor(colors,n):
    change = 0
    for i in range(1,n):
        if colors[i-1] == colors[i]:
            change += 1
            for ch in "RBG":
                if ch != colors[i-1] and ch != colors[i+1]:
                    colors[i] = ch
    print(change)
    print(''.join(colors[0:-1]))

def main():
    n = int(sys.stdin.readline())
    arr = list(sys.stdin.readline()+'.')
    recolor(arr,n)


if __name__ == "__main__":
    main()
