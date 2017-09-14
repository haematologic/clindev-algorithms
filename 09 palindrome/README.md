# Algorithm to determine if a string is a palindrome
> A palindrome is a string that reads the same forward and backward, for example, radar, toot, and madam.

```js
/**
 * @module Palindrome solvers
 * A palindrome is a string that reads the same forward and backward, for example,
 * - radar, toot, madam.
 */

/**
 * Returns true if the string is a palindrome
 */
```

##Level 1:
* We will start by creating our isPalindrome function
* It takes a string and returns a boolean

##Level 2:
* Write a function to check if `any permutation of` a given string is a palindrome

```js
/**
 * Returns true if any permutation of the string is a palindrome
 * civic true
 * vicic true
 * toot true
 * toto true
 * civil false
 */
```
* e.g. `civic` is a palindrome. So any permutation of it e.g. `vicic` would also be allowed.
* Same for toot and toto.
* No permutation of the characters of `civil` make a palindrome.


Factors to keep in mind for higher scores:
* Similar to the Anagram challenge, runtime complexity will be drive by the permutations function. The trick is to understand the pattern to all palindromes (pairs of characters, only 1 is allowed to be left unpaired).
* Consider a HashMap implementation
* Avoid recursion when possible
