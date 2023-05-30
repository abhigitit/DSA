/*
Creating only one instance of the class.
Don't allow users to create an instance or hit the class constructor.
Move constructor to private.

Then how to create a single instance? Use a static function which relates to class and not to any particular object. 

It can help in optimizing resource utilization by ensuring that only one instance is created and shared when necessary. 
It prevents unnecessary duplication of resources and ensures efficient usage of those resources.
Resource Sharing: By having only one instance of a class, you can share resources efficiently among multiple parts of your code. 
For example, if you have a database connection or a configuration manager, having multiple instances could lead to unnecessary resource consumption or conflicts. The Singleton pattern ensures that all code accesses the same instance, allowing efficient sharing of resources.
Global Access: The Singleton pattern provides a convenient way to access an object from anywhere in the application without passing it around as a parameter.
This can be particularly useful for objects that need to be accessed by various components or modules of a system.

It is not thread safe. If multiple threads at the same time try to create instances, the whole purpose is destroyed.

Use mutex locks.


https://www.youtube.com/watch?v=oeQWxhlnCHM

*/
