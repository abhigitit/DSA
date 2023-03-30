/*

Return the number which has its rightsum = leftsum
Rightsum = sum of all the elements to the right of the equilibrium number
Leftsum = sum of all the elements to the left of the equilibrium number

Algorithm:
Calculate total sum of elements.
Assign the value of total sum to rightsum and let leftsum be 0
Loop through and subtract the number from the right sum(subtracting that number gives the numbers’ right sum).
Check if its equal to leftsum and if true, return the element
Else, add leftsum to the current element(so that in the next iteration, left sum is actually the left sum of the element we are looking)
*/


int equilArray(vector<int>& array)
{
    int sum=0;
    int rightSum = 0;
    int leftSum=0;
    for(auto i:array){
        sum+=i;
    }
    rightSum = sum;
    for(int i=0;i<array.size();i++){
        rightSum = rightSum-array[i];
        if(leftSum==rightSum){
            return array[i];
        }
        else
        leftSum += array[i];
    }
    return -1;
}


