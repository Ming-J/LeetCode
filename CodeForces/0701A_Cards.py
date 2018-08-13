import sys

"""
n Cards Even
unordered map 
"""

def main():
    cards = int(sys.stdin.readline())
    values = [ (int(x),i) for i, x in enumerate(sys.stdin.readline().split(),1)]
    values.sort()
    lo = 0
    hi = len(values) - 1
    while lo < hi:
        print( str(values[lo][1])+' '+str(values[hi][1]))
        lo += 1
        hi -= 1

if __name__ == ("__main__"):
    main()
