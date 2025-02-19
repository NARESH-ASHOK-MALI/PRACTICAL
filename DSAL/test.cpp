#include<iostream>
#include<string>
using namespace std;
void heapify(int arr[], int n, int ind) {    
    int largest = ind;
    int n1 = 2 * ind + 1;
    int n2 = 2 * ind + 2;
    if (n1 < n && arr[largest] < arr[n1]) {
        largest = n1;
    }
    if (n2 < n && arr[largest] < arr[n2]) {
        largest = n2;
    }
    if (ind!=largest) {
        int temp = arr [ind];
        arr[ind] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }

}
int main(){
        cout<<"Enter size of the array:- "<<endl;
        int n ;
        cin>>n;
        cout<<" ";
        int arr[n];
        cout<<"Enter Elements of array: ";
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        int ct = 1;
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
            cout<<"Pass" << ct++ <<":-";
            for (int j = 0; j < n; j++) {
                cout<<arr[j] << " ";
            }
            cout<<endl;
        }
        cout<<"Final Sorted Array is :- ";
        for (int j = 0; j < n; j++) {
            cout<<arr[j] << " ";
        }
        cout<<endl;
    return 0;
}