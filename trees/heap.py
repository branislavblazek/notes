class Heap:
    def __init__(self):
        self.heap = []

    def push_back(self, value):
        self.heap.append(value)
        where_now = len(self.heap) - 1
        while where_now > 0:
            parent = (where_now - 1) // 2
            if self.heap[where_now] > self.heap[parent]:
                self.heap[parent], self.heap[where_now] = self.heap[where_now], self.heap[parent]
                where_now = parent
            else:
                break

    def min(self):
        return self.heap[0]

    def extract_max(self):
        n = len(self.heap)

        if n > 1:
            maximum = self.heap[0]
            self.heap[0] = self.heap.pop()
        elif n == 1:
            maximum = self.heap[0]
            self.heap.pop()
        else:
            return

        where_now = 0
        while True:
            destiantion = where_now
            if 2*where_now+1 < n-1 and self.heap[2*where_now+1] > self.heap[destiantion]:
                destiantion = 2*where_now+1
            if 2*where_now+2 < n-1 and self.heap[2*where_now+2] > self.heap[destiantion]:
                destiantion = 2*where_now+2
            
            if where_now != destiantion:
                self.heap[where_now], self.heap[destiantion] = self.heap[destiantion], self.heap[where_now]
                where_now = destiantion
            else:
                return maximum