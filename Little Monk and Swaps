def sortDict(dic):
    return sorted(dic.items(), key = lambda n: n[0])
 
 
def minSwaps(arr):
    
    n = len(arr)
    
    arrPos = dict()
    for i in range(n):
        arrPos[arr[i]] = i
        
    sarrPos = sortDict(arrPos)
    del arrPos
    
    vis = set()
    ans = 0
    
    for i in range(n):
        
        if(arr[i] in vis or sarrPos[i][1] == i):
            continue
        
        cycle_size = 0
        j = i
        
        while arr[j] not in vis:
            vis.add(arr[j])
            
            j = sarrPos[j][1]
            cycle_size += 1
            
        
        ans += (cycle_size - 1)
    
    return ans
 
 
def in_trav(A, i, T, n):
    if i < n:
        in_trav(A, 2 * i + 1, T, n)
        T.append(A[i])
        in_trav(A, 2 * i + 2, T, n)
    
 
A = list()
n = int(input())
 
string = input()
s = string.split()
 
for e in s:
    A.append(int(e))
 
del string, s
 
T = list()
in_trav(A, 0, T, n)
 
print(minSwaps(T))
