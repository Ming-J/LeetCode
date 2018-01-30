import sys

"""
* Can use the inclusion-exclusion principle
* |A U B| = |A|+|B|-|A intersct B|
"""
def main():
    kPunch = int(sys.stdin.readline().strip())
    lTail = int(sys.stdin.readline().strip())
    mHell = int(sys.stdin.readline().strip())
    nMom = int(sys.stdin.readline().strip())
    dragon = int(sys.stdin.readline().strip())
    fight = [kPunch, lTail, mHell, nMom]
    count = 0;
    for i in xrange(dragon):
        for n in fight:
            if (i+1) % n is 0:
                count += 1
                break
    print count
            

if __name__ == ("__main__"):
    main()
