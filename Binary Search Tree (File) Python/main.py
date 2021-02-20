# Binary Search Tree / main.py
# Created on: 09-Sept-2018
# Author: Gourav Siddhad

from bst import BST


def main():
    tree = BST()
    tree.read_File('input.txt')
    tree.print_tree()
    tree.delete(19)
    print('')
    tree.print_tree()

#     Search

#     if tree.lookup(values[v]) is None:
#         print(str(values[v]) + ' Not Found', end=' ')
#     else:
#         print(str(values[v]) + ' Found', end=' ')


if __name__ == "__main__":
    main()
