#include <iostream>

using namespace std;

int main() {
	int n;
	cout << "Nhap kich thuoc mang n  = ";
	cin  >> n;
	int arr[n];
	int i;
	for (i = 0; i < n; i++) {
		cout << "Mhap phan tu mang thu " << i << ": ";
		cin >> arr[i];
	}
	int d = INT_MIN; // d la chieu rong toi da 
	int a = 0, b = 0, index_start = 0; // a la chieu rong toi da ban dau , b la chieu rong toi da sau cung 
	for ( i = 0; i < n; i++) {
		int sum = 0; int j;
		for(j = i; j < n; j++) {
			if (sum + arr[j] < arr[j]) {
				sum = arr[j];
				index_start = j;
			} else {
				sum += arr[j];
			}
			if (d < sum) {
				d = sum;
				a = index_start;
				b = j;
			}
		}
	}
    cout << d << "\n";
    cout << "bat dau tu " << a << " den " << b << "\n";
	return 0;
}

