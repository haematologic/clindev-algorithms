# Implement a singly linked list
> In a singly linked list each node in the list stores the contents of the node and a reference (or pointer in some languages) to the next node in the list. It is one of the simplest way to store a collection of items.

![Linked List](https://upload.wikimedia.org/wikipedia/commons/thumb/4/4b/CPT-LinkedLists-addingnode.svg/474px-CPT-LinkedLists-addingnode.svg.png)

A linked list is simply, a list of nodes. Each node has a value, and a link to a next node in this list, till we arrive at the end of the list where `next` will be `undefined`.

`node {value,next} -> node {value,next} -> undefined`

Now, the trick to writing a linked list, and really *any* data structure with a concept of a `node` e.g. a Binary tree, is to first define a `node`. In general it is useful to keep track of both ends of a linked list i.e. the head and the tail.

Factors to keep in mind for higher scores:
* Factor in safe manipulation of `next` pointers by providing a utility `add` method that lets users add an item to the linked list.
* As an added convenience to our users, we can also provide a method that generates an iterator over all the values in the list.
