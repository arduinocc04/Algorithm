import math, decimal
a,b,c = map(int, input().split())
#헤론의 공식 이용해서 넓이 구함
#헤론 공식은 인터넷에서 찾음
tmp = a**2 + b**2 - c**2
tmp2 = decimal.Decimal(math.sqrt(1-(decimal.Decimal(tmp/(2*a*b))**2)))
S = decimal.Decimal((a*b*tmp2)/2)
#학교에서 배운거 이용
r = decimal.Decimal((2*S)/(a+b+c))
#헤론 공식 검색한 글에 같이 있었음
R = decimal.Decimal((a*b*c)/(4*S))
# 외심과 내심은 사랑입니다에서 배웠음
if a== b== c:
    d = 0
else:
    d = decimal.Decimal(math.sqrt(R**2 - 2*r*R))
#쭉 잘가다가 k에서 막힘
#지오지브라로 돌려보다가, 삼각형의 한변과, i, j, k 연장한것 방멱 정리 이용. 
def calc(n):
    return decimal.Decimal(math.sqrt(decimal.Decimal(R**2) - decimal.Decimal((n**2)/4)))
k = calc(a) + calc(b) + calc(c)
print(S)
print(R)
print(r)
print(d)
print(k)