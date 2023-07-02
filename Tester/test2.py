T=int(input())
 
for j in range(T):
  _str= input()
  signal=[int(n) for n in _str]
  signal.insert(0,1)
  for i in range(len(signal)-2):
    if signal[i]==1 and signal[i+1]==0 and signal[i+2]==1:
      signal[i+1] =2
      signal[i+2] =2
  signal.pop(0)
  signal.insert(0,2)
  signal.append(2)
  start=[]
  end=[]
  final=[]
  for i in range(len(signal)-1):
    if signal[i]==2 and signal[i+1]==1:
      start.append(i)
    if signal[i]==1 and signal[i+1]==2:
      end.append(i)
  for i , j in zip(start,end):
    lis=signal[i+1:j+1]
    v=lis.count(0)
    
    if sum([i for i, value in enumerate(lis) if value == 0])==int(v*(v+1)/2) and lis.count(0)>=2:
      final.append(1)
    else:
      final.append(0)
  
  if any(i==0 for i in final):
    print("NO")
  else:
    print('YES')