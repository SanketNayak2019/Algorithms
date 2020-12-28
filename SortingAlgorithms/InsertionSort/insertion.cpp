#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ifstream unsortedData ("../testinput.txt");
    vector<int> unsortedInts;
    
    //populate vector with input data
    int temp;
    while(unsortedData>>temp) unsortedInts.push_back(temp);
    unsortedData.close();

    //sort vector
    for(int i = 1; i<unsortedInts.size(); ++i){
        int value = unsortedInts[i];
        for(int j = i-1;j>=0;--j){
            if(unsortedInts[j]>value)
                swap(unsortedInts[j],unsortedInts[j+1]);
            else break;
        }
    }

    //print vector
    for(int num:unsortedInts)
        cout << num << " ";
    cout<<"\n";
}