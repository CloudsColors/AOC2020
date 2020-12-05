#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <unordered_map>

using namespace std;

int checkPassportFields(vector<string> *passportData)
{
    vector<string> nescessaryInformation = 
        {"hcl", "iyr", "hgt", "eyr", "pid", "ecl", "byr"};
    bool foundHit = false;
    for(string requiredFields : nescessaryInformation)
    {
        foundHit = false;
        for(string field : *passportData)
        {
            if(field == requiredFields)
            {
                foundHit = true;
                break;
            }
        }
        if(foundHit == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    ifstream file("data.txt");

    vector<string> passportData;

    char delimiter = ':';
    string line;
    int validPassports = 0;

    while(file >> line)
    {
        passportData.push_back(line.substr(0, line.find(delimiter)));
        if(file.peek() == '\n' || file.eof())
        {
            file.get();
            if(file.peek() == '\n' || file.eof())
            {
                if(checkPassportFields(&passportData)) validPassports++;
                passportData.clear();
            }
        }
    }
    cout << validPassports << " number of valid passports!\n"; 
    return 0;
}