import os
import subprocess
import time
import platform

program = os.path.join(os.path.dirname(__file__), 'test' if platform.system == 'Linux' else 'test.exe')
print(os.getcwd())
tInputs = os.listdir(os.path.join(os.path.dirname(__file__), 'data'))
dir_ = os.path.join(os.path.dirname(__file__), 'data')
res = open(os.path.join(os.path.dirname(__file__), 'err.txt'), 'w', encoding='utf8')
TIMELIMIT = 1
for i in tInputs:
    if i.endswith('.in'):
        startTime = time.time()
        #os.system(program + f' < {i} > ' + os.path.join(os.path.dirname(__file__), 'result.txt'))
        with open(os.path.join(os.path.dirname(__file__), 'result.txt'), 'w') as f:
            subprocess.call(program + f' < {os.path.join(dir_, i)} ', stdout=f, shell=True)
        with open(os.path.join(dir_, i.split('.')[0] + '.out'), 'r') as f:
            with open(os.path.join(os.path.dirname(__file__), 'result.txt'), 'r') as w:
                a,b = w.readline().rstrip(), f.readline().rstrip()
                tmp = i.split('.')[0]
                if a != b:
                    res.write(f'WA: {tmp} / expect: {b} ans: {a}\n')
                if time.time() - startTime > TIMELIMIT:
                    res.write(f'TLE: {tmp}\n')
                print(f'test: {i} time:{time.time() - startTime}ms, ans={a}')
res.close()