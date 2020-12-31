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

    //run prim's on fully dense graph
    vector<pair<double,bool> > connections(coords.size(),make_pair(numeric_limits<double>::infinity(),false));
    size_t discovered =0;
    cout<<discovered<<" ";
    for(size_t numDisc = 1; numDisc<coords.size();++numDisc){
        connections[discovered] = make_pair(numeric_limits<double>::infinity(),true);
        for(size_t index = 1; index<coords.size();++index){
            if(connections[index].second) continue;
            const double distance = getDistance(coords[index],coords[discovered]);
            if(connections[index].first > distance)
                connections[index].first = distance;
        }
        auto minPtr = min_element(connections.begin()+1,connections.end(),[](const pair<double,bool> c1,const pair<double,bool> c2){
            return c1.first<c2.first;
        });
        discovered = minPtr-connections.begin();
        cout<<discovered<<" ";
    }
    cout<<"\n";
}