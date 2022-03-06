<h1>Binary Search</h1>

```
Left-mid:
  mid = lo + (hi-lo) / 2
  lo = mid + 1
  hi = mid
Right-mid
  mid = lo + (hi - lo + 1) / 2
  lo = mid
  hi = mid - 1
```
<h1>Detecting Cycle</h1>

dfs way of checking

```python
def dfs( node ):
  # node are in our current path, cycle detected
  if visited[node] == 2: return False
  # node have been previous passed, it's okay to visit
  if visited[node] == 1: Return True
  visited[node] = 2 # Mark Node to currently visiting
  for next in connected[node]:
    if not dfs(next):
      return False
  visited[node] = 1 # Mark Node to been visited
  return True

```

<h1>BitMask</h1>


```python
#Same as getting all permutation of N value
for mask in range(1 << N):
  print(mask, bin(mask))

#Going through the Binary and see which index is in our creent permutation
for x in range(N):
  print("\t", ((mask >> x) & 1))
```

<h1>Binary Index Tree</h1>

```python
class bit():
  def __init__(self):
    self.size = (10**5) + 1
    self.arr = [0] * self.size
  def prefix_sum(self, idx):
    res = 0
    while idx > 0:
      res += self.arr[idx]
      idx -= idx & -idx
    return res
  def increase(self, idx, delta):
    while idx <= self.size:
      self.arr[idx] += delta
      idx += idx & -idx
  def range_sum(self, l, r): 
    return self.prefix_sum(r) - self.prefix_sum(l - 1);
```

<hi>KMP</h1>
```python
def strStr(self, haystack: str, needle: str) -> int:
    if needle == "": return 0
    if haystack == "": return -1
    suffix = self.suffix_array(needle, len(needle))
    kmp = [0] * len(haystack)
    kmp[0] = 1 if haystack[0] == needle[0] else 0
    if len(needle) == 1 and kmp[0] == 1:
        return 0
    for i in range(1,len(haystack)):
        j = kmp[i-1]
        while j > 0 and haystack[i] != needle[j]:
            j = suffix[j-1]
        if haystack[i] == needle[j]:
            kmp[i] = j + 1
        if kmp[i] == len(needle):
            return i - len(needle) + 1
    return -1

# The maximum length k so that p[0:k-1] = p [p-k+1:i]
# https://github.com/wisdompeak/LeetCode/tree/master/String/1392.Longest-Happy-Prefix
# https://github.com/wisdompeak/LeetCode/tree/master/String/028.Implement-strStr
def suffix_array(self, needle, size):
    suffix = [0] * size
    for i in range(1, size):
        j = suffix[i-1]
        while j > 0 and needle[i] != needle[j]:
            j = suffix[j-1]
        if needle[i] == needle[j]:
            suffix[i] = j + 1
    return suffix        
```
