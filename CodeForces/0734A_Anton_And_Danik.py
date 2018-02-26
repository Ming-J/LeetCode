import sys

def main():
    games = int(sys.stdin.readline().strip())
    winner = sys.stdin.readline().strip()
    anton = 0
    danik = 0
    for c in winner:
        if c == "A":
            anton += 1
        else:
            danik += 1
    if anton == danik:
        print("Friendship")        
    elif anton > danik:
        print("Anton")
    else:
        print("Danik")
        
if __name__ == ("__main__"):
    main()
