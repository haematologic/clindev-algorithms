# Create a hashmap
> A common interview question to weed out beginner / true expert developers is to simply ask them to create a dictionary / hashmap / map.

Before we begin it is worth pointing out that Javascript ES6 has a built in hash map data structure implementation in the form of the `Map` class.

* To demonstrate that built in class, lets create a map of `string` keys and values that are objects that have a `cost` property.
* We store a domain object of cost 123 against the key foo
* We store a domain object of cost 456 against the key bar
* We can retrieve the value against any key using `get`
* We can also check if there is a value stored against a key using the `has` method which returns `true` when there is a key/value pair stored and false otherwise.
```js
const map = new Map<string, { cost: number }>();
map.set('foo', { cost: 123 });
map.set('bar', { cost: 456 });
console.log(map.get('foo')); // {cost: 123}
console.log(map.has('bar')); // true
console.log(map.has('baz')); // false
```
***Delete example***

* We create a generic class for keys of type number or string, and any `Value` type.
* We will internally store the data as an object/dictionary which can be indexed by a string to return a value.
* We add a set method that takes a key of type `Key` and a value of type `Value` and simply stores the value against the key in the internal indexed object.
* We add a get method that takes a key and returns either the value or `undefined` if there is nothing stored against the key. In the method body we simply return the looked up value from the internal index object.
* For delete we simply delete any data stored against the key in the internal data object.
* For the `has` method we simply check if there is a value stored against the key in the internal data object.

Factors to keep in mind for higher scores:
* Keep in mind that you may have several unwanted prototypes (Javascript) if you simply create a blank `{}` object, you may need to use the `Object` method instead
