#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;
using Coord  = pair<int,int>;

double getDistance(const Coord &c1, const Coord &c2){
    const double xDist = c1.first-c2.first, yDist = c1.second-c2.second;
    return pow((xDist*xDist+yDist*yDist),0.5);
}

int main(){
    ifstream inputFile ("../coords.txt");
    vector<Coord> coords;
    
    //populate vector with input data
    int x,y;
    char t;
    while(inputFile>>x>>t>>y) coords.push_back(make_pair(x,y));
    inputFile.close();

    //run kruskal's on fully dense graph
    
}