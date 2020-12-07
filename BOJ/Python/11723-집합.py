import sys
class Set:
    def __init__(self):
        self.empty()
    def add(self, num):
        self.list[num-1] = True
    def remove(self, num):
        self.list[num-1] = False
    def check(self, num):
        if self.list[num-1]:
            sys.stdout.write('1\n')
        else:
            sys.stdout.write('0\n')
    def toggle(self, num):
        if self.list[num-1]:
            self.remove(num)
        else:
            self.add(num)
    def all(self):
        self.list = [True]*20
    def empty(self):
        self.list = [False]*20


a = Set()
for i in range(int(input())):
    cmd = sys.stdin.readline().split()
    if len(cmd) == 1:
        if cmd[0] == 'all':
            a.all()
        else:
            a.empty()
    else:
        b = int(cmd[1])
        if cmd[0] == 'add':
            a.add(b)
        elif cmd[0] == 'remove':
            a.remove(b)
        elif cmd[0] == 'toggle':
            a.toggle(b)
        else:
            a.check(b)
        