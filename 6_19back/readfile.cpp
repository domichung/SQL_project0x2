#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip> 
#include <string>
#define READ_FILE_CUT_SIZE 3
using namespace std;

void cut_input_data(string s, string arr[], int size) {
    size_t start = 0;
    size_t end = s.find(",");
    int index = 0;

    while (end != string::npos && index < size) {
        arr[index++] = s.substr(start, end - start);
        start = end + 1;
        end = s.find(",", start);
    }

    if (index < size) {
        arr[index] = s.substr(start);
    }
}

int main(){
    ifstream reads_file;

    int data_counter = 1;
    string data_locate = "./data_big5/";
    
    int x = 466;

    while (x--){

        stringstream ss;
        ss << data_locate << setw(4) << setfill('0') << data_counter;
        string data_locate = ss.str();
        //printf("locate: %s\n", data_locate.c_str());
        data_counter++;
        // ==============================================

        reads_file.open(data_locate.c_str());
        if(reads_file.fail()){
    	    cout << "input file opening failed\n";
    	    exit(1);
        }
        else{
        string read_file_string;
        reads_file>>read_file_string;
        for (int i=0;i<2;i++){
            reads_file>>read_file_string;

            string datacut[READ_FILE_CUT_SIZE];
    
            cut_input_data(read_file_string, datacut, READ_FILE_CUT_SIZE);
            
            /*for (int i = 0; i < READ_FILE_CUT_SIZE; ++i) {
                cout << datacut[i] << endl;
            }*/
            
        }
        reads_file.close();
        }
    }

    return 0;
}