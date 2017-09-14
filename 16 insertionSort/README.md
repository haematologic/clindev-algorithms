# Insertion sort algorithm
> Insertion sort is a very intuitive algorithm as humans use this pattern naturally when sorting cards in our hands.

![Insertion Sort Animation](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

* The basic idea of insertion sort is to mentally divide the array into a sorted left section and an unsorted right section, moving an item 1 by 1 from the unsorted right section into its rightful place in the sorted left section.
```
/**
 * sorted    unsorted
 *        <=
 */
```
* To understand the algorithm a bit better lets look at an example.
* We will sort the array [4,3,2,1]. We expect the final result to be 1,2,3,4.
```js
[ 4, 3, 2, 1 ]
{ section: [ 4 ], current: 3 }
{ section: [ 3, 4 ], current: 2 }
{ section: [ 2, 3, 4 ], current: 1 }
[ 1, 2, 3, 4 ]
```
* You can see that we start with a single sorted item of 4, and put the current item 3 in its rightful place, Next we move 2 into its rightful place, and finally the current item 1 into its rightful place.

* Loop through all the items in the array skipping the first one as a single item is already sorted.
* Storing the item in a `current` variable opens up a hole at the ith position in the array that we can use to slide items one by one if they are bigger than the current item.
* Use a variable `j` to keep track of which item we are comparing against the `current` item.  
* We will continue to do comparison till we arrive the head of the array *or* the item at the jth position is no longer smaller than the current item.
* Once the loop is complete, our sorted left section is equal to the whole array, and each item has been placed into its rightful place on the left. Therefore the whole array is sorted.

Factors to keep in mind for higher scores:
* None
