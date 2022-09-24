n=int(input())
arr = list(map(int,input().split()))
res = []

pre = arr[0]
nxt = arr[1]
res.append(pre)
for i in range(1,n-1):
    res.append(nxt)
    if pre%2!=0 and nxt%2!=0:
        avg = (pre+nxt)//2
        res.append(avg)
    
    # res.append(avg)
    pre = arr[i]
    nxt = arr[i+1]
print(res)