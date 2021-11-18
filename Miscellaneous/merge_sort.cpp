#include<iostream>
using namespace std;

void merge(int arr[], int l, int r) {
	
	int mid = (l + r) / 2;
	
	int i = l, j = mid + 1, idx = 0, size = r - l + 1;
	int tmp[size];
	
	while(i <= mid and j <= r) {
		if(arr[i] < arr[j]) {
			tmp[idx++] = arr[i++];
		} else {
			tmp[idx++] = arr[j++];
		}
	}
	
	while(i <= mid) {
		tmp[idx++] = arr[i++];
	}
	
	while(j <= r) {
		tmp[idx++] = arr[j++];
	}
	
	for(int i = 0; i < size; i++) {
		arr[i + l] = tmp[i];
	}
}

void msort(int arr[], int l, int r) {
	
	if(l < r) {
		int mid = (l + r) / 2;
		
		msort(arr, l, mid);
		msort(arr, mid + 1, r);
		
		merge(arr, l, r);
	}
}

int main() {
	
	int n;
	cin >> n;
	
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	msort(arr, 0, n - 1);
	
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	return 0;
}
