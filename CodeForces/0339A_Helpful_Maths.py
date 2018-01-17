import sys

def main():

    #input = "1+2+3+1+2"
    input = [ int(c) for c in sys.stdin.readline().strip().split('+') ]
        
    arr = [0, 0, 0]
    for x in input:
        arr[x-1] += 1
    res = ""
    for i , val in enumerate (arr):     
        if(val is not 0):
            count = 0
            while count < val:
                if res is "":
                    res += str(i+1)
                else:
                    res += "+" + str(i+1)
                count += 1
    print res
    

if __name__ == ('__main__'):
    main()
