class TextEditor:
    def __init__(self):
        self.text = ""
        self.outputs = []

    def append(self, W):
        self.text = self.text + W
    
    def delete(self, k):
        self.text = self.text[0:len(self.text) - k]
    
    def print(self, k):
        k = k - 1
        self.outputs.append(self.text[k:k+1])

    def printOutput(self):
        for x in self.outputs:
            print(x)

n = int(input())
textEditor = TextEditor()
memory = []
for i in range(n):
    s = input()
    case = int(s[0:1])
    if case == 1:
        W = s[2:len(s)]
        s = "2 " + str(len(W))
        memory.append(s)
        textEditor.append(W)
    if case == 2:
        k = int(s[2:len(s)])
        s = "1 " + textEditor.text[len(textEditor.text) - k: len(textEditor.text)]
        memory.append(s)
        textEditor.delete(k)
    if case == 3:
        k = int(s[2:len(s)])
        textEditor.print(k)
    if case == 4:
        s = memory.pop()
        case = int(s[0:1])
        if case == 1:
            W = s[2:len(s)]
            textEditor.append(W)
        if case == 2:
            k = int(s[2:len(s)])
            textEditor.delete(k)
textEditor.printOutput()

