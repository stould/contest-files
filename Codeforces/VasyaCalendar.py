d = int(raw_input())
n = int(raw_input())

nums = map(int, raw_input().split(' '))

ans = 0

for i in range(0, len(nums) - 1):
    ans += (d - nums[i])

print("%d" % ans)
