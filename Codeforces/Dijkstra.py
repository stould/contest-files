n, m = map(int, raw_input('').split(' '))

dist = [ 1000001 for i in range(1000000) ]
prev = [ -1 for i in range(1000000) ]
memo = [ False for i in range(1000000) ]
maze = [1000001] * 1000001

for i in range(100000):
  maze[i] = [1000001] * 1000001

for i in range(m):
  a, b, c = map(int, raw_input('').split(' '))
  a -= 1
  b -= 1
  
dist[0] = 0

while(True):
  start = -1
  for i in range(n):
    if not memo[i] and (start == -1 or dist[start] > dist[i]):
      start = i
  if start == -1:
    break
  
  memo[start] = True
  
  for i in range(n):
    tmp = dist[start] + maze[start][i]
    if tmp < dist[i]:
      dist[i] = tmp
      prev[i] = start

end = n - 1
path = []
while prev[end] != -1:
  path.append(prev[end])
  end = prev[end]
  
for i in range(len(path)):
  if i == len(path) - 1:
    print('%d\n' %(path[i]))
  else:
    print('%d ' % (path[i]))
    