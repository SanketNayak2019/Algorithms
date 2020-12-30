#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//merges two sorted ranges of a vector in place
void merge(vector<int> &nums,int left,int middle,int right){
    int left2 = middle+1;
    while(left<=middle && left2<=right){
        if(nums[left] <= nums[left2]) ++left;
        else{
            rotate(nums.begin()+left,nums.begin()+left2,nums.begin()+left2+1);
            ++left, ++middle, ++left2;
        }
    }
}

void mergeSort(vector<int> &nums, int left, int right){
    if(left<right){
        int splitInd = int((left+right)/2);
        mergeSort(nums,left,splitInd);
        mergeSort(nums,splitInd+1,right);
        merge(nums,left,splitInd,right);
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
    mergeSort(unsortedInts,0,unsortedInts.size()-1);

    //print vector
    for(int num:unsortedInts)
        cout << num << " ";
    cout<<"\n";
}