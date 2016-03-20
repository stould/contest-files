import sys
sys.stdin = open("i.in", "r")
test = int(input())

while test > 0:
  n, m = map(int, input().split(" "))
  helper = {}

  for i in range(n):
    a = str(input())
    b = str(input())
    helper[a] = b
  for i in range(m):
    tmp = input().split(" ")
    for x in helper.keys():
      for y in range(len(tmp)):
        if x == tmp[y]:
          tmp[y] = helper[x]          
    s = ""
    for x in tmp:
      s += x + " "
    print(s[:-1])
  test -= 1
