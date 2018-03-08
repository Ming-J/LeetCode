import sys

def main():
    houses, todo = [int(x) for x in sys.stdin.readline().strip().split()]
    pos = 1
    time = 0
    for x in sys.stdin.readline().strip().split():
        goto = int(x)
        if goto >= pos:
            time += (goto - pos)
        else:
            time += ((houses - pos) + goto)
        pos = goto
    print(time)

if __name__ == ("__main__"):
    main()
