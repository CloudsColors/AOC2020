#include <iostream>
#include <string>

using namespace std;



int dayTwoSolutionOne()
{
    string temp;
    int iterations = 1;

    int lowerBound;
    int higherBound;
    string password;
    char requirement;

    int validPasswords = 0;

    while(cin >> temp)
    {
        if(iterations % 3 == 1)
        {
            lowerBound = stoi(temp.substr(0, temp.find("-")));
            higherBound = stoi(temp.substr(temp.find("-")+1, temp.length()));
            iterations++;
            continue;
        }
        else if(iterations %3 == 2)
        {
            requirement = temp[0];
            iterations++;
            continue;
        }
        else
        {
            password = temp;
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
            iterations = 1;
        }
    }
    cout << "The number of valid passwords in the database is: " << validPasswords << "\n";
    return 0;
}

/*
example input:

1-3 a: abcde
1-3 b: cdefg
2-9 c: ccccccccc
9-17 s: sssssssstssssssscss
16-19 t: tttttttttttttttttttt
1-2 s: svvsnsk
3-5 z: zzzzz
*/

int main()
{
    string temp;
    int iterations = 1;

    int lowerBound;
    int higherBound;
    string password;
    char requirement;

    int validPasswords = 0;

    while(cin >> temp)
    {
        if(iterations % 3 == 1)
        {
            lowerBound = stoi(temp.substr(0, temp.find("-")));
            higherBound = stoi(temp.substr(temp.find("-")+1, temp.length()));
            iterations++;
            continue;
        }
        else if(iterations %3 == 2)
        {
            requirement = temp[0];
            iterations++;
            continue;
        }
        else
        {
            password = temp;
            if(password[lowerBound-1] == requirement ^ password[higherBound-1] == requirement){
                validPasswords++;
            }
            iterations = 1;
            continue;
        }
    }
    cout << "The number of valid passwords in the database is: " << validPasswords;
    return 0;
}