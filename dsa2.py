class HashFunction:
    def __init__(self):
        self.h = [{'key': -1, 'name': 'NULL'} for i in range(10)]

    def insert(self):
        cnt = 0
        flag = 0
        while True:
            if cnt >= 10:
                print("\n\tHash Table is FULL")
                break
            k = int(input("\n\tEnter a Telephone No: "))
            n = input("\n\tEnter a Client Name: ")
            hi = k % 10  # hash function
            if self.h[hi]['key'] == -1:
                self.h[hi]['key'] = k
                self.h[hi]['name'] = n
            else:
                if self.h[hi]['key'] % 10 != hi:
                    temp = self.h[hi]['key']
                    ntemp = self.h[hi]['name']
                    self.h[hi]['key'] = k
                    self.h[hi]['name'] = n
                    for i in range(hi + 1, 10):
                        if self.h[i]['key'] == -1:
                            self.h[i]['key'] = temp
                            self.h[i]['name'] = ntemp
                            flag = 1
                            break
                    for i in range(hi):
                        if self.h[i]['key'] == -1:
                            self.h[i]['key'] = temp
                            self.h[i]['name'] = ntemp
                            break
                else:
                    for i in range(hi + 1, 10):
                        if self.h[i]['key'] == -1:
                            self.h[i]['key'] = k
                            self.h[i]['name'] = n
                            flag = 1
                            break
                    for i in range(hi):
                        if self.h[i]['key'] == -1:
                            self.h[i]['key'] = k
                            self.h[i]['name'] = n
                            break
            flag = 0
            cnt += 1
            ans = input("\n\t..... Do You Want to Insert More Key: y/n")
            if ans.lower() == 'n':
                break

    def display(self):
        print("\n\t\tKey\t\tName")
        for i in range(10):
            print(f"\n\th[{i}]\t{self.h[i]['key']}\t\t{self.h[i]['name']}")

    def find(self, k):
        for i in range(10):
            if self.h[i]['key'] == k:
                print(f"\n\t{self.h[i]['key']} is Found at {i} Location With Name {self.h[i]['name']}")
                return i
        else:
            return -1

    def Delete(self, k):
        index = self.find(k)
        if index == -1:
            print("\n\tKey Not Found")
        else:
            self.h[index]['key'] = -1
            self.h[index]['name'] = "NULL"
            print("\n\tKey is Deleted")

if __name__ == "__main__":
    obj = HashFunction()
    while True:
        print("\n\t***** Telephone (ADT) *****")
        print("\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit")
        ch = int(input("\n\t..... Enter Your Choice: "))
        if ch == 1:
            obj.insert()
        elif ch == 2:
            obj.display()
        elif ch == 3:
            k = int(input("\n\tEnter here:"))
            if obj.find(k)==-1:
                print("not found")
        elif ch==4:
            k=int(input("\n\tEnter here"))
            obj.Delete(k)
            print("Deleted")
        elif choice == 5:
            break
        else:
            print("\nInvalid choice, please try again.")








