import sys

def main():
    arr = [int(x) for x in sys.stdin.readline().split()]
    ppl = arr[0]
    bottle = arr[1]
    milPreBot = arr[2]
    lime = arr[3]
    slicesPreLime = arr[4]
    salt = arr[5]
    pplMil = arr[6]
    ppsalt = arr[7]
    totalMil = bottle * milPreBot
    totalSliceLime = lime * slicesPreLime
    print(min(totalMil//(pplMil*ppl),min(totalSliceLime//ppl,salt//(ppsalt*ppl))))

if __name__ == ("__main__"):
    main()
