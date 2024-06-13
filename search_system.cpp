#include <iostream>
#include <fstream>
using namespace std;

#include "cut.cpp"
#include "cid_index_to_data.cpp"
#include "sid_index_to_data.cpp"
#include "name_index_to_data.cpp"

//#######################################################################################
//# 
//# 注意事項 檔案為big5編碼 若要使用中文索引請注意編碼問題
//# 模式說明
//# 1. 使用課程代碼搜尋
//# 2. 使用課程名稱搜尋
//# 3. 使用學生學號搜尋
//# 其他 關閉系統
//# 
//# 以簡單更新過 基礎 GUI
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
