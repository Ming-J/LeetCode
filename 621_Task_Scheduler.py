import sys

class Solution():
    def leastInterval(self, tasks, n):
        lst = [0] * 26
        for c in tasks:
            lst[ord(c) - ord('A')] += 1
        lst.sort(reverse = True)
        count = 0
        while lst[0] > 0:
            tempN = 0
            #print(lst)
            while tempN <= n:
                if lst[0] == 0:
                    break
                if tempN < 26 and lst[tempN] > 0:
                    lst[tempN] -= 1
                tempN += 1
            count += tempN 
            lst.sort(reverse = True)
        return count
        print(count)       
        print(lst)
    
    
    
        
def main():
    test = Solution()
    test.leastInterval(["A","B","C","D","E","F","G"],2)

if __name__ == "__main__":
    main()
