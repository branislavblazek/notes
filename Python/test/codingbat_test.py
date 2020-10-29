def count_code(str):
    count = 0
    for i in range(len(str[:-3])):
        if str[i:i+3] == 'co' and str[i+3] == 'e':
            count += 1
    print(count)

count_code('codexxcode')
