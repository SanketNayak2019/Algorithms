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
    for(int i = 0; i<unsortedInts.size(); ++i){
        int minIndex = i;
        for(int j = i+1; j<unsortedInts.size();++j)
            if(unsortedInts[minIndex] > unsortedInts[j]) minIndex = j;
        swap(unsortedInts[i],unsortedInts[minIndex]);
    }

    //print vector
    for(int num:unsortedInts)
        cout << num << " ";
    cout<<"\n";
}