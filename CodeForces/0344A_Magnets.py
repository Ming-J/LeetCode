import sys

def main():
    magnets = int(sys.stdin.readline().strip())
    piece = 1
    preHead = None
    for x in range(magnets):
        mag = sys.stdin.readline().strip()
        head = mag[0]
        tail = mag[1]
        if head is preHead:
            piece += 1
        preHead = tail
    print(piece)

if __name__ == ("__main__"):
    main()
