#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//checks if vector is sorted
bool isSorted(const vector<int> &orderedInts){
    for(size_t i = 0; i<orderedInts.size()-1; ++i){
        if(orderedInts[i] > orderedInts[i+1]) return false;
    }
    return true;
}

//randomizes order of vector
void randomize(vector<int> &unorderedInts){
    for(int &num:unorderedInts)
        swap(num,unorderedInts[rand() % unorderedInts.size()]);
}

int main(){
    ifstream unsortedData ("testinput.txt");
    vector<int> unsortedInts;
    
    //populate vector with input data
    int temp;
    while(unsortedData>>temp) unsortedInts.push_back(temp);
    unsortedData.close();

    //sort vector
    while(!isSorted(unsortedInts)) randomize(unsortedInts);

    //print vector
    for(int num:unsortedInts)
        cout << num << " ";
    cout<<"\n";
}