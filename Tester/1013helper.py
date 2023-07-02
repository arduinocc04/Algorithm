import os
import random

a = ['0', '1']
with open(os.path.join(os.path.dirname(__file__), 'data', '1.in'), 'w') as f:
    f.write("200\n")
    for i in range(200):
        res = ''
        for j in range(200):
            res += random.choice(a)
        f.write(res + "\n")