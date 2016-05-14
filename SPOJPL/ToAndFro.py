while True:
  n = int(input())
  if n == 0:
    break
  s = str(input())
  ans = ""
  r = int(len(s) / n)
  for i in range(r):
    for j in range(1, n):
      if (i + 1) * j > len(s):
        break
      ans = ans + s[(i + 1) * j]
  print("%s", ans)
