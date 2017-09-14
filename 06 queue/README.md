# Queue implementation
> A queue is an abstract data type that serves as a collection of elements, with two principal operations: enqueue, which adds an element to the collection, and dequeue, which removes the earliest added element. The order in which elements are dequeued is `First In First Out` aka. `FIFO`. The term `queue` takes it name from the real world queues e.g. "a queue at the ticket counter".

![FIFO Queue](https://upload.wikimedia.org/wikipedia/commons/d/d3/Fifo_queue.png)

Factors to keep in mind for higher scores:
* `push` and `shift` Javascript implementations may seem easy, but are not actually the fastest as they have an average runtime of 0(n) instead of the fastest 0(1) operation cost.
* Consider tracking the `nextEnqueueIndex` and `lastDequeuedIndex` which we initialize to 0.
* In short the implementation is simply maintaining a map and tracking our queue and dequeue indexes within the enqueue and dequeue methods.
* Add a size function which returns the number of elements in the queue.
