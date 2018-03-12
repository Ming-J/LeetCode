import sys
import heapq

def killD(strength, drags):
    while len(drags) > 0:
        x = heapq.heappop(drags)
        if strength > x[0]:
            strength += x[1]
        else:
            return "NO"
    return "YES"

def main():
    strengh, drag = [int(x) for x in sys.stdin.readline().strip().split()]
    drag_stren = []
    for ind in range(drag):
        s, b = [int(x) for x in sys.stdin.readline().strip().split()]
        heapq.heappush(drag_stren,(s,b))

    print(killD(strengh, drag_stren))

if __name__ == ("__main__"):
    main()
