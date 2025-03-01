#include <iostream>;
#include <string.h>;
#include <math.h>;
using namespace std;

int main(){
	int n,s;
	s=0;
	int a[n];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i]==a[j]){
				s++;
			}
		}
	}
	cout << s;
}
