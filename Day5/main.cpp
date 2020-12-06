#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int dayFiveSolution()
{
    ifstream file("data.txt");
    string boardingPass;
    vector<int> planeSeating(1000, 0);
    int highestSeatID = 0;

    while(file >> boardingPass)
    {
        int upperHalf = 0b01111111;
        int lowerHalf = 0b00000000;
        int row, column, seatID;
        //cout << "Upper half: " << upperHalf << "\n";
        for(int i = 0; i < boardingPass.length()-4; i++)
        {
            if(boardingPass[i] == 'F')
            {
                upperHalf -= (1 << 6-i);
            }
            else
            {
                lowerHalf += (1 << 6-i); 
            }
        }
        row = (boardingPass[6] == 'F')?lowerHalf:upperHalf;
        upperHalf = 0b0111;
        lowerHalf = 0b0000;
        for(int i = 7; i < boardingPass.length()-1; i++)
        {
            if(boardingPass[i] == 'L')
            {
                upperHalf -= (1 << 9-i);
            }
            else
            {
                lowerHalf += (1 << 9-i);
            }
        }
        column = (boardingPass[9] == 'L')?lowerHalf:upperHalf;
        seatID = row*8+column;
        planeSeating[seatID] = seatID;
        highestSeatID = (highestSeatID<seatID)?seatID:highestSeatID;
    }
    for(int i = 0; i < planeSeating.size()-1; i++)
    {
        if(planeSeating[i] - planeSeating[i+1] > 0 && i < highestSeatID){
            cout << "Your seatID is: " << i+1 << "\n";
        }
    }
    cout << "Highest seat ID was: " << highestSeatID << "\n";
    return 0;
}