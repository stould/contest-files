teste = 1
while true do
	n = tonumber(io.read())
	if n == -1 then
		break
	else
		print("Teste " .. teste .. "\n" .. (1 + 2^n)*(1 + 2^n))
		teste = teste + 1
	end
end
