#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip> 
#include <string>
#include <vector>


using namespace std;

void name_change_index_to_data(string str[]){
    ifstream data_file;
    string read_string;
    str[1].erase(str[1].find_first_of('.'), 1);
    data_file.open(str[1].substr(1));
    while (getline(data_file, read_string)){
        string temp[3];
        cut_data_data(read_string, temp);
        if (temp[2] == str[0]){
            cout << temp[0] << " " << temp[1]<< endl;
        }
    }
}

void name_to_data(string search) {
    cout<<search<<endl;
    int check_search_success = 0;
    int data_counter = 0;
    ifstream reads_file;
    string index_dir = "./all_index/index_classname/";
    while (true){

        stringstream ss;
        data_counter++;
        ss << index_dir << setw(4) << setfill('0') << data_counter <<".txt";
        string data_locate = ss.str();
        
        reads_file.open(data_locate.c_str());

        if(reads_file.fail()){
            break;
        }
        else {
            string read_file_string;
            while(getline(reads_file, read_file_string)){
                string hold_to_compare[2];
                cut_input_data(read_file_string, hold_to_compare);
                if(hold_to_compare[0] == search){
                    name_change_index_to_data(hold_to_compare);
                    check_search_success = 1;
                }
                else if ( check_search_success == 1 ) {
                    check_search_success = 3;
                    break;
                }
            }
            reads_file.close();
        }

        if (check_search_success == 3){
            break;
        }

    }
    if (check_search_success == 0){
        cout << "Data not found" << endl;
    }
}