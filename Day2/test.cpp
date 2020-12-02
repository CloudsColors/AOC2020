#include <fstream>
#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

vector<tuple<int, int, char, string>> parse_input(string filename)
{
    ifstream input_file;
    input_file.open(filename);

    vector<tuple<int, int, char, string>> passwords;
    while (!input_file.eof())
    {
        int num1, num2;
        char dash, colon;
        char character;
        string password;

        input_file >> num1 >> dash >> num2 >> character >> colon >> password;
        passwords.push_back(make_tuple(num1, num2, character, password));
    }

    input_file.close();

    return passwords;
}

int main(){
    auto passwords = parse_input("day2.txt");

    int a, b;
    char character;
    string password;

    for(auto pass : passwords){
        tie(a,b,character,password) =  pass;
        cout << a << ":" << b << ":" << character << ":" << password << "\n";
    }
}