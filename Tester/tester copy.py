import os
import subprocess
import time
import random
program1 = os.path.join(os.getcwd(), 'Tester', 'test')
program2 = os.path.join(os.getcwd(), 'Tester', 'test2.py')
dir_ = os.path.join(os.getcwd(), 'Tester', 'data')
tInputs = os.listdir(os.path.join(os.getcwd(), 'Tester', 'data'))
res = open(os.path.join(os.getcwd(), 'Tester', 'err.txt'), 'w', encoding='utf8')
asdf = [i for i in range(1, 10)]
a = ['0', '1']
for i in range(100):
    f = open(os.path.join(os.getcwd(), 'Tester', 'data', f'{i}.in'), 'w', encoding='utf8')
    with open(os.path.join(os.path.dirname(__file__), 'data', f'{i}.in'), 'w') as f:
        f.write("200\n")
        for i in range(200):
            resas = '1'
            for j in range(199):
                resas += random.choice(a)
            f.write(resas + "\n")
TIMELIMIT = 26
for i in tInputs:
    if i.endswith('.in'):
        startTime = time.time()
        # os.system(program1 + f' < {i} > ' + os.path.join(os.getcwd(), 'Tester', 'result.txt'))
        inputf = open(os.path.join(dir_, i), 'r')
        with open(os.path.join(os.getcwd(), 'Tester', 'result1.txt'), 'w') as f:
            subprocess.call(program1, stdin=inputf, stdout=f, shell=True)
        inputf.close()
        inputf = open(os.path.join(dir_, i), 'r')
        with open(os.path.join(os.getcwd(), 'Tester', 'result2.txt'), 'w') as g:
            subprocess.call(['python', program2], stdin=inputf, stdout=g, shell=True)
        inputf.close()
        with open(os.path.join(os.getcwd(), 'Tester', 'result1.txt'), 'r') as f:
            with open(os.path.join(os.getcwd(), 'Tester', 'result2.txt'), 'r') as g:
                a,b = g.readline().rstrip(), f.readline().rstrip()
                tmp = i.split('.')[0]
                if a != b:
                    res.write(f'WA: {tmp} / expect: {b} ans: {a}\n')
                if time.time() - startTime > TIMELIMIT:
                    res.write(f'TLE: {tmp}\n')
                print(f'test: {i} time:{time.time() - startTime}ms, ans={a} expect={b}')
res.close()