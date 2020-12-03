#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int dayThreeSolutionOne()
{
    ifstream input("data.txt");
    string eachLevel;
    int xPos, nrOfTrees = 0;

    while(getline(input, eachLevel))
    {
        if(xPos >= eachLevel.length()) xPos -= eachLevel.length();
        if(eachLevel[xPos] == '#') nrOfTrees++;
        xPos += 3;
    }
    cout << "Number of trees on this slope is: " << nrOfTrees << "\n";
    return 0;
}

int dayThreeSolutionTwo(){
    ifstream input("data.txt");
    string eachLevel;
    vector<string> map;
    int xPos, nrOfTrees = 0;
    vector<int> dx = {1,3,5,7,1};
    vector<int> dy = {1,1,1,1,2};
    vector<int> result;

    while(getline(input, eachLevel))
    {
        map.push_back(eachLevel);        
    }
    for(int i = 0; i < dx.size(); i++){
        for(int z = 0; z < map.size(); z+=dy[i]){
            if(xPos >= map[z].length()) xPos -= map[z].length();
            if(map[z][xPos] == '#') nrOfTrees++;
            xPos += dx[i];
        }
        xPos = 0;
        result.push_back(nrOfTrees);
        nrOfTrees = 0;
    }
    long long results = 1;
    for(int x : result){
        results = results * x;
    }
    cout << "The result is: " << results << "\n";
    return 0;
}