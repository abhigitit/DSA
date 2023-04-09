/*
Find Median from Data Stream

Brute Force: We can use insertion sort to find the position of number coming from the stream. For every number, the algorithm takes O(N) tc and hence the
overall TC will be O(N^2).

For calculating the median, its just O(1) tc.

How cna we improve?
We are only interested in finding the middle element of ordered array. Finding median is O(1) if the array is ordered.
Maintaing order of the array using sorting algorithms take O(N^2) time.

Do we need all the elements in the order? No
We only need the middle element to be in the right position. If the number of elements is odd, we will have only one middle element and if the no is evene,
two middle elements.

We can maintain the order of the elements in O(NlogN) time with balanced binary search trees.

We can use binary heap to retrieve the min/max number we want in O(1). But how do we store elements such that the root of the heap will be the middle
element of the current stream?

Can we pop N/2 elements and get the middle element and then push back the N/2 elements? No, this process will be NlogN for every median calculation and
overall will be N^2logN which is ever worse.

Intuition: Use both max and min heaps.
The middle element/s will be last number of firsthalf array and first number of second half of the array.
Store the elements in two heaps such that the middle element/s will be retrived in O(1) and overall TC will be O(NlogN)

In case of odd elements, we will store the extra elements in the max heap such that the middle elements is popped out. 

Either maxheap size will be equal to minheap size or one greater.

minheapsize <= maxheapsize <= minheapsize + 1

How the elements will be stored?
We have assumed that if number of elements are odd, maxheap will have one extra.
*So initially, the first element is stored in max heap.

How to handle insertions into heaps : https://www.youtube.com/watch?v=1LkOrc-Le-Y&t=1499s&ab_channel=TECHDOSE

*/

class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int lsize = max_heap.size();
        int rsize = min_heap.size();
        
        if(lsize==0)
            max_heap.push(num);
        
        else if(lsize==rsize)
        {
            if(num<min_heap.top())
                max_heap.push(num);
            else
            {
                int temp = min_heap.top();
                min_heap.pop();
                max_heap.push(temp);
                min_heap.push(num);
            }
        }
        
        else
        {
            if(rsize==0)
            {
                if(num>max_heap.top())
                    min_heap.push(num);
                else
                {
                    int temp = max_heap.top();
                    max_heap.pop();
                    min_heap.push(temp);
                    max_heap.push(num);
                }
            }
            else if(num>=max_heap.top())
                min_heap.push(num);
            else
            {
                if(num<max_heap.top())
                {
                    int temp = max_heap.top();
                    max_heap.pop();
                    max_heap.push(num);
                    min_heap.push(temp);
                }
                else
                    min_heap.push(num);
            }
        }
    }
    
    double findMedian() {
       int lsize = max_heap.size();
        int rsize = min_heap.size();
        if(lsize>rsize)
            return double(max_heap.top());
        else
            return (double(max_heap.top())+double(min_heap.top()))/2;
    }
};


