#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <algorithm>

using namespace std;

/*
This function increments the left and right to find the new left and right
*/
void increment(const vector<int> &nums,int &left,int &right,const int partValue){
    while(nums[left]<partValue)
        ++left;
    while(nums[right]>partValue)
        --right;
}

int partition(vector<int> &nums,int leftInd, int rightInd){
    //Chooses partition index (ideally would get sample median or other method)
    size_t partInd = rand() % (rightInd-leftInd) + leftInd; 
    int partValue = nums[partInd];

    //Moves partition var to the rightmost spot
    swap(nums[partInd],nums[rightInd]);

    //finds the first var greater than the partition from the left and vice-verse for the right
    int left = leftInd, right = rightInd-1;
    increment(nums,left,right,partValue);

    //iterates until left>=right at which point every value less than the partition will be to its left
    while(left<right){
        swap(nums[left],nums[right]);
        increment(nums,left,right,partValue);
    }

    //move the partition var back to its spot
    swap(nums[left],nums[rightInd]);

    return left; //return the index of the partition
}

void quick(vector<int> &nums,int left,int right){
    if(left<right){
        //gets the partion index from the partitioned vector
        int partInd = partition(nums,left,right);

        //Recursively partition/sort left and the right of the partition
        quick(nums,left,partInd-1);
        quick(nums,partInd+1,right);
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
    srand (time(NULL));
    quick(unsortedInts,0,unsortedInts.size()-1);

    //print vector
    for(int num:unsortedInts)
        cout << num << " ";
    cout<<"\n";
}