dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

aux = input().split(" ")

n =int(aux[0])
m = int(aux[1])
ch = str(aux[2])

maze = [ [] for i in range(n) ]
mem = [ [] for i in range(n) ]

aux = set()

for i in range(n):
  maze[i].append(input())
  for j in range(m):
    mem[i].append(False)

for i in range(n):
  for j in range(m):
    if maze[i][j] == ch:
      pass
