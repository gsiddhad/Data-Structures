# B Plus Tree / main.py
# Created on: 07-Nov-2018
# Author: Gourav Siddhad

from bptree import BPTree


def main():
    tree = BPTree()
    tree.read_File('input.txt')
    print(tree)


if __name__ == "__main__":
    main()
