# Merge sort algorithm
> MergeSort is a famous example of a divide and conquer algorithm.

![Insertion Sort Animation](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)

MergeSort is a recursive algorithm. In any recursive algorithm you will have some base conditions that terminate the recursion.

* In merge sort we divide the array into two equal portions, and sort them recursively.
* To get these two portions of the array, we first find the middle index by dividing the array length by 2.

```js
const middle = Math.floor(array.length / 2);
const left = array.slice(0, middle);
const right = array.slice(middle);
```
* We then make two equal slices of the array using `array.slice` and store them as `left` and `right`.
* For an uneven array length the right portion will be bigger than the left one, but it shouldn't matter for us, as it will all recursively boil down to an array of length 1.

The beauty of merge sort is that given sorted left and right segments, it is very easy to merge them into a bigger sorted segment.

* We will offload the segment sorting problem recursively to mergeSort itself by invoking it with the `left` and `right` arrays. Finally we will call the `merge` function which will merge these sorted segments into a bigger sorted segment.
```js
return merge(mergeSort(left), mergeSort(right));
```

* The merge function plays the `conquering` role in the mergeSort divide and conquer algorithm, and is truly where the beating heart of mergesort exists.
* It takes the sorted left and right segments, and is responsible for cleverly merging them into a single sorted array.
* The innovation is to simply, one by one select the smallest item, from either the left or the right segment and put that into the result giving us the merged sorted array.

* To understand the algorithm lets run through a simple example. We will call merge sort with the array `4,3,2,1`. We expect the output to be 1,2,3,4.
* You can see that we split 4,3,2,1 into two smaller problems.
* First one is 4,3 which we further split into 4 and 3,
* We merge these single item sorted arrays to get get the larger sorted array 3,4
* We then do the same for 2,1, splitting it into 2 and 1 and then merging it as the sorted 1,2
* Finally we merge these 3,4 and 1,2, into the sorted 1,2,3,4

Factors to keep in mind for higher scores:
* Consider the conditions that need to be met for odd length arrays
