import os
import subprocess
import time
import random
program1 = os.path.join(os.getcwd(), 'Tester', 'test1.exe')
program2 = os.path.join(os.getcwd(), 'Tester', 'test2.py')
dir_ = os.path.join(os.getcwd(), 'Tester', 'data')
for i in range(2, 100):
    with open(os.path.join(dir_, f'{i}.in'), 'w') as f:
        f.write(str(i) + '\n')
        for j in range(i):
            tmp = random.choice('IN')
            f.write(f'{random.randint(-250, 250)} {random.randint(-250, 250)} {tmp}\n')
tInputs = os.listdir(os.path.join(os.getcwd(), 'Tester', 'data'))
res = open(os.path.join(os.getcwd(), 'Tester', 'err.txt'), 'w', encoding='utf8')
TIMELIMIT = 26
for i in tInputs:
    if i.endswith('.in'):
        startTime = time.time()
        #os.system(program + f' < {i} > ' + os.path.join(os.getcwd(), 'Tester', 'result.txt'))
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