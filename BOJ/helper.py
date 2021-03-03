import requests
from bs4 import BeautifulSoup
import os

if __name__ == '__main__':
    language = input('무슨 언어? 0: c++, 1: python>>> ')
    problem = int(input("문제 번호? 숫자만 입력>>> "))
    url = f'https://www.acmicpc.net/problem/{problem}'
    req = requests.get(url)
    html = req.text
    soup = BeautifulSoup(html, 'html.parser')
    pTitle = soup.find(id="problem_title").text
    if language == '0':
        f = open(os.path.join(os.getcwd(), 'BOJ', 'C++', f'{problem}-{pTitle}.cpp'), 'w', encoding='utf8')
        f.write(
        """#include <cstdio>

int main() {
    return 0;
}""")
    elif language == '1':
        with open(os.path.join(os.getcwd(), 'BOJ', 'Python', f'{problem}-{pTitle}.py'), 'w', encoding='utf8') as f:
            f.write()