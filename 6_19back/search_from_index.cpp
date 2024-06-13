#include <iostream>
#include <fstream>

using namespace std;

void change_index_to_data(string locate,string search_id){
    ifstream data_file;
    string read_string;
    data_file.open(locate);
    while (getline(data_file, read_string)){
        if (read_string.substr(0, read_string.find(",")).compare(search_id) == 0){
            //cout << read_string << endl;
            cout << read_string.substr(read_string.find(",")+1) << endl;
        }
    }
}

int main() {
    
    string search_string;

    while (cin>>search_string){
        
        ifstream index_file;
        index_file.open("index.txt");

        string index_string;
        
        int CHECK_END_OF_DATA_IN_INDEX = 0;
        int NO_DATA = 1;

        while (getline(index_file, index_string)){
            
            if (index_string.substr(0, index_string.find(" ")).compare(search_string) == 0){
                if (CHECK_END_OF_DATA_IN_INDEX == 0){
                    cout << "============================" << endl << "search : " << search_string << endl ;
                }

                //cout << index_string.substr(index_string.find(" ")+1) <<endl;
                change_index_to_data(index_string.substr(index_string.find(" ")+1),index_string.substr(0, index_string.find(" ")));
                CHECK_END_OF_DATA_IN_INDEX = 1;
                NO_DATA = 0;

            }
            else {
                if (CHECK_END_OF_DATA_IN_INDEX == 1){
                    CHECK_END_OF_DATA_IN_INDEX = 0;
                    cout << "============================" << endl ;
                    break;
                }
            }

        }  
        if (NO_DATA == 1){
            printf("Data Not Found\n");
        }
        else {
            NO_DATA = 1;
        }
    }
}