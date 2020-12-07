#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    ifstream file("data.txt");

    string input;
    unordered_map<string, vector<tuple<int, string>>> containerMapping;
    vector<string> contain;
    vector<string> duplicationCheck;
    int count = 0;
    int sumBagsHold = 0;

    // Collect data
    while(getline(file, input))
    {
        stringstream ss(input);
        string buff;
        vector<string> inputArray;
        while(ss >> buff)
        {
            inputArray.push_back(buff);
        }
        string bagHolder = inputArray[0] + " " + inputArray[1];
        for(int i = 0; i < inputArray.size(); i++)
        {
            if(find(inputArray.begin(), inputArray.end(), "no") != inputArray.end()){
                break;
            }
            if(inputArray[i] == "contain" || inputArray[i] == "bag," || inputArray[i] == "bags,")
            {
                string bagFitsIn = inputArray[i+2] + " " + inputArray[i+3];
                int nrOfBags = stoi(inputArray[i+1]);
                containerMapping[bagFitsIn].push_back({nrOfBags, bagHolder});
            }
        }
    }
    // solution 1
    contain.push_back("shiny gold");
    while(contain.size() > 0)
    {
        for(auto &tup : containerMapping[contain[0]])
        {
            string s;
            int nrOfBags;
            tie(nrOfBags, s) = tup;
            if(find(duplicationCheck.begin(), duplicationCheck.end(), s) != duplicationCheck.end()){
                continue;
            }
            duplicationCheck.push_back(s);
            contain.push_back(s);
            count++;
        }
        contain.erase(contain.begin());
    }
    // solution 2
    vector<tuple<string, int>> containBag;
    containBag.push_back({"shiny gold", 1});
    while(containBag.size() > 0)
    {
        string currentBag;
        int multiplier;
        tie(currentBag, multiplier) = containBag[0];
        for(auto &it : containerMapping)
        {
            int addedBags = 0;
            for(auto &tup : it.second)
            {
                string s;
                int nrOfBags;
                tie(nrOfBags, s) = tup;
                if(s == currentBag)
                {
                    cout << it.first << " " << s << " nrOfBags: " << nrOfBags << "\n";
                    addedBags += nrOfBags;
                    containBag.push_back({it.first, nrOfBags*multiplier});
                }
            }
            sumBagsHold += (addedBags*multiplier);
        }
        containBag.erase(containBag.begin());
    }
    cout << "The number of bags that eventually contain at least one shiny bag is: " << count << " and the number of bags a shiny gold can hold is: " << sumBagsHold << "\n";
    return 0;
}