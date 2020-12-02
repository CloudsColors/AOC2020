#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int dayTwoSolutionOne()
{
    ifstream file("day2.txt");

    int lowerBound, higherBound;
    char dash,requirement,colon;
    string password;

    int validPasswords = 0;

    while(!file.eof())
    {
        file >> lowerBound >> dash >> higherBound >> requirement >> colon >> password;
        int occurences = 0;
        for(char x : password)
        {
            if(x == requirement){
                occurences++;
            }
        }
        if(occurences >= lowerBound && occurences <= higherBound)
        {
            validPasswords++;
        }
    }
    cout << "The number of valid passwords in the database is: " << validPasswords << "\n";
    return 0;
}

int dayTwoSolutionTwo()
{
    ifstream file("day2.txt");

    int lowerIndex, higherIndex;
    char dash,requirement,colon;
    string password;

    int validPasswords = 0;

    while(!file.eof())
    {
        file >> lowerIndex >> dash >> higherIndex >> requirement >> colon >> password;
        if(password[lowerIndex-1] == requirement ^ password[higherIndex-1] == requirement){
            validPasswords++;
        }
    }
    cout << "The number of valid passwords in the database is: " << validPasswords;
    return 0;
}