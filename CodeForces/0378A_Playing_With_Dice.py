import sys

def dice(a,b):
    one = draw = two = 0
    for i in range(1,7):
        diff1 = abs(a - i)
        diff2 = abs(b - i)
        if diff1 == diff2:
            draw += 1
        elif diff1 < diff2:
            one += 1
        else:
            two += 1
    print(one,draw,two,sep=' ') 

def main():
    a,b = sys.stdin.readline().split()
    dice(int(a), int(b))
    return

if __name__ == "__main__":
    main()