import sys

def main():
    n = int(sys.stdin.readline().strip())
    feel = ""
    for i in range(1,n+1):
        if i % 2 == 1:
            feel += "I hate "
        else:
            feel += "I love "
        if i == n:
            feel += "it"
        else:
            feel += "that "
    print(feel)
    
if __name__ ==("__main__"):
    main()
