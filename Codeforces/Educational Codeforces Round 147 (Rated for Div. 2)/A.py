import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    s = input().rstrip()
    qmark_cnt = 0
    for c in s:
        if c == '?': qmark_cnt += 1
    
    lead_qmark_cnt = 0
    while lead_qmark_cnt < len(s) and s[lead_qmark_cnt] == '?': lead_qmark_cnt += 1

    if s[0] == '0':
        sys.stdout.write("0\n")
        continue

    if qmark_cnt == 0:
        tmp = 0
    else:
        tmp = 10**qmark_cnt
        for i in range(1, lead_qmark_cnt+1):
            tmp -= 9**(lead_qmark_cnt - i)*10**(qmark_cnt - lead_qmark_cnt)
    if tmp == 0: tmp = 1
    sys.stdout.write(str(tmp) + "\n")