#include <iostream> 
using namespace std; 
// Ham dung de quy de tinh ucln 
// Dung thuat toan lay a = b va b = a%b cho den khi b == 0 thi a chinh la ucln
int ucln (int a, int b){ 
    if (b == 0 ) return a;
    else return ucln(b,a%b);
}
int main() {
    int a,b;
    // Nhap 2 so a b 
    cin >> a >> b;
    cout << ucln(a,b) <<endl;

}

