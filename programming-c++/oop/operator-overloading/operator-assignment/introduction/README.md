# Assignment Operator

The assignment `operator=` is used to copy values from one object 
to another already existing object.

```C++
    ClassName& operator =(const lassName& orig);
```

The purpose of the copy constructor and the assignment operator are almost 
equivalent - both copy one object to another: 

* The **copy constructor initializes new objects**

* The **assignment operator replaces the contents of existing objects**

The assignment operator must be **overloaded as a member function**.
	
The overloaded **operator=** returns ***this**, so that we can chain multiple 
assignments together.


## this Pointer

The **this pointer** is a special, implicit pointer available within all non-static 
member functions of a class. It **points to the instance of the class** for which 
the member function is currently being invoked.     


## References
* Josh Lospinoso. **C++ Crash Course**. No Starch Press. 2019
    - Chapter 4: The Object Life Cycle
    
* [Overloading the assignment operator](https://www.learncpp.com/cpp-tutorial/9-14-overloading-the-assignment-operator/)

*Egon Teiniker, 2020-2024, GPL v3.0*
