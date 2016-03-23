def bsearch(ls, search):
  low = 0
  high = len(ls)

  while low < high:
    mid = int((low + high) / 2)
    if ls[mid] == search:
      return True
    elif ls[mid] < search:
      low = mid + 1
    else:
      high = mid
  return False

n  = int(input())

memo = []

for i in range(2, 100, 2):
  memo.append(i)

ok = False

for i in range(2, 100, 2): 
  if bsearch(memo,n - i) == True:
    ok = True
    break
if ok:
  print("YES")
else:
  print("NO")
