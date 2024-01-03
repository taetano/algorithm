input = input()
arr = [-1] * (ord('z') - ord('a') + 1)

index = 0;
for ch in input:
    pos = ord(ch) - ord('a')
    if arr[pos] == -1:
        arr[pos] = index

    index = index + 1;
    
for each in arr:
    print(each, end = " ")
    