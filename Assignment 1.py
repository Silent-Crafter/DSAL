class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insertAtBegin(self, data):
        temp = Node(data)
        if not self.head:
            self.head = temp
            self.tail = self.head
            return

        temp.next = self.head
        self.head = temp

    def insertAtEnd(self, data):
        if not self.tail:
            self.tail = self.head = Node(data)
            return

        temp = Node(data)
        self.tail.next = temp
        self.tail = temp

    def search(self, data):
        temp = self.head
        if not temp: return False
        while temp.data != data:
            temp = temp.next
            if not temp:
                return None

        return temp.data

    def delete(self, data):
        temp = self.head
        prev = temp
        if not temp:
            return False
        while temp.data != data:
            prev = temp
            temp = temp.next
            if not temp:
                return False

        prev.next = temp.next
        del temp
        return True

    def __str__(self):
        out = []
        temp = self.head
        while temp:
            out.append(temp.data)
            temp = temp.next

        return str(out)


class TeleDir:
    def __init__(self, size):
        self.hash_table = [LinkedList() for _ in range(size)]
        self.size = 0
        self.max_size = size

    def insert(self, key: int):
        if self.size == self.max_size:
            print("Hash Table Full")
            return False

        hash_index = self.hash(key)

        bucket = self.hash_table[hash_index]
        bucket.insertAtBegin(key)

        self.size += 1
        return True

    def search(self, key: int):
        hash_index = self.hash(key)

        bucket = self.hash_table[hash_index]
        elem = bucket.search(key)
        if not elem:
            return None

        return hash_index

    def delete(self, key: int):
        hash_index = self.hash(key)
        bucket = self.hash_table[hash_index]
        if not bucket.delete(key):
            return False

        self.size -= 1
        return True

    def hash(self, key: int):
        return key % self.max_size

    def print(self):
        print("INDEX\tVALUE")
        for index, value in enumerate(self.hash_table):
            if value:
                print(index, value, sep='\t\t')


def main():
    directory = TeleDir(10)

    directory.insert(123)
    directory.insert(456)
    directory.insert(789)
    directory.insert(786)
    directory.insert(999)
    directory.insert(232)
    directory.insert(459)
    directory.insert(2)

    directory.print()
    print(f"Search Result for 232: {directory.search(232)}")
    print(f"Search Result for 145: {directory.search(145)}")
    directory.delete(999)

    directory.print()


if __name__ == '__main__':
    main()
