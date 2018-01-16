import sys

def main():
    situation = sys.stdin.readline().strip()
    nOne = 0
    prev = ""
    
    for c in situation:
        if c is prev:
            nOne += 1
        else:
            nOne = 1
            prev = c
        if nOne >= 7:
            print "YES"
            return
        
    print "NO"
        

if __name__ == ('__main__'):
    main()
