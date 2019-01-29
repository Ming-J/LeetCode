import sys

def main():
    restaurant, time = map(int,sys.stdin.readline().split())
    res = None
    for i in range(restaurant):
        joy, time_need = map(int,sys.stdin.readline().split())
        if time_need <= time:
            res = max(res,joy) if res is not None else joy
        else:
            current = joy - (time_need - time)
            res = max(res,current) if res is not None else current
    print(res)

if __name__ == "__main__":
    main()