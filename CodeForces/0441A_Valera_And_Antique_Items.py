import sys


"""
n sellers
"""       



def main():
    n , amount = [int(x) for x in sys.stdin.readline().split()]
    sellers = []
    for i in range(n):
        array = [int(x) for x in sys.stdin.readline().split()]
        for x in range(1,len(array)):
            if array[x] < amount and (len(sellers) == 0 or sellers[len(sellers) - 1] != i+1):
                sellers.append(i+1)
    print(len(sellers))
    for x in sellers:
        print(x,end=" ")

if __name__ == ("__main__"):
    main()
