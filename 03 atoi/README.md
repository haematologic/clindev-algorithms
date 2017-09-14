# Parse a string to an integer
> A common interview question is to write  a  function  that  converts  a  string  into  an  integer e.g. `"123"` => `123`.  This  function  is commonly  called  `atoi` because  we  are  converting  an  ASCII  string  into  an  integer.

Now JavaScript has a function called `parseInt`, that can do this integer parsing for us. Lets run through a few examples of this built in function's behaviour.

* For simple ints we get the int,
* For ints with a negative sign we get a negative int.
* When it encounters a character that is not a numeral, it ignores it and all succeeding characters. It still returns the integer value parsed up to that point, so for "-123Extra" we get -123.
* You can use this fact to ignore decimal portions as well as demonstrated in this example
* Finally if a string does not start with a decimal numeral it returns NaN i.e. Not A Number.

```js
/**
 * Converts a string to a integer
 * e.g. "123" => 123
 */
export function atoi(str: string): number {
  return parseInt(str);
}

console.log(atoi('123')); // 123
console.log(atoi('-123')); // -123
console.log(atoi('-123Extra')); // -123
console.log(atoi('-123.456')); // -123
console.log(atoi('Does not start with a digit 123')); // NaN
```

Note that you can customize the behavior of parseInt quite easily by wrapping it in a function.

e.g. `parseInt` siliently ignoring invalid trailing characters can be considered a behavior you want to change.

So you can easily implement a more fit for purpose function with a simple regex test that only allows strings containing things that we support e.g. a leading sign followed by any number of decimal digits.
* In all other cases we will return NaN's
* And now all imperfect inputs to the our function will return NaN.

Factors to keep in mind for higher scores:
* You are not allowed to use `parseInt` or any other built-in number parsing functionality.
* Able to parse decimal points and negative numbers.
* Able to error out when there is no number (NaN).
