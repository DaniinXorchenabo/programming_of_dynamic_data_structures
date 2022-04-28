from random import randint

class TreeOfBinarySearch(object):


    def __init__(self):
        self.arr = dict()

    def add(self, new_item):
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
            self.arr[index] = new_item
            return
        while current_item != it:
            index = index * 2 + int(new_item > current_item)
            if index not in self.arr:
                arr[index] = new_item
                return None
            current_item = self.arr[index]
        return index
    
    def print(self, int_size=8, blanks=1) -> None:
        a = {k: v for k, v in self.arr.items()}
        # print(a)
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
        while counter <= len(a):
            printed_arr = {i + 1: (a[i + 1] if (i + 1) in a else "") for i in range(last_ind, 2 * last_ind + 1)}
            counter += len([i for i in printed_arr if i != ""])
            deep += 1
            _counter *= 2
            last_ind = 2 * last_ind + 1
        
        # a.extend([""] * (_counter - len(a) + 1))
        print("=" * (2 + int_size * _counter + 2 * blanks * _counter))
        last_ind = 0
        counter = 0
        while counter <= len(a):
            printed_arr = {i+1: (a[i+1] if (i+1) in a else "") for i in range(last_ind, 2 * last_ind + 1)}
            counter += len([i for i in printed_arr if i != ""])
            print(design_one_line(printed_arr, _counter))
            print("|" + " " * (int_size * _counter + 2 * blanks * _counter) + "|")
            last_ind = 2 * last_ind + 1
        print("=" * (2 + int_size * _counter + 2 * blanks * _counter))


if __name__ == '__main__':
    tree = TreeOfBinarySearch()
    [tree.add(randint(0, 100)) for i in range(10)]
    tree.print()