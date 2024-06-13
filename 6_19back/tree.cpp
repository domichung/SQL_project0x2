#include <iostream>

using namespace std;

struct node {
    string data;
    node* left;
    node* right;
};

node* new_node(string student_id) {
    node* p = new node();
    p->data = student_id;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insert(node*& root, string student_id) {
    if (root == NULL) {
        root = new_node(student_id);
    } else {
        node* current = root;
        while (true) {
            if (student_id < current->data) {
                if (current->left == NULL) {
                    current->left = new_node(student_id);
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = new_node(student_id);
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

void in_order_traversal(node* root) {
    if (root != NULL) {
        in_order_traversal(root->left);
        cout << root->data << "\n";
        in_order_traversal(root->right);
    }
}

void delete_tree(node* root) {
    if (root != NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}

int main() {
    node* root = NULL;
    string student_id;
    while (cin >> student_id) {
        insert(root, student_id);
    }

    cout << endl;
    in_order_traversal(root);
    cout << endl;

    delete_tree(root);
}
