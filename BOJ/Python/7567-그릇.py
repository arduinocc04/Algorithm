a = input()
ans = 10
last = a[0]
for i in a[1:]:
    if i == last:
        ans += 5
    else: ans += 10
    last = i
print(ans)
