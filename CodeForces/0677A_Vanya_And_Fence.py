import sys

def main():
    friends, fence = [ int(x) for x in sys.stdin.readline().split()]
    #height = [ int(x) for x in sys.stdin.readline().split()]
    width = 0
    for h in sys.stdin.readline().split():
        if int(h) > fence:
            width += 2
        else:
            width += 1
    print(width)
    
if __name__ == ("__main__"):
    main()
