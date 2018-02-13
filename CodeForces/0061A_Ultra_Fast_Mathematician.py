import sys

def calculation(lhs, rhs):
    sum = ""
    for i, char in enumerate(lhs):
        if char is not rhs[i]:
            sum += '1'
        else:
            sum += '0'
    return sum

def main():
    lhs = sys.stdin.readline().strip()
    rhs = sys.stdin.readline().strip()
    print(calculation(lhs,rhs))

if __name__ == ("__main__"):
    main()
