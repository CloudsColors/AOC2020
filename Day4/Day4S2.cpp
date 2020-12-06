#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <unordered_map>

using namespace std;

bool checkPassportValues(string key, string value){
    if(key == "byr")
    {
        if(value.length() > 4 || value.length() < 4)
        {
            return false;
        }
        if(stoi(value) > 2002 || stoi(value) < 1920)
        {
            return false;
        }
    }
    else if(key == "iyr")
    {
        if(value.length() > 4 || value.length() < 4)
        {
            return false;
        }
        if(stoi(value) > 2020 || stoi(value) < 2010){
            return false;
        }
    }
    else if(key == "eyr")
    {
        if(!(value.length() == 4))
        {
            return false;
        }
        if(stoi(value) > 2030 || stoi(value) < 2020)
        {
            return false;
        }
    }
    else if(key == "hgt")
    {
        if(value.substr(value.length()-2, value.length()-1) == "cm")
        {
            if(stoi(value) < 150 || stoi(value) > 193)
            {
                return false;
            }
        }
        else
        {
            if(stoi(value) < 59 || stoi(value) > 76)
            {
                return false;
            }
        }
    }
    else if(key == "hcl")
    {            
        if(!(value[0] == '#'))
        {
            return false;
        }
        for(int i = 1; i < value.length(); i++)
        {
            if(value[i] - '0' < 0 && value[i] - '0' > 9 || value[i] - 'a' < 0 && value[i] - 'a' > 5)
            {
                return false;
            }
        }
    }
    else if(key == "ecl")
    {
        if(!(value == "amb" || value == "blu" || value == "brn" || value == "gry" || value == "grn" || value == "hzl" || value == "oth"))
        {
            return false;
        }
    }
    else if(key == "pid")
    {
        if(value.length() < 9 || value.length() > 9)
        {
            return false;
        }
        for(char c : value)
        {
            if(c - '0' < 0 || c - '0' > 9)
            {
                return false;
            }
        }
    }
    else if(key == "cid")
    {
        return true;
    }
    return true;
}

bool checkPassportFields(unordered_map<string, string> *passportData)
{
    vector<string> nescessaryInformation = 
        {"hcl", "iyr", "hgt", "eyr", "pid", "ecl", "byr"};
    for(string requiredField : nescessaryInformation)
    {
        if(passportData->find(requiredField) != passportData->end())
        {
            if(checkPassportValues(requiredField, passportData->at(requiredField)))
            {
                continue;
            }
            else
            {
                return false;
            } 
        }
        else{
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream file("data.txt");
    unordered_map<string, string> passportData;
    char delimiter = ':';
    string line;
    int validPassports = 0;

    while(file >> line)
    {
        string key = line.substr(0, line.find(delimiter));
        string value = line.substr(line.find(delimiter)+1, line.length()-1); 
        passportData[key] = value;
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