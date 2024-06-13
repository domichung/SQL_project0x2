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

struct node {
    string data_student_id;
    string data_id;
    node* left;
    node* right;
};

node* new_node(string student_id,string data_id) {
    node* p = new node();
    p->data_student_id = student_id;
    p->data_id = data_id;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insert(node*& root, string student_id, string data_id) {
    if (root == NULL) {
        root = new_node(student_id ,data_id);
    } else {
        node* current = root;
        while (true) {
            if (student_id < current->data_student_id) {
                if (current->left == NULL) {
                    current->left = new_node(student_id,data_id);
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = new_node(student_id,data_id);
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

void in_order_traversal(node* root, ofstream& output_file) {
    if (root != NULL) {
        in_order_traversal(root->left, output_file);
        output_file << root->data_student_id << " " << root->data_id << "\n";
        in_order_traversal(root->right,output_file);
    }
}

int main(){
    ifstream reads_file;

    int data_counter = 1;
    string data_locate = "./data_big5/";
    
    node* root = NULL;

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
            getline(reads_file, read_file_string);
            //reads_file>>read_file_string;
            //trashcan of first line
            for (int i=0;i<1000;i++){
                //reads_file>>read_file_string;
                if (getline(reads_file, read_file_string)){
                }
                else{
                    break;
                }
                string datacut[READ_FILE_CUT_SIZE];
                cut_input_data(read_file_string, datacut, READ_FILE_CUT_SIZE);
                /*if (datacut[0][0] != 'D') {
                    printf("datacut[0]: %s from %s\n", datacut[0].c_str(),data_locate.c_str());
                    continue;
                }*/
                // fuck up de bug wasn full data
                /*for (int i = 0; i < READ_FILE_CUT_SIZE; ++i) {
                    cout << datacut[i] << endl;
                }*/
                //test cut 
                insert(root,datacut[0],data_locate.c_str());
            }
        reads_file.close();
        }
    }

    ofstream output_file;
    output_file.open("index.txt");

    in_order_traversal(root, output_file);

    return 0;
}