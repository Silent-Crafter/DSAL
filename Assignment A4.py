# class Set:
#     def __init__(self):
#         self.data = {}
#
#     def add(self, element):
#         if self.contains(element):
#             print("Error: Element already exists in the set.")
#             return
#
#         self.data[hash(element)] = element
#
#     def remove(self, element):
#         hash_value = hash(element)
#         if hash_value not in self.data:
#             print("Error: Element does not exist in the set.")
#             return
#
#         del self.data[hash_value]
#
#     def contains(self, element):
#         return hash(element) in self.data
#
#     def size(self):
#         return len(self.data)
#
#     def intersect(self, other):
#         result = Set()
#         for key in self.data:
#             if self.contains(other.data.get(key, None)):
#                 result.add(self.data[key])
#         return result
#
#     def union(self, other):
#         result = Set()
#         for key in self.data:
#             print(self.data[key])
#             result.add(key)
#
#         for key in other.data:
#             if key not in result:
#                 result.add(other.data[key])
#         return result
#
#     def difference(self, other):
#         result = Set()
#         for key in self.data:
#             if not other.contains(self.data[key]):
#                 result.add(self.data[key])
#         return result
#
#     def subset(self, other):
#         return all(self.contains(item) for item in other.data)
#
#     def __contains__(self, item):
#         return hash(item) in self.data
#
#     def __iter__(self):
#         return iter(self.data.values())
#
#     def __str__(self):
#         return str([str(i) for i in self])
#
#
# if __name__ == "__main__":
#     set1 = Set()
#     set1.add(1)
#     set1.add(2)
#     set1.add("Hello")
#
#     print("Set 1: ", set1)
#     print("Is Hello in Set 1? ", set1.contains("Hello"))
#
#     set2 = Set()
#     set2.add(2)
#     set2.add(3)
#
#     print("Set 2: ", set2)
#
#     print("Intersection of Set 1 and Set 2: ", set1.intersect(set2))
#
#     set3 = set1.union(set2)
#     print("Union of Set 1 and Set 2: ", set3)
#
#     set4 = set1.difference(set2)
#     print("Difference between Set 1 and Set 2: ", set4)
#
#     set5 = Set()
#     set5.add(1)
#     set5.add(2)
#
#     print("Set 5: ", set5)
#
#     print("Is Set 5 a subset of Set 1? ", set1.subset(set5)) # returns False

class Set:
    def __init__(self):
        self.data = []

    def add(self, item):
        if item not in self.data:
            self.data.append(item)

    def remove(self, item):
        if item in self.data:
            self.data.remove(item)

    def contains(self, item):
        return item in self.data

    def union(self, other_set):
        result = self
        for item in other_set:
            if item not in result:
                result.add(item)
        return result

    def intersect(self, other_set):
        result = Set()
        for item in self:
            if item in other_set:
                result.add(item)

        return result

    def difference(self, other_set):
        result = Set()
        for item in self:
            if item not in other_set:
                result.add(item)
        return result

    def subset(self, other_set):
        return all(item in self for item in other_set)

    def size(self):
        return len(self.data)

    def __iter__(self):
        return iter(self.data)

    def __contains__(self, item):
        return item in self.data

    def __str__(self):
        return str(self.data)


if __name__ == "__main__":
    set1 = Set()
    set1.add(1)
    set1.add(2)
    set1.add("Hello")

    print("Set 1: ", set1)
    print("Is Hello in Set 1? ", set1.contains("Hello"))

    set2 = Set()
    set2.add(2)
    set2.add(3)

    print("Set 2: ", set2)

    print("Intersection of Set 1 and Set 2: ", set1.intersect(set2))

    set3 = set1.union(set2)
    print("Union of Set 1 and Set 2: ", set3)

    set4 = set1.difference(set2)
    print("Difference between Set 1 and Set 2: ", set4)

    set5 = Set()
    set5.add(1)
    set5.add(2)

    print("Set 5: ", set5)

    print("Is Set 5 a subset of Set 1? ", set1.subset(set5))
