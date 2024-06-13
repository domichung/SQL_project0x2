#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip> 
#include <string>
#include <vector>

using namespace std;

void cut_input_data(string s, string arr[]) {
    istringstream iss(s);
    iss >> arr[0];
    getline(iss, arr[1]);
}


void cut_data_data(const string& input, string arr[]) {
    stringstream ss(input);
    string token;
    int MAX_ELEMENTS = 3;
    int count = 0;
    
    while (getline(ss, token, ',')) {
        if (count < MAX_ELEMENTS) {
            arr[count++] = token;
        } 
        else {
            break;
        }
    }
}