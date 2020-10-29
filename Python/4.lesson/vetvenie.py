count = 6
print("{0} subor{1}".format((count if count != 0 else 'ziadny'), 
	("y" if count in range(2,5) else ("" if count in range(0,2) else "ov"))))