import sys

"""
n Cards Even

unordered map 
"""

def main():
    cards = 6
    values = [  for x in stdin.readlin().split()]
    
    values = [(1,1),(5,2),(7,3),(4,4),(4,5),(3,6)]
    values.sort()
    lo = 0
    hi = len(values) - 1
    while lo < hi:
        print( str(values[lo][1])+' '+str(values[hi][1]))
        lo += 1
        hi -= 1
    
    print("HI")

if __name__ == ("__main__"):
    main()
