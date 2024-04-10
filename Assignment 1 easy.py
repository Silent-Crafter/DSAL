table_size = 10
hash_table = []


def hash_function(key):
    return key % table_size


def insert(hash_table, key):
    hash_index = hash_function(key)
    hash_table[hash_index].append(key)


def display(hash_table):
    print("INDEX\tVALUE")
    for index, value in enumerate(hash_table):
        print(index, value, sep='\t\t')


def search(hash_table, key):
    hash_index = hash_function(key)
    bucket = hash_table[hash_index]
    if key in bucket:
        return hash_index

    return False


def delete(hash_table, key):
    hash_index = hash_function(key)
    return hash_table[hash_index].remove(key)


# Initialize HashTable with empty lists i.e. [[], [], []]
for i in range(table_size):
    hash_table.append([])

insert(hash_table, 123)
insert(hash_table, 456)
insert(hash_table, 789)
insert(hash_table, 786)
insert(hash_table, 999)
insert(hash_table, 232)
insert(hash_table, 459)
insert(hash_table, 2)

display(hash_table)

res = search(hash_table, 232)
print(f"Search Result for 232: {res}")

res = search(hash_table, 145)
print(f"Search Result for 145: {res}")

delete(hash_table, 999)
display(hash_table)
