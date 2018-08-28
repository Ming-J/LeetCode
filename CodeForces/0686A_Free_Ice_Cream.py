import sys

def main():
    n , x =[int(x) for x in sys.stdin.readline().split()]
    distress = 0
    for i in range(n):
        sign, d = [y  for y in sys.stdin.readline().split()]
        if sign is "+":
            x += int(d)
        else:
            ice = int(d)
            if x >= ice:
                x -= ice
            else:
                distress += 1
                print("{} {}".format(x,distress))
    
if __name__ == ("__main__"):
    main()
