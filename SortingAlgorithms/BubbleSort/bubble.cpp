#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ifstream unsortedData ("../testinput.txt");
    vector<int> nums;
    
    //populate vector with input data
    int temp;
    while(unsortedData>>temp) nums.push_back(temp);
    unsortedData.close();

    //sort vector
    int numSwaps = -1;
    while(numSwaps){
        numSwaps=0;
        for(int i = 0; i<nums.size()-1;++i){
            if(nums[i] > nums[i+1]){
                swap(nums[i],nums[i+1]);
                ++numSwaps;
            }
        }
    }

    //print vector
    for(int num:nums)
        cout << num << " ";
    cout<<"\n";
}