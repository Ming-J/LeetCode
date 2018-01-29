import sys

def main():
    berland = sys.stdin.readline().strip()
    birland = sys.stdin.readline().strip()
    ind = 0;
    for c in reversed(berland):
        if c is not birland[ind]:
            print "NO"
            return
        ind += 1
    print "YES"
    return
    
if __name__ == ('__main__'):
    main()
