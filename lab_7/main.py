from random import randint, shuffle
from typing import Callable
from itertools import islice, chain

class TreeOfBinarySearch(object):


    def __init__(self, item_count: int | None = None, check_func=lambda i: True):

        def gen():
            i = 0
            yield i
            while True:
                data = [j*k for j in range(i, i+10) for k in [1, -1]]
                shuffle(data)
                for j in data:
                    yield j
                i += 10


        self.arr = dict()
        self.check_func = check_func
        if item_count is not None:
            list(islice((self.add(i) for i in gen() if self.check_func(i)), item_count))

    def add(self, new_item):
        if self.check_func(new_item) is False:
            return
        index = 1
        try:
            current_item = self.arr[index]
        except KeyError as e:
            self.arr[index] = new_item
            return
        while True:
            index = index * 2 + int(new_item > current_item)
            if index not in self.arr:
                self.arr[index] = new_item
                break
            current_item = self.arr[index]
        # tree.print()

    def search(self, it):
        index = 1
        try:
            current_item = self.arr[index]
        except KeyError as e:
            return None
        while current_item != it:
            index = index * 2 + int(it > current_item)
            if index not in self.arr:
                self.arr[index] = it
                return None
            current_item = self.arr[index]
        return index
    
    def print(self, int_size=8, blanks=1) -> None:
        a = {k: v for k, v in self.arr.items()}

        def design_one_line(part_a: dict[int, int], _counter) -> str:
            emmitator = " " * blanks + " " * int_size + " " * blanks
            part_a: list = [blanks * " " + (str(i) + " " + "[" + str(ind) + "]").center(int_size, " ") + " " * blanks for ind, i in part_a.items()]
            is_digit = _counter // len(part_a)
            part_a = [(part_a[i // is_digit] if i % is_digit == is_digit // 2 else emmitator) for i in range(_counter)]
            return "|" + "".join(part_a) + "|"

        last_ind = 0
        deep = 1
        _counter = 1
        counter = 0
        while counter < len(a):
            printed_arr = {i + 1: (a[i + 1] if (i + 1) in a else "") for i in range(last_ind, 2 * last_ind + 1)}
            counter += len([i for ind , i in printed_arr.items() if i != ""])
            deep += 1
            _counter *= 2
            last_ind = 2 * last_ind + 1

        print("=" * (2 + int_size * _counter + 2 * blanks * _counter))
        last_ind = 0
        counter = 0
        while counter < len(a):
            printed_arr = {i+1: (a[i+1] if (i+1) in a else "") for i in range(last_ind, 2 * last_ind + 1)}
            counter += len([i for ind, i in printed_arr.items() if i != ""])
            print(design_one_line(printed_arr, _counter))
            print("|" + " " * (int_size * _counter + 2 * blanks * _counter) + "|")
            last_ind = 2 * last_ind + 1
        print("=" * (2 + int_size * _counter + 2 * blanks * _counter))

    def is_empty(self):
        return not bool(self.arr )

    def from_up_to_down(self):

        def recursion(index, data = []):
            if index in self.arr:
                data.append(self.arr[index])
                recursion(2 * index)
                recursion(2 * index + 1)
            return data

        return recursion(1)

    def from_left_to_right(self):

        def find_left(index):
            new_index = index * 2
            if new_index not in self.arr:
                return index
            return find_left(new_index)

        def recursion(last_index, index, data = []):
            if index in self.arr:
                data.append(self.arr[index])
                if last_index < index:
                    recursion(index, 2 * index)
                recursion(index, 2 * index + 1)
                if last_index > index:
                    recursion(index, index//2)

            return data

        return recursion(float('inf'), find_left(1))

    def from_down_to_up(self):

        def find_left(index):
            new_index = index * 2
            if new_index not in self.arr:
                return index
            return find_left(new_index)

        def recursion(last_index, index, data = []):
            if index in self.arr:
                if last_index < index:
                    recursion(index, 2 * index)
                recursion(index, 2 * index + 1)
                data.append(self.arr[index])
                if last_index > index:
                    recursion(index, index//2)

            return data

        return recursion(float('inf'), find_left(1))

    def delete(self):

        def find_left(index):
            new_index = index * 2
            if new_index not in self.arr:
                return index
            return find_left(new_index)

        def recursion(last_index, index, data=[]):
            if index in self.arr:
                if last_index < index:
                    recursion(index, 2 * index)
                recursion(index, 2 * index + 1)
                data.append(self.arr[index])
                self.arr.pop(index)
                if last_index > index:
                    recursion(index, index // 2)

            return data

        return recursion(float('inf'), find_left(1))






if __name__ == '__main__':
    tree = TreeOfBinarySearch(item_count=10)
    tree.print()
    print(tree.from_up_to_down())
    print(tree.from_left_to_right())
    print(tree.from_down_to_up())
    print(tree.delete())
    print(tree.is_empty())