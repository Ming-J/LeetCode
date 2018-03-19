import sys

def main():
    num = int(sys.stdin.readline().strip())
    if num >= 0:
        print(num)
    else:
        if num >= -10:
            print(0)
        else:
            last = str(num)[0:-1]
            lastbefore = str(num)[0:-2] + str(num)[-1]
            if int(last) > int(lastbefore):
                print(int(last))
            else:
                print(int(lastbefore))

if __name__ == ("__main__"):
    main()
