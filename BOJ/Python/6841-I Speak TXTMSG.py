import sys    

A = ["CU",  ":-)",  ":-(", ";-)", ":-P",  "(~.~)",  "TA",  "CCC",  "CUZ", "TY", "YW", "TTYL"]
B = ["see you", "I’m happy",  "I’m unhappy", "wink", "stick out my tongue", "sleepy", "totally awesome", "Canadian Computing Competition", "because", "thank-you", "you’re welcome", "talk to you later"]

while True:
    N = sys.stdin.readline().rstrip()
    if N in A : 
        print(B[A.index(N)])
    else : 
        print(N)
    if N == "TTYL": 
        break
