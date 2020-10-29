prestupne = [y for y in range(1900, 1940) if (y % 4 == 0 and y % 100 != 0) or (y % 400 == 0)]
print(prestupne)

codes = []
for sex in "MF": #Male Female
    for size in "SMLX":
        if sex == "F" and size == "X":
            continue
        for color in "BGW":
            codes.append(sex + size + color)

print(codes)
#komprehenzia:
codes = [sex + size + color for sex in "MF" for size in "SMLX" for color in "BGW" if not (sex == "F" and size == "X")]
print(codes)
