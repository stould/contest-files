local N = io.read()

local cnt = {}
local ans = 0
local su  = 0

for i = 1, N do
   C = io.read()

   if cnt[C] == nil then
	  cnt[C] = 1
   else
	  cnt[C] = cnt[C] + 1
   end

   if cnt[C] > su then
	  su = cnt[C]
	  ans = C
   end
end

print(ans)
