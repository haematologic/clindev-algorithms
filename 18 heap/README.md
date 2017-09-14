# Implement the heap data structure using JavaScript
> Heap is a data structure that can fundamentally change the performance of fairly common algorithms in Computer Science.

> The heap data structure is called a heap because it satisfies the heap property. The heap property states, that if P is a parent node of C, then the value of node P is less than the value of node C.

* Here we have a graph of nodes `A,B,C,D,E`
* Its nice to have a mental model of a heap as a `complete binary tree`.
* This tree would satisfy the heap property if `A` is less than its children `B` and `C` Similarly `B` is less than its children `D` and `E`.
* Note that if the heap property is satisfied for direct children, it is also automatically satisfied for any indirect children. e.g. A < D and A < E.
* If the heap property is satisfied by each parent, it implies that the *smallest* item in the tree, has to be the root node.
* The heap data structure is called a heap because it has this heap property.
* ***(Select the tree)*** Also worth mentioning is the fact that since it is a complete binary tree, the maximum number of levels will be of the order `log n` where n is the number of items in the tree.

```
           A
         ↙   ↘
       B       C
     ↙   ↘
    D     E

A < B
A < C
B < D
B < E

A < D
A < E
```

Note that a given set of values can be arranged in multiple ways to satisfy the heap property. E.g.

* Given 4,4,5,6,9
* We can have the following two trees,
* Both are perfectly valid as each node is smaller than all its children.
* The only position that is guaranteed to be the same among all possible heaps with a given set of values, is the root node. The root will always be the item with the smallest value.
```
4,4,5,6,9

Example Tree
           4
         ↙   ↘
       5       4
     ↙   ↘
    6     9

Example Tree
           4
         ↙   ↘
       4       5
     ↙   ↘
    9     6
```

Even though its nice to have a mental model of a heap as a `complete binary tree` with pointers, they are normally implemented as an array. An array provides very low memory overhead and the left and right child nodes can be calculated quite easily.

* Consider the simple array of indexes 0-13.
* It can be *conceptualized* as a tree with indexes corresponding to items of the array. When we are done with the left and right nodes at a level, we start a new level, and consider these indexes as the left and right of items of the previous level. We stop whenever we run out of items in the array.

```
[] = 0,1,2,3,4,5,6,7,8,9,10,11,12,13

                0
           ╱       ╲
         ↙            ↘
       1                2
     ↙   ↘           ↙    ↘
   3       4        5       6
 ↙  ↘    ↙  ↘    ↙  ↘    ↙
7    8   9   10  11  12  13
```

Given a node at index `n`, lets try and figure out a formula to find the index for its left child node. As always, its a great idea to write down a few examples so we can use these to test our formula.
```
left(0) = 1
left(1) = 3
left(3) = 7
```

* The key realization for the formula is that for an item at index `n`, we will essentially have to skip `n` spaces on its right, and one more to arrive at its left node.
* So we arrive at the formula for `left(n)` as `2n+1`. Our examples are all satisfied by this equation.
* The right child node, is simply one plus the left, so its formula is `2n+2`.
* Not only can we traverse the children of such a binary tree by simple math, we can also traverse the parent of a given index, simply by going back from our `left` and `right` formulas.
* We start off with different parent formulas for left and right children.
* From `2n+1` you can see that `left` node indexes must be an odd number, and `2n+2`  means right node indexes must be an even number.
* So at a given index if its even, we use parentRight formula otherwise we use the parentLeft formula.
* With these `left`, `right` and `parent` equations we can easily traverse this array backed binary tree, without needing to have pointers.
```
left(n) -> self + n items on the right + 1
left(n) = n + n + 1 = 2n + 1

left(0) = 2(0) + 1 = 1
left(1) = 2(1) + 1 = 3
left(3) = 2(3) + 1 = 7

right(n) = 2n + 2

parentLeft(n) = (n - 1) / 2
parentRight(n) = (n - 2) / 2

2n + 1 => left is odd
2n + 2 => right is even

parent(n) =>
  n is even => (n - 2) / 2
       else => (n - 1) / 2
```

***Select the line with the array***
This usage of an array as the backing storage is one of the reasons why heaps are extremely popular. Furthermore, pointer traversal can be done with simple math, which can be done very efficiently with bit shifting tricks for powers of two.

We now have enough context to jump into its implementation of heaps excellent O(logn) `add` and `extractRoot` methods. These are the raison d'etre of the heap data structure.

* To allow us to compare two items of type T we need a compare function. This compare function will follow the same semantics as offered by the built in JavaScript `sort` method.

```js
function compare(a, b) {
  if (a is less than b by some ordering criterion) {
     return -1;
  } else if (a is greater than b by the ordering criterion) {
    return 1;
  } else {
    return 0;
  }
}
```

We start off by creating a generic class for a `Heap` for items.
* we create a backing data storage as an array of items.
* we have a constructor that accepts a compareFn of items.
* we go ahead and write our `private` node traversal functions
  * One for the left child node.
  * One for the right child node.
  * and finally a traversal to the parent from a given node index which has a different implementation depending on the index being even or odd, as we discussed before.

When creating the `add` method be sure to have a private `shiftUp` function that makes sure there is no violation in the heap property between this new node and its parent, and also makes sure that the smallest node rises to the top of the heap.

The other key operation of the heap is the `extractRoot` method, which retrieves and removes the root element of this heap. This root element will be the smallest element in the heap.
* Of course we can only remove an item if there are any items.
* The root we want to return is going to be the first item in the array.
* If we remove this item there will be a hole at the head of the internal array. The best way to really fill this hole is with the last item in the array. That would result in the minimum number of array index changes.
* Now this new head item will most likely be larger than its children, and we will fix the inconsistency be implementing a `shiftDown` routine.

As a final exercise we can add a `size` method like we do for many of our data structures. In this case we can simply return the length of the underlying array.

Another useful method to have is `peek` which instead of removing the root, only looks at the value.

There are quite a few use cases where this O(logn) insertion and extract can greatly improve efficiency of simple programming challenges. Basically whenever you see an algorithm requiring repeated minimum (or maximum) computations, consider using a heap.
