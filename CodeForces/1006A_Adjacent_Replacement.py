import sys


class array():
    def __init__(self, arr):
        self.arr = arr

    def cal(self):
        for i in range(len(self.arr)):
            if self.arr[i] % 2 == 0:
                self.arr[i] -= 1
        print(*self.arr, sep=' ')


def main():
    n = sys.stdin.readline()
    arr = [int(x) for x in sys.stdin.readline().split()]
    t = array(arr)
    t.cal()
    return


if __name__ == "__main__":
    main()
