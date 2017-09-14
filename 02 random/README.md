# Create random integers in a given range
> Learn how to create random integers without an external library

JavaScript Math.random provides you with a random floating point number in the range [0 inclusive, 1 exclusive).

* A common challenge presented, to beginning developers in an interview, is to go ahead and create a function that should return an int between a given start and end value.
* We start by creating our function that accepts a  start value, a before value.

```js
/**
 * Returns a random int between
 * @param start inclusive
 * @param before exclusive
 */
export function randomInt(start, before){
}
```

# Entropy
Math.random is pseudo-random but good enough for most cases. For true randomness (entropy pool version) and security critical applications you need something like NodeJS crypto.

Operating systems generally have an entropy pool (using user input / cpu usage etc) that they provide to programs that need them (either natively or through the virtual machine of your language).

> Modern CPUs also have a built in entropy generator e.g. intel IVY bridge and later CPUs have `RDRAND` instruction, however your operating systems may or may not use such instructions.

Factors to keep in mind for higher scores:
* Consider integrating a more robust entropy generator
