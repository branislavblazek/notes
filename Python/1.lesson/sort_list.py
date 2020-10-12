def sortIt(num):
    numbers = num
    indexes = []
    indx = 0
    while indx < len(numbers):
        indexes.append(indx)
        indx += 1
    for n in indexes:#aby kod nekoncil 13,12,16 prebehni to cele
        for i in indexes:
            if i + 1 == len(numbers):
                break
            if numbers[i] > numbers[i+1]:
                numbers[i], numbers[i+1] = numbers[i+1], numbers[i]
                indexes = []
                indx = 0
                while indx < len(numbers):
                    indexes.append(indx)
                    indx += 1
    return numbers
print(sortIt([50, 40, 100, 45, 10]))



    
        
    
        
        
        
    
