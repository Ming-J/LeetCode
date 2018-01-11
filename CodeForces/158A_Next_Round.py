from sys import stdin, stdout

def main():
    n,k = map(int,stdin.readline().split())
    arr = [int(x) for x in stdin.readline().split()]

    x=0

    for i,val in enumerate(arr):
        if ( (i<k and val >0) or (arr[k-1]==val and val>0 )):
            x+=1
    
    print x

if __name__=="__main__":
    main()

    
