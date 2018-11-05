class Stack:
    def __init__(self):
        self.__stackSize = 0
        self.__table = [0] * 1

    def __resize_table(self):
        self.__table = self.__table + [0] * len(self.__table)

    def insert(self, elem):
        if self.__stackSize == len(self.__table):
            self.__resize_table()
        self.__table[self.__stackSize] = elem
        self.__stackSize += 1

    def pop(self):
        if self.__stackSize == 0:
            raise Exception('Stack is empty and you want to pop something from it!')
        self.__stackSize -= 1
        return self.__table[self.__stackSize]

    def __str__(self) -> str:
        temp = "[" + "".join([str(item) + ", " for item in self.__table]) + "]"
        return temp


stack = Stack()
stack.insert(1)
print(stack)
stack.insert(2)
print(stack)
stack.pop()
stack.insert(3)
print(stack)
