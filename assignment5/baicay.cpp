#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Khoi tao nut 
struct TreeNode {
    int value;      // gia tri cua nut 
    TreeNode* left; // con trai cua nut 
    TreeNode* right; // con phai cua nut 
    
    // Khoi tao gia tri nut 
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Xay dung cay 
TreeNode* buildTree(int N, const vector<pair<int, int>>& edges) {
    vector<TreeNode*> nodes(N + 1, nullptr);  // nodes[i] là con tro den nut i
    
    // Khoi tao cac nut cay tu 1 den N
    for (int i = 1; i <= N; ++i) {
        nodes[i] = new TreeNode(i); // Moi nut co gia tri la i
    }
    
    // Duyet cac cap nut cha con
    for (const auto& edge : edges) {
        int parent = edge.first;  // Lay gia tri nut cha
        int child = edge.second;  // Lay gia tri nut con
        
        // Neu nut cha chua co con gan vao con trai
        if (nodes[parent]->left == nullptr) {
            nodes[parent]->left = nodes[child];
        } else {
            // neu nut cha co con trai gan vao con phai
            nodes[parent]->right = nodes[child];
        }
    }
    
    return nodes[1]; // Goc cay la nut co 1 chi so 
}

// ham tinh chieu cao cay
int getHeight(TreeNode* root) {
    if (root == nullptr) return 0; // Neu cay rong chieu cao la 0
    // Tinh chieu cao cay con trai va phai roi lay gia tri lon hon cong them 1
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

// Ham duyet cay the preorder
void preorder(TreeNode* root) {
    if (root == nullptr) return; // Neu cay rong, khong lam gi ca
    cout << root->value << " "; // In gia tri cua nut goc
    preorder(root->left);  // Duyet cay con trai
    preorder(root->right); // Duyet cay con phai
}

// Ham duyet cay theo postorder 
void postorder(TreeNode* root) {
    if (root == nullptr) return; // Neu cay rong, khong lam gi ca
    postorder(root->left);  // Duyet cay con trai
    postorder(root->right); // Duyet cay con phai
    cout << root->value << " "; // In gia tri cua nut goc sau khi duyet cay con
}

// Ham duyet cay theo inorder
void inorder(TreeNode* root) {
    if (root == nullptr) return; // Neu cay rong, khong lam gi ca
    inorder(root->left); // Duyet cay con trai
    cout << root->value << " "; // In gia tri nut goc
    inorder(root->right); // Duyet cay con phai
}

// Ham kiem tra xem co phai cay nhi phan khong
bool isBinaryTree(TreeNode* root) {
    if (root == nullptr) return true; // Cay rong la cay nhi phan hop le 
    int childCount = 0; // Dem so luong con cua nut hien tai 
    
    // Kiem tra nut hien tai co con trai 
    if (root->left) childCount++;
    
    // Kiem tra neu nut hien tai co con phai 
    if (root->right) childCount++;
    
    // Neu nut hien tai co qua 2 con thi khong phai cay nhi phan
    return (childCount <= 2) && isBinaryTree(root->left) && isBinaryTree(root->right);
}

int main() {
    int N, M;
    cin >> N >> M;
    
    // khoi tao vector cho cap cha con 
    vector<pair<int, int>> edges(M);
    
    // Nhap vao cac gia tri
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    // Xay dung tu cac cap cha con 
    TreeNode* root = buildTree(N, edges);

    // Tinh va in ra chieu cao cua cay
    cout << getHeight(root) << endl;
    // In preorder 
    preorder(root);
    cout << endl;

    // In postorder
    postorder(root);
    cout << endl;

    // Kiem tra co phai cay nhi phan hay khong
    if (isBinaryTree(root)) {
        inorder(root);
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl;
    }

    return 0;
}
 
