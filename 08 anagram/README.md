# Algorithm to determine if two strings are an anagram
> The anagram test is commonly used to demonstrate how an naive implementation can perform significant order of magnitudes slower than an efficient one.
> A word is an anagram of another if you can rearrange its characters to produce the second word. Here we write a function that given two strings determines if they are anagrams of each other.

```js
/**
 * A word is an anagram of another if you can rearrange its characters to produce the second word.
 * Given two strings determine if they are anagrams of each other.
 * - 'earth' and 'heart' are anagrams
 * - 'silent' and 'listen' are anagrams
 * - 'foo' and 'bar' are not anagrams
 */
```

A plain implementation that derives from the definition would be to
* check all the permutations of s1
* and then see if it is equal to s2
* If they are then the strings are anagrams
* If no permutation matched then they are not anagrams

Factors to keep in mind for higher scores:
* Consider the speed of your code, and if rearrangements are actually required, if so the complexity of the algorithm will be equal to the possible permutations of s1, so order of n! (n = number of characters in the string)
* Consider using a HashMap that counts the characters between the strings (time complexity of this version is of order n (O(n)) where n is the number of characters in the strings.)
