#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip> 
#include <string>

#define READ_FILE_CUT_SIZE 3
#define DATA_COUNTER 466

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
    string course_id;
    string data_id;
    string class_name;
    node* left;
    node* right;
};

node* new_node(string course_id,string data_id ,string class_name) {
    node* p = new node();
    p->course_id = course_id;
    p->data_id = data_id;
    p->class_name = class_name;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insert(node*& root, string course_id, string data_id,string class_name) {
    if (root == NULL) {
        root = new_node(course_id ,data_id ,class_name);
    } else {
        node* current = root;
        while (true) {
            if (course_id < current->course_id) {
                if (current->left == NULL) {
                    current->left = new_node(course_id,data_id,class_name);
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = new_node(course_id,data_id,class_name);
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

string kill_same_locate;

void in_order_traversal(node* root, ofstream& output_file) {
    if (root != NULL) {
        in_order_traversal(root->left, output_file);
        string test = root->class_name + " " + root->data_id + "\n";
        if (test != kill_same_locate){
            output_file << test;
            kill_same_locate = test;    
        }
        in_order_traversal(root->right,output_file);
    }
}

int main(){
    ifstream reads_file;

    int data_counter = 1;
    string data_locate = "../data_big5/";
    
    node* root = NULL;

    int x = DATA_COUNTER;

    while (x--){
        stringstream ss;
        ss << data_locate << setw(4) << setfill('0') << data_counter;
        string data_locate = ss.str();
        data_counter++;

        reads_file.open(data_locate.c_str());

        if(reads_file.fail()){
    	    cout << "input file opening failed\n";
    	    exit(1);
        }
        else{
            string read_file_string;
            getline(reads_file, read_file_string);
            for (int i=0;i<1000;i++){
                if (getline(reads_file, read_file_string)){
                }
                else{
                    break;
                }
                string datacut[READ_FILE_CUT_SIZE];
                cut_input_data(read_file_string, datacut, READ_FILE_CUT_SIZE);
                insert(root,datacut[1],data_locate.c_str(),datacut[2]);
            }
        reads_file.close();
        }
    }

    ofstream output_file;
    output_file.open("../all_index/long/classname.txt");

    in_order_traversal(root, output_file);

    return 0;
}