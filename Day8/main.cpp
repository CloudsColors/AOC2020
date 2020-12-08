#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// modified for solution 2 only.

int main()
{
    ifstream file("data.txt");
    string input;
    vector<tuple<string, int>> inputData;
    vector<int> lineDetection;
    int acc = 0;
    bool looped = true;
    int lastIndexChanged{0};

    while(getline(file, input))
    {
        int spaceIndex = input.find(" ");
        string op = input.substr(0, spaceIndex);
        int value = stoi(input.substr(spaceIndex+1, input.length()));
        inputData.push_back({op, value});
    }
    vector <tuple<string, int>> inputDataClone = inputData;
    // Added for solution 2
    while(looped)
    {
        acc = 0;
        lineDetection.clear();
        inputDataClone = inputData;
        for(int i = 0+lastIndexChanged; i < inputData.size(); i++)
        {
            string op;
            int value;
            tie(op, value) = inputDataClone[i];

            if(op == "nop")
            {
                //cout << "change\n";
                lastIndexChanged = i+1;
                inputDataClone[i] = {"jmp", value};
                break;
            }
            else if(op == "jmp")
            {
                //cout << "change\n";
                lastIndexChanged = i+1;
                inputDataClone[i] = {"nop", value};
                break;
            }
        }
        // end of added part for solution 2
        // solution part 1
        for(int i = 0; i < inputDataClone.size(); i++)
        {
            string op;
            int value;
            tie(op, value) = inputDataClone[i];

            if(find(lineDetection.begin(), lineDetection.end(), i) != lineDetection.end())
            {
                looped = true;
                break;
            }

            if(op == "nop")
            {
                lineDetection.push_back(i);
            }
            else if(op == "jmp")
            {
                i += value-1;
                lineDetection.push_back(i);
            }
            else
            {
                acc += value;
                lineDetection.push_back(i);
            }
            if(i >= 607)
            {
                looped = false;
            }
        }

        // end of part for solution 1 only
    }
    cout << "Acc is: " << acc;
}