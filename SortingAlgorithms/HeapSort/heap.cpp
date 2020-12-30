#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void heapify(vector<int> &nums, int heapLen, int rootInd){
    int localMax = rootInd, left = rootInd*2+1, right = left+1;
    if(left<heapLen && nums[left]>nums[localMax]) localMax = left;
    if(right<heapLen && nums[right]>nums[localMax]) localMax = right;
    if(localMax!=rootInd){
        swap(nums[localMax],nums[rootInd]);
        heapify(nums,heapLen,localMax);
    }
}

void heapSort(vector<int> &nums){
    for(int index = nums.size()/2-1;index>-1;--index)
        heapify(nums,nums.size(),index);
    for(int index = nums.size()-1;index>0;--index){
        swap(nums[0],nums[index]);
        heapify(nums,index,0);
    }
}

int main(){
    ifstream unsortedData ("../testinput.txt");
    vector<int> unsortedInts;
    
    //populate vector with input data
    int temp;
    while(unsortedData>>temp) unsortedInts.push_back(temp);
    unsortedData.close();

    //sort vector
    heapSort(unsortedInts);

    //print vector
    for(int num:unsortedInts)
        cout << num << " ";
    cout<<"\n";
}