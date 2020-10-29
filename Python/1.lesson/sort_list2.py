def sort(num):
    if not isinstance(num, list):
        print('data are not in list!')
        return False
    if not num:
        print('data are empty!')
        return False
    ret = [num[0]]
    i = 1
    while i < len(num):
        n = 0
        while n < len(ret):
            print(ret[n], n)
            if num[i] <= ret[n]:
                o = 0
                while o < len(ret):
                    
                    o += 1
                    
            n += 1
        i += 1

sort([50, 40, 100, 45, 10])
