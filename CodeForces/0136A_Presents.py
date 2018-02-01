import sys

def main():
    n = sys.stdin.readline().strip()
    gift = [int(x) for x in sys.stdin.readline().strip().split()]
    recieved = [None for _ in xrange(len(gift))]
    for giftFrom,giftTo in enumerate(gift):
        recieved[giftTo-1] = giftFrom+1
    print (" ".join(map(str,recieved)))

if __name__ == ("__main__"):
    main()
