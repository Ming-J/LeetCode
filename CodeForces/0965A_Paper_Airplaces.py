import sys, math

def calPack(ppl, make, airPreSheet, sheetPrePack):
    sheetNeeded = math.ceil(make/airPreSheet)
    return math.ceil((sheetNeeded * ppl)/(sheetPrePack))

def main():
    li = [ int(x) for x in sys.stdin.readline().split()]    
    ppl = li[0]
    make = li[1]
    airPreSheet = li[2]
    sheetPrePack = li[3]
    print(calPack(ppl,make,airPreSheet,sheetPrePack))
    
if __name__ == ("__main__"):
    main()
