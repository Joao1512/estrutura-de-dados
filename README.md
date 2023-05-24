# Data Structures in C

That is my on C implementations for Arrays, LinkedList, Queue and others data structures. 

## 💻 Array

- **clear**() - removes all items.
- **print**() - prints all items.
- **find**(item) - looks for value and returns first index with that value, -1 if not found.
- **isFilled**(index) - returns true if there is a value at index, false if there isn’t.
- **validInsert**(index) - returns true if insertion can be done at index.
- **shiftRight**(index) - shifts all items after index one position ahead.
- **insert**(item, index) - inserts item at index, shifts that index's value and trailing elements to the right.

## 💻 LinkedList

- **size**() - number of items.
- **print**() - prints all items.
- **front**() - get value of front item.
- **back**() - get value of end item.
- **removeValue**(value) - removes the first item in the list with this value.
- **remove**(index) - removes the item in index.
- **insert**(index, value) - insert value at index, so current item at that index is pointed to by new item at index.
- **indexOf**(item) - get the index of first occurrence of item.
- **pushFront**(value) - adds an item to the front of the list.
- **pushBack**(value) - adds an item at the end.

## 💻 Queue

- **enqueue**(value) - adds value at position at tail.
- **dequeue**() - returns value and removes least recently added element (front).
- **clear**() - removes all items.
- **size**() - number of items.
- **print**() - prints all items.
- **indexOf**(item) - get the index of first occurrence of item.

## 🗒️ Note:

**This repository is a work in progress, and I will post more lines of code over time with more data structures and improvements to existing ones.**
