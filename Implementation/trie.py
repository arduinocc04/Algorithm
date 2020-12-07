TRIE_CHILD_CNT = 26
class Trie: #영어 대문자를 위함.
    def __init__(self, isEnd=False):
        self.childs = [None]*TRIE_CHILD_CNT
        self.isEnd = isEnd
    
    def addWord(self, word):
        a = ord(word[0]) - 65
        if self.childs[a]:
            i = 1
            nd = self.childs[a]
            while i < len(word) and nd.childs[ord(word[i])-65]:
                i += 1
                nd = nd.childs[ord(word[i])-65]
            if not i == len(word) - 1:
                for j in range(i, len(word), 1):
                    nd.childs[ord(word[j])-65] = Trie()
                    nd = nd.childs[ord(word[j])-65]
                nd.isEnd = True
            else:
                nd.isEnd = True
        else:
            self.childs[a] = Trie()
            nd = self.childs[a]
            for c in word:
                nd.childs[ord(c)-65] = Trie()
                nd = nd.childs[ord(c)-65]
            nd.isEnd = True
    
    def checkWordIn(self, word):
        a = ord(word[0]) - 65
        i = 1
        nd = self.childs[a]
        while nd:
            if len(word) -1 == i and nd.isEnd:  return True
            if i > len(word)-1:  break
            nd = nd.childs[ord(word[i])-65]
        return False
    
    def travel(self, res=''):
        if self.isEnd:  print(res)
        if self.childs.count(None) == TRIE_CHILD_CNT:  return
        for i in range(len(self.childs)):
            if self.childs[i]:
                nd = self.childs[i]
                nd.travel(res + chr(i+65))


if __name__ == '__main__':
    trie = Trie()
    trie.addWord('HI')
    trie.addWord('HOHO')
    trie.travel()