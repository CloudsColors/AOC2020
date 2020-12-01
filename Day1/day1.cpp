#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; // std:: is implied.

int dayOneSolutionOne()
{
    vector<int> inputs;
    int temp;
    unordered_map<int, int> cache;
    int index1;
    int index2;

    while (cin >> temp) 
    {
        inputs.push_back(temp);
    }
    for(int i = 0; i < inputs.size(); i++)
    {
        int number_needed = 2020 - inputs[i];
        if(cache.find(number_needed) != cache.end()){
            // we found a number
            index1 = i;
            index2 = cache[number_needed];
            break;
        }else{
            cache[inputs[i]] = i;
        }
    }
    cout << inputs[index1] << " and " << inputs[index2] << " which multiplies to " << inputs[index1]*inputs[index2];
	return 0;
}

int dayOneSolutionTwo()
{
    vector<int> inputs;
    int temp;
    unordered_map<int, int> cache;
    int index1;
    int index2;
    int index3;

    while (cin >> temp) 
    {
        inputs.push_back(temp);
    }
    for(int i = 0; i < inputs.size(); i++)
    {
        int first_subtraction = 2020 - inputs[i];
        for(int z = i+1; z < inputs.size(); z++){
            int number_needed = first_subtraction - inputs[z];
            if(number_needed < 0){
                continue;
            }
            if(cache.find(number_needed) != cache.end()){
                // we found a number
                index1 = i;
                index2 = cache[number_needed];
                index3 = z;
                break;
            }else{
                cache[inputs[i]] = i;
            }
        }
    }
    cout << inputs[index1] << ", " << inputs[index2] << " and " << inputs[index3] << " which multiplies to " << inputs[index1]*inputs[index2]*inputs[index3];
	return 0;
}

int main(){
    dayOneSolutionTwo();
}