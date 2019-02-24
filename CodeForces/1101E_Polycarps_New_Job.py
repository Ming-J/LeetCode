import sys


class Bill:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def getX(self):
        return self.x

    def getY(self):
        return self.y


def main():
    n = int(sys.stdin.readline())
    x_largest = 0
    y_largest = 0
    for _ in range(n):
        q, x, y = sys.stdin.readline().split()
        x = int(x)
        y = int(y)
        if(y > x):
            x, y = y, x
        if(q == '+'):
            if x > x_largest:
                x_largest = x
            if y > y_largest:
                y_largest = y
        else:
            # c1 = (x >= x_largest.x and y >= x_largest.y) or (
            #     x >= x_largest.y and y >= x_largest.x)
            # c2 = (x >= y_largest.x and y >= y_largest.y) or (
            #     x >= y_largest.y and y >= x_largest.x)
            c1 = (x >= x_largest and y >= y_largest) or (
                x >= y_largest and y >= x_largest)
            if c1:
                print("YES")
            else:
                print("NO")


if __name__ == "__main__":
    main()
