# Example: Move Constructor for Simple String 

A move constructor is all about **moving resources instead of copying them**.


## Move Constructor

Instead of making a brand-new buffer and copying each character, 
the move constructor just grabs the pointer from the other object.

That’s why this operation is **super cheap**, it is just pointer juggling 
instead of heap allocation + character-by-character copying.

```C++
String::String(String&& other) noexcept
    : _size(other._size), _data(other._data)
{
    // Leave 'other' in a safe, empty state
    other._size = 0;
    other._data = nullptr;
}
```

* Copy the raw data pointer and size: Our object now owns 
	the buffer that `other` used to own.

* Reset the old object to ensure:
	- the old object is valid and harmless
	- its destructor won’t delete memory it no longer owns
	- you don’t get double-frees

* Mark it noexcept: Move constructors should always be noexcept, because:
	- Standard library containers (like `std::vector`) will use moves 
		instead of copies only if they are guaranteed not to throw.
	- It allows our type to be used efficiently in more places.


*Egon Teiniker, 2024-2025, GPL v3.0*
