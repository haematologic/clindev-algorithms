# Implement a doubly linked list in TypeScript
> In a doubly linked list each node in the list stores the contents of the node and a pointer or reference to the next and the previous nodes in the list. It is one of the simplest way to store a collection of items.

![Doubly Linked List](http://algorithms.tutorialhorizon.com/files/2016/03/Doubly-Linked-List.png)

Here we have a singly linked list with a FIFO removal `dequeue` method.

Lets say we wanted to add a last in first out `pop` operation.
* It will return either the last value or undefined if we are out of elements
* We can only pop a value if we still have an active `tail`
* We can grab the value that we want to return from the tail.
* Next we have to do our routine maintenance of the `tail` and `head` nodes.
* Now we have to update the tail to be the second last item in the linked list. To find that in this singly linked list we would need to start from the `head` till we arrive at a node whose `next` is the current `tail`. However such an implementation would be `O(n)` and we want an `O(1)` algorithm.

```js
/**
 * LIFO removal in O(1)
 */
pop() {
  if (this.tail) {
    const value = this.tail.value;
    this.tail = // figure out a new tail
  }
}
```

There is a data structure called a `doubly` linked list that would make it trivial to figure out the second last node i.e. the node `previous` to the tail.

```js
undefined <-> node { value, next, prev } <-> node { value, next, prev } <-> undefined
```

Instead of just `value` and `next` we also keep track of any previous node, against each node. Of course, for the head `prev` will be `undefined` and for the `tail` the `next` will be `undefined`.

We will have to add a very slight additional maintenance for this new `prev` node reference. On `add` we will create a `DoublyLinkedListNode` and therefore also initialize the `prev` value. Additionally if we have a current `tail`, we continue to update the `next` pointer, but now we also update the `prev` pointer for this new node.

The modifications to the dequeue operation are equally simply. After dequeing the current head, if we get a new head value, we simply need to clear the `prev` reference.

It is worth mentioning, that you should take the time to understand what a `node` means in your data structure, and appreciate the fact that you need to maintain the `value/prev/next` members in your data structure operations. Taking a paper and pen, and drawing out operations may go a long way in your understanding.

The main advantage of using a `DoublyLinkedList` is that any operations that require constant `next` and `prev` reference manipulations, can be implemented with `O(1)` time complexity. In this example it allows us to implement a FIFO Queue, and a LIFO Stack operation, in a single data structure with an `O(1)` time complexity.
