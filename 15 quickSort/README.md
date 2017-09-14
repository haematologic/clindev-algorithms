# Quicksort algorithm
> Quicksort (also called partition sort and pivot sort) is arguably the most used sorting algorithm. It is the one commonly implemented internally in language runtimes.

![Quicksort Animation](https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif)

* We start off by creating a function that takes an array of numbers and will return a sorted array of numbers.

```js
/**
 * Sorts an array using quick sort
 */
export function quickSort(array) {
  array = array.slice();

  return array;
}
```
* Within the function we create a copy of the original array using `slice`.
* And return this array.
* Before returning it we will sort it using a recursive partitioning routine.
* Lets go ahead and write this partitioning function, it will take an array, the start index of the array section that it needs to partition, and the upper limit of the index for the partitioning.
* The quicksort algorithm is also called partition sort *because of this partitioning routine*.

```js
/**
 * Partitions the [start, before) indexes of the array
 */
function partition(array, start, before) {
}
```
* The objective in each recursive iteration is to select a `pivot` element, and move the items in the array such that the array satisfies the following property. (items less than the pivot appear before the pivot, and items greater than the pivot appear after the pivot)
```js
// [
//  items less than pivot,
//  pivot,
//  items greater than pivot,
// ]
```
The quicksort algorithm is also called `pivot` sort due to this partitioning around a pivot.

* There are multiple ways to select the pivot, but we can select a random index from the array.
* To make the remaining algorithm easier, we move the item at this index to the start of the array. This way we don't need to keep moving the pivot to its rightful place when we are iterating through the elements in the array subsection.
* We will loop through items in the array subsection maintaining the following invariant
```js
[
  items less than pivot,
  - index for pivot rank,
  items greater than pivot,
  - index for current item,
  remaining items we have yet to see,
]
```
* Now lets loop through the array subsection with these invariants in mind.
* We end the loop before index reaches the before point.
* We start the loop at start+1 as our pivot is at the start position.
* If the item at the current index is less than the pivot, then we
  - increase the pivot rank.
  - slide this smaller element, into the section of the array that holds items less than pivot. We can do this sliding by simply moving the item at the pivotRank to the current index. This is because the item at this *incremented* pivot rank should be greater than the pivot.
  After this sliding the item at the pivot rank is smaller than the pivot, which is one of the invariants we are maintaining.
* If the item is greater than pivot then we just keep on looping without any changes to pivotRank.
* By the time the loop terminates we have met our invariant, expect that now there are no more remaining items to see.
```js
[
  items less than pivot,
  - index for pivot rank,
  items greater than pivot,
  - index for current item,
]
```
* Now we need to move the pivot to be between the items that are less than and great than.
* If the pivotRank didn't change in the loop, then the pivot is already in its rightful place at the start of the array subsection.
* If the pivotRank changed during our loop, we can simply put the pivot into its rightful place by swapping it with the element at the current pivotRank. This is because any item at the pivot rank is definitely smaller than pivot because of our swaps within the loop.
* After putting the pivot at its rightful place, the array subsection has been partitioned into
```js
[
  items less than pivot,
  pivot,
  items greater than pivot,
]
```
* Notice that in each call to partition, not only are we putting the pivot in its rightful place, but more importantly we are dividing the problem into two smaller problems that can be tackled independently. Items less than the pivot can be sorted independent of the items greater than the pivot. We can do this sorting by recursively calling the partition routine on the items less than and items greater than the pivot.
```js
partition(array, start, pivotRank);
partition(array, pivotRank + 1, before);
```

Factors to keep in mind for higher scores:
* This partition routine is recursive, and like any recursive function it will have a base case that terminates the recursion. For sorting you can abort under certain conditions, factor these into your code.
* Consider the different ways of selecting your pivot point, which is fastest?
