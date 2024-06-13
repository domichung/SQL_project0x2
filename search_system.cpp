#include <iostream>
#include <fstream>
using namespace std;

#include "cut.cpp"
#include "cid_index_to_data.cpp"
#include "sid_index_to_data.cpp"
#include "name_index_to_data.cpp"

//#######################################################################################
//# 
//# �`�N�ƶ� �ɮ׬�big5�s�X �Y�n�ϥΤ�����޽Ъ`�N�s�X���D
//# �Ҧ�����
//# 1. �ϥνҵ{�N�X�j�M
//# 2. �ϥνҵ{�W�ٷj�M
//# 3. �ϥξǥ;Ǹ��j�M
//# ��L �����t��
//# 
//# �H²���s�L ��¦ GUI
//# 
//#######################################################################################


int main(){

    char searchmode;
    
    while (true){
        cout << "choose mode" << endl;
        cout << "1. use course_num  to search" << endl;
        cout << "2. use course_name to search" << endl;
        cout << "3. use students_id to search" << endl;
        cout << "else. exit" << endl;
        cin >> searchmode;
        
        if (searchmode != '1' && searchmode != '2' && searchmode != '3'){
            break;
        }

        string search_string;
        cout << "input search string" << endl;
        cin >> search_string;

        if (searchmode == '1'){
            cout << "===============================================" << endl;
            cout << "search course number = " << search_string << endl;
            cid_to_data(search_string);
            cout << "===============================================" << endl;
            cout << "search finish press any key to continue" << endl;
            cin >> search_string;
        }
        else if (searchmode == '2'){
            cout << "===============================================" << endl;
            cout << "search course name = " << search_string << endl;
            name_to_data(search_string);
            cout << "===============================================" << endl;
            cout << "search finish press any key to continue" << endl;
            cin >> search_string;
        }
        else if (searchmode == '3'){
            cout << "===============================================" << endl;
            cout << "search student id = " << search_string << endl;
            sid_to_data(search_string);
            cout << "===============================================" << endl;
            cout << "search finish press any key to continue" << endl;
            cin >> search_string;
        }
        system("cls");
    }
}
