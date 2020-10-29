class Queue:
    def __init__(self):
        self.n = 1000001
        self.queue = [None]*self.n
        self.first_pointer = 0
        self.k = 0
    
    def put(self, item):
        if self.k < self.n:
            self.queue[(self.first_pointer + self.k) % self.n] = item
            self.k += 1

    def get(self):
        if self.k > 0:
            value = self.queue[self.first_pointer]
            self.first_pointer = (self.first_pointer + 1) % self.n
            self.k -= 1
            return value
        else:
            return False

    def view_first(self):
        return self.queue[0]


n = [int(i) for i in input().split(' ')][0]
data = []
for _ in range(n):
    inpt = [int(i) for i in input().split(' ')]
    data.append(inpt)

data.sort()

fronta = Queue()

for clovek in data:
    pass