<img width="919" alt="Screen Shot 2022-02-02 at 7 26 49 PM" src="https://user-images.githubusercontent.com/90536339/152276533-a084c705-13cc-4fb8-abed-b0a2f4528033.png">


In dynamic arrays, the compiler allocates more memory than specified. Assume that the additional memory provided is also utilized, that's when the compiler creates more space somewhere else in the memory, and then copying happens => O(N)

Space Complexity in dynamic arrays for insertion is O(1), O(N), O(1)..... O(1) when there is space still left in the dynamic array and O(N) when the last memory slot is utilized.

Amortized Analysis: Sort of complexity analysis where we are taking all the edge cases into account.

Many constant insertion operations cancel out the linear time insertions.
Amortized TC of insertion in dynamic array = O(1)
