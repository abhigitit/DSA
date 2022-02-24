



#include <bits/stdc++.h>


using namespace std;
void siftUp(int currenIndex,vector<int> &heap);
void siftDown(int currentIdx,int endIdx,vector<int> &heap);
void buildMaxHeapSiftUp(vector<int> &heap){
    for(int i=0;i<heap.size();i++){
        siftUp(i,heap);
    }
}
void buildMaxHeapSiftDown(vector<int> &heap){
    int firstparent = floor((heap.size()-2)/2);
    for(int currentIdx=firstparent;currentIdx>=0;currentIdx--){
        siftDown(currentIdx,heap.size()-1,heap);
    }
}

void siftUp(int currentIdx,vector<int> &heap){
    int parentIdx = floor((currentIdx - 1)/2);
    while(currentIdx >0 && heap[currentIdx]>heap[parentIdx])
    {
        swap(heap[currentIdx],heap[parentIdx]);
        currentIdx = parentIdx;
        parentIdx = floor((currentIdx - 1)/2);
    }
}

void siftDown(int currentIdx,int endIdx,vector<int> &heap)
{
    int childOne = currentIdx*2 + 1;
    
    while(childOne<=endIdx)
    {
        int childTwo = currentIdx*2 + 2 <= endIdx ? currentIdx*2 + 2 : -1;
        int idxToSwap;
        if(childTwo!=-1 && heap[childTwo] > heap[childOne])
        {
            idxToSwap = childTwo;
        }
        else
       idxToSwap = childOne;
    
    if(heap[idxToSwap]>heap[currentIdx])
    {
        swap(heap[currentIdx],heap[idxToSwap]);
        currentIdx = idxToSwap;
       childOne = currentIdx*2 + 1;
    }
    else return;
    }
}
int main()
{
    vector<int> heap{10,45,3,6,77,8};
    buildMaxHeapSiftUp(heap);
    for(auto i:heap)
    cout<<i<<"\n";
    cout<<"___________"<<endl;
   buildMaxHeapSiftDown(heap);
    for(auto i:heap)
    cout<<i<<"\n";
    return 0;
}
