# Bubble Sorting
> Bubble sort is considered the simplest sorting algorithm to implement.

![Bubble Sort Animation](https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif)

* The function takes an array of numbers as an argument and will return a sorted array of numbers.
* Bubble sort works by looping over the input array n times
* In each iteration the goal is to *Bubble* the highest ranking value to the end
  * So we loop through all the items in the array
  * We simply check if the current value on the left is greater than the current value on the right.
  * If so we swap the variables at the two positions.
  * This ensures that we keep bubbling the highest value to the last position of the array.
* Since we are looking up the j+1 item it makes obvious sense to terminate the inner loop 1 before the last index.

Demonstration:
* We will sort the array [4,3,2,1]. We expect the final result to be 1,2,3,4.
* Now if we run this, you can see
  * 4 bubbling to the end of the array
  * Then 3,
  * and finally 2
* This explains the concept of bubble sort and how it gets its name.
```js
/**
 * Explains the bubble sort concept
 */
[ 4, 3, 2, 1 ]
[ 3, 4, 2, 1 ]
[ 3, 2, 4, 1 ]
[ 3, 2, 1, 4 ]
[ 2, 3, 1, 4 ]
[ 2, 1, 3, 4 ]
[ 1, 2, 3, 4 ]
```

Factors to keep in mind for higher scores:
* Instead of always iterating n times try to optimize the algorithm to terminate early.
* Consider creating a variable to track if any bubbling takes place and note whenever we swap a variable
* Replace the top **for loop** with a **while** that terminates when no bubbling happens
