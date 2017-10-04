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

# Solutions

[Here](https://github.com/haematologic/clindev-algorithms/blob/master/02%20random/C/rdrand/db_main.c) is my first solution, to 02 random, written in C.

I am very much a beginner to C but was spurred along by being able to make a solution to the [Game of Life](https://github.com/haematologic/clindev-game-of-life/) last week, and was really interested to try the >= IvyBridge onboard CPU entropy generator that Stefan mention.

I have hacked something together using the [Intel libdrng for C](https://software.intel.com/en-us/articles/the-drng-library-and-manual) and adapting some code from StackOverflow [here](https://stackoverflow.com/questions/2509679/how-to-generate-a-random-number-from-within-a-range)...

Was a very interesting thought experience on how to make bins across the range that can be evenly picked. I have graphed some sample runs (99999 per range) using Python Pandas / Matplotlib shown here in a Jupyter Notebook [here](https://github.com/haematologic/clindev-algorithms/blob/master/notebooks/02_random.ipynb)
