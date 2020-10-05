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
dfs
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

