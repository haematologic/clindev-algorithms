# FizzBuzz

```js
/**
 * Write a program that prints the integers from 1 to 100 (inclusive).
 * But:
 *  - for multiples of three, print Lub (instead of the number)
 *  - for multiples of five, print Dub (instead of the number)
 *  - for multiples of both three and five, print LubDub (instead of the number)
 */
```
* The statement for the FizzBuzz problem specifies that you need to print integers from 1 to 100.
* For multiples of 3, instead of the number you should print `Lub`,
* For multiples of 5, instead of the number you should print `Dub`,
* And if the number is divisible by both 3 and 5, instead of printing the number, you should print `LubDub`.

Here you can go ahead and write down the expected results upfront:

```js
/**
 * 1
 * 2
 * Lub
 * 4
 * Dub
 * ...
 */
```
With this understanding in your head. You can jump into the code.

Factors to keep in mind for higher scores:
* Only one log/print call
* Only do the multiple detection math once
* Have no temporary variable mutation (no lazy assignment)
* Shorten the code with ternary operators
