import sys

def calCost(rides, bundle, single, deal):
    singleCost = rides * single
    numberOfBundle = rides//bundle
    ticRem = rides%bundle 
    bundleCost = numberOfBundle*deal + ticRem*single
    allBundle = (numberOfBundle+1)*deal
    return min(singleCost,min(bundleCost,allBundle))

def main():
   arr =[int(x) for x in sys.stdin.readline().strip().split()]
   rides, bundle, single, deal = arr
   print(calCost(rides,bundle,single,deal))

if __name__ == ("__main__"):
    main()
