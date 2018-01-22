import sys

class lucky:
  def __init__(self):
    self.luckyList = []
    notLucky = [0, 1, 2, 3, 5, 6, 8, 9]
    n = 1;
    while(n <= 1000):
      self.luckyList.append(n)
      for badluck in notLucky:
        if str(badluck) in str(n):
          self.luckyList.pop()
          break
      n += 1

  def checkMod(self,num):
    for lucky in self.luckyList:
      if num % lucky == 0:
        return True
    return False
      
  def printLucky(self):
    print self.luckyList

def main():
  luuuuk = lucky()
  num = int(sys.stdin.readline().strip())
  if luuuuk.checkMod(num) :
    print "YES"
  else:
    print "NO"
    
if __name__ == ("__main__"):
  main()
