Let us start with the very basic question of what coding is or what software engineers do.
_Coding or Software Engineering is just manipulating the data.
_Move data from one place to another place is what software engineers do.

What's a data structure?
_Data Structures are used to organize, structure, and manage data.
_Data Structure is a collection of data values, the relationships among them, and the functions, operations that can be applied to the data.

Complexity Analysis?
_Complexity Analysis determines how efficient an algorithm is.

Time Complexity?
_measure of how fast an algorithm runs. It is expressed in Big O notation.

Space Complexity?
_Measure of how much auxiliary memory an algorithm takes up. It is expressed in Big O notation.

These are the standard definitions found everywhere on the internet. Let's take a deep dive into it and understand what these terms mean at the basic level i.e the memory level.

Imagine Memory as a canvas sheet!


<img width="852" alt="Screen Shot 2022-01-28 at 9 53 14 AM" src="https://user-images.githubusercontent.com/90536339/151597345-59a8006c-91b1-4544-b134-e62a476ea431.png">

What do we check to store data in the memory canvas?
_If there is a free memory slot to store.
_If there are consecutive memory slots to store.
_THe way to store data in the memory canvas depends on the endianness followed.

Endianness?
_Endianness means ordering of bytes.
_Endianness means that the bytes in computer memory are read in a certain order either from left to right which is big-endian or right to left which is little-endian.

![](http://4.bp.blogspot.com/_IEmaCFe3y9g/SO3GGEF4UkI/AAAAAAAAAAc/z7waF2Lwg0s/s400/lb.GIF)


why is it important?
_knowledge of endianness is important when you are reading and writing the data across the network from one system to another.

Coming back to time complexity, let us define it in a more efficient way.
_Measure of an algorithm speed at run-time as the size of the input to the the algorithm increases.
O(1) means constant time complexity
O(N) means linear time complexity
O(N^2) means quadratic time complexity and etc..

Let us define one more term before diving into the time complexity analysis.
Asymptotic  Analysis?
_Analysing the behaviour of functions as the input ot the function increases and tends towards the infinite value.

Let us take a dive into understanding the constant time complexity O(1).
_What is "1" in O(1)? "1" here refers to the elementary operation; the operation to access a single memory slot.
_Accessing a value from a single memory slot takes constant time.(consider this as the base)

Consider, we have declared an array of size N i.e with N integers and it is stored in the memory canvas contiguously. We are adding two numbers from the array.
_To add two integers, we need to access 8 bytes i.e. 8 memory slots(from the memory canvas). Accessing value from a single memory slot equals O(1) and hence, accessing values from 8 memory slots equals O(8).
_N increases and we are still trying to add two numbers and we are accessing 8 memory slots and it takes O(8) time. The change in value of the input array size is not affecting the time thats required to fetch values from 8 slots. Hence, the operation performed in this case is considered to be constant time operation.

If we are trying to sum all the elements in the array, we need to fetch all the memory slots. Here, as the array size increases, the time for us to fetch the data increases linearly. Hence, sum of all elements in the array takes O(N) time.
