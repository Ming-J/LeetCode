import sys

def main():
    n = sys.stdin.readline().strip()
    numbers = sys.stdin.readline().strip()
    guest = [ int(c) for c in numbers.split()]
    nArr = [0]*4
    sum = 0
    
    #store all element in an array of bucket
    for val in guest:
        nArr[val-1] += 1
        sum += val

    # number of for 4 ppl group
    taxi = nArr[3] + nArr[2]
    sum -= (nArr[3]*4 + nArr[2] *3)
    
    nArr[0] -= nArr[2]

    if nArr[1] > 0:
        taxi += nArr[1] / 2
        if nArr[1] % 2 != 0 :
            taxi += 1
            nArr[0] -= 2

    while nArr[0] > 0 :
        taxi += 1
        nArr[0] -= 4
        
    print taxi


if __name__ == ("__main__"):
    main()
    
