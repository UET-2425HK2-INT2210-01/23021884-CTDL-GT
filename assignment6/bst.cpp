#include <iostream>
using namespace std;

// Dinh nghia cau truc cua mot nut trong cay BST
struct Node {
    int data; // Gia tri cua nut
    Node* left; // Con tro tro den cay con trai
    Node* right; // Con tro tro den cay con phai
    Node(int val) : data(val), left(NULL), right(NULL) {} // Ham khoi tao nut
};

// Ham chen mot gia tri vao BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val); // Neu cay rong, tao mot nut moi
    if (val < root->data) root->left = insert(root->left, val); // Neu gia tri nho hon, chen vao cay con trai
    else root->right = insert(root->right, val); // Neu lon hon, chen vao cay con phai
    return root;
}

// Ham tim phan tu nho nhat trong cay con ben phai
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) current = current->left; // Duyet ve phia trai den nut nho nhat
    return current;
}

// Ham xoa mot gia tri khoi BST
Node* deleteNode(Node* root, int val) {
    if (!root) return root; // Neu cay rong, tra ve NULL
    if (val < root->data) root->left = deleteNode(root->left, val); // Neu gia tri nho hon, tim trong cay con trai
    else if (val > root->data) root->right = deleteNode(root->right, val); // Neu lon hon, tim trong cay con phai
    else {
        // Truong hop nut co toi da mot con
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Truong hop nut co hai con: tim gia tri nho nhat o cay con phai
        Node* temp = minValueNode(root->right);
        root->data = temp->data; // Gan gia tri nho nhat cho nut can xoa
        root->right = deleteNode(root->right, temp->data); // Xoa gia tri da sao chep
    }
    return root;
}

// Ham in cay theo thu tu trung to (LNR: Left - Node - Right)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left); // Duyet cay con trai
    cout << root->data << " "; // In gia tri cua nut
    inorder(root->right); // Duyet cay con phai
}

int main() {
    Node* root = NULL; // Khoi tao cay rong
    int initialValues[] = {2, 1, 10, 6, 3, 8, 7, 13, 20}; // Mang chua cac gia tri ban dau
    for (int val : initialValues) root = insert(root, val); // Chen tung gia tri vao cay
    
    cout << "BST ban dau: ";
    inorder(root); // In cay BST ban dau
    cout << endl;

    int insertValues[] = {14, 0, 35}; // Mang chua cac gia tri can chen
    for (int val : insertValues) root = insert(root, val); // Chen cac gia tri vao cay
    cout << "BST sau khi chen: ";
    inorder(root); // In cay BST sau khi chen
    cout << endl;

    int deleteValues[] = {6, 13, 35}; // Mang chua cac gia tri can xoa
    for (int val : deleteValues) root = deleteNode(root, val); // Xoa tung gia tri khoi cay
    cout << "BST sau khi xoa: ";
    inorder(root); // In cay BST sau khi xoa
    cout << endl;
    
    return 0; // Ket thuc chuong trinh
}

