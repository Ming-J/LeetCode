import sys

def main():
    ppl = int(sys.stdin.readline().strip())
    if ppl == 1:
        print(0)
        return
    welfare = [int(x) for x in sys.stdin.readline().strip().split()]
    highest = max(welfare)
    charges = 0
    for x in welfare:
        charges += (highest - x)
    print(charges)

if __name__ == ("__main__"):
    main()
