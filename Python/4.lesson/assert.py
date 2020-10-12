def product(*args):
	result = 1
	for x in args:
		result *= x
	assert result, "Nulovy argument"
	return result

print(product(10,2,15,30,0,4))