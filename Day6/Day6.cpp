#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

int Day6Solution()
{
    ifstream file("data.txt");

    string input;
    unordered_map<char, int> group;

    int sumSolutionOne{0}, sumSolutionTwo{0}, nrOfPeople{0};

    while(file >> input)
    {
        nrOfPeople++;
        for(char c : input)
        {
            group[c] += 1;
        }
        if(file.peek() == '\n' || file.eof())
        {
            file.get();
            if(file.peek() == '\n' || file.eof())
            {
                for(auto &it : group)
                {
                    if(it.second == nrOfPeople)
                    {
                        sumSolutionTwo++;
                    }
                }
                sumSolutionOne += group.size();
                nrOfPeople = 0;
                group.clear();
            }
        }
    }
    cout << "Sum for solution one is: " << sumSolutionOne << "\nSum for solution two is: " << sumSolutionTwo << "\n";
}