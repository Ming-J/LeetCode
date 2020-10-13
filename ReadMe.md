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
