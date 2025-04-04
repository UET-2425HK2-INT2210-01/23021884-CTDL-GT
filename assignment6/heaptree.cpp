#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Lop MinHeap de quan ly heap (Heap nhi phan nho nhat)
class MinHeap {
private:
    vector<int> heap; // Vector luu tru cac phan tu cua heap
    
    // Ham dua mot phan tu len vi tri dung trong heap (Heapify Up)
    void heapifyUp(int index) {
        while (index > 0) { // Lap den khi nut nam o goc
            int parent = (index - 1) / 2; // Tinh chi so nut cha
            if (heap[index] < heap[parent]) { // Neu phan tu hien tai nho hon cha, hoan doi vi tri
                swap(heap[index], heap[parent]);
                index = parent; // Cap nhat vi tri moi de tiep tuc kiem tra
            } else {
                break; // Dung lai neu vi tri dung
            }
        }
    }
    
    // Ham dua mot phan tu xuong vi tri dung trong heap (Heapify Down)
    void heapifyDown(int index) {
        int size = heap.size();
        while (2 * index + 1 < size) { // Neu nut hien tai co con trai thi tiep tuc
            int left = 2 * index + 1; // Chi so con trai
            int right = 2 * index + 2; // Chi so con phai
            int smallest = left; // Mac dinh con trai la nho nhat
            
            if (right < size && heap[right] < heap[left]) { // Neu con phai nho hon con trai
                smallest = right;
            }
            
            if (heap[index] > heap[smallest]) { // Neu nut hien tai lon hon con nho nhat, hoan doi
                swap(heap[index], heap[smallest]);
                index = smallest; // Cap nhat vi tri moi de tiep tuc kiem tra
            } else {
                break; // Dung lai neu vi tri dung
            }
        }
    }
    
public:
    // Ham chen mot phan tu vao heap
    void insert(int val) {
        heap.push_back(val); // Them phan tu vao cuoi vector
        heapifyUp(heap.size() - 1); // Dua phan tu nay len vi tri dung
    }
    
    // Ham xoa mot phan tu khoi heap
    void deleteValue(int val) {
        auto it = find(heap.begin(), heap.end(), val); // Tim vi tri cua phan tu trong heap
        if (it != heap.end()) { // Neu tim thay phan tu can xoa
            int index = distance(heap.begin(), it); // Lay chi so cua phan tu
            swap(heap[index], heap.back()); // Doi phan tu can xoa voi phan tu cuoi
            heap.pop_back(); // Xoa phan tu cuoi cung
            heapifyDown(index); // Dua phan tu moi vao vi tri dung bang Heapify Down
        }
    }
    
    // Ham in heap hien tai
    void printHeap() {
        for (int val : heap) { // Duyet qua tung phan tu trong heap
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap; // Tao mot doi tuong MinHeap
    vector<int> initialValues = {2, 1, 10, 6, 3, 8, 7, 13, 20}; // Danh sach so ban dau
    
    // Them cac phan tu ban dau vao heap
    for (int val : initialValues) heap.insert(val);
    cout << "Heap ban dau: ";
    heap.printHeap(); // In heap sau khi khoi tao
    
    // Them cac gia tri moi vao heap
    vector<int> insertValues = {14, 0, 35}; // Danh sach gia tri can chen
    for (int val : insertValues) heap.insert(val);
    cout << "Heap sau khi chen: ";
    heap.printHeap(); // In heap sau khi chen
    
    // Xoa cac gia tri khoi heap
    vector<int> deleteValues = {6, 13, 35}; // Danh sach gia tri can xoa
    for (int val : deleteValues) heap.deleteValue(val);
    cout << "Heap sau khi xoa: ";
    heap.printHeap(); // In heap sau khi xoa
    
    return 0; // Ket thuc chuong trinh
}
