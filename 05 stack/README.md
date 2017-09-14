# Stack implementation
> A stack is an abstract data type that stores a collection of elements, with two principal operations:
* push: adds an element to the collection
* pop: removes the most recently added element that was not yet removed.
The order in which elements are poped is `Last In First Out` aka. `LIFO`.

![LIFO Stack](https://upload.wikimedia.org/wikipedia/commons/b/b4/Lifo_stack.png)

A `stack` is a Last in First out (LIFO) with key operations having a time complexity of O(1).
* It will have two key operations.
* The first one is push which adds an item into the stack.
* The other key operation pops an item from the stack. If there are no more items we can return an out of bound value like `undefined`.

Factors to keep in mind for higher scores:
* Add a `size` method that allows you to safely find out if there are any elements present in the data structure.
