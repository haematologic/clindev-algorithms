# Binary Search Algorithm
> Binary search is a very fundamental algorithm in Computer Science. It powers BSTs (binary search trees) which form the basis of modern databases and immutable data structures. Binary search works very much the way humans intuitively search for a name in a yellow pages directory (if you have ever seen one) or the dictionary.

![Binary Search](https://upload.wikimedia.org/wikipedia/commons/thumb/8/83/Binary_Search_Depiction.svg/470px-Binary_Search_Depiction.svg.png)

* We start of by writing our `binarySearch` function that takes an array of numbers and an element we have to find.
* The function should return the index of the element if its found within the array.
* If the element is not found we can simply return -1

Factors to keep in mind for higher scores:
* Recursively break down the problem into smaller ones, and search for the element within a given start, and end range of the array.
* Divide the problem space into two equal search spaces by finding the middle element of the current search subsection
* This algorithm is called binary search because we divide the search problem into two (aka binary) sub problems.
