class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)

        if self.table[index] is None:
            self.table[index] = (key, value)
        else:
            while self.table[index] is not None:
                index = (index + 1) % self.size
            self.table[index] = (key, value)

    def lookup(self, key):
        index = self.hash_function(key)
        count = 0
        while self.table[index] is not None:
            if self.table[index][0] == key:
                return self.table[index][1]
            index = (index + 1) % self.size
            count += 1
            if count == self.size:
                break
        return None

    def delete(self, key):
        index = self.hash_function(key)
        count = 0
        while self.table[index] is not None:
            if self.table[index][0] == key:
                self.table[index] = None
            
            index = (index + 1) % self.size
            count += 1
            
            if count == self.size:
                break


def main():
    size = int(input("Enter number of clients: "))
    obj = HashTable(size)



    while True:
        print("\n1. Insert record \n2. Search record.\n3.Delete record")
        ch = int(input("Enter choice: "))    
        
        if ch == 1:
            key = int(input("Enter phno.: "))
            value = input("Enter name: ")
            obj.insert(key, value)

        elif ch == 2:
            key = int(input("Enter phone number: "))
            print(obj.lookup(key))

        elif ch == 3: 
            key = int(input("Enter phone number: "))
            obj.delete(key)

        elif ch == 0:
            exit()

        else:
            print("Invalid input")


main()