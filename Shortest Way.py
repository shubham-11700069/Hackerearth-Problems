T=int(input())
def count(x,y):
    count = 0
    while x>0 and y>0:
        if x>y:
            count= count + x//y
            x %= y
        else:
            count = count+ y//x
            y %= x
    return (count-1)

for i in range(T):
    a,b=map(int,input().split())
    print(count(a,b))
        
    
