#include <iostream>

using namespace std;

void Selection_Sort(int a[],int size);

int main(){
    int size = 5;
    int arr[size] = {8,2,22,4,5};
    Selection_Sort(arr,size);
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}

void Selection_Sort(int a[],int size){
    for(int i = 0;i<size - 1;i++){
    int max_index = 0;
        for(int j = 1;j<size - i;j++){
            if(a[j] > a[max_index]){
                max_index = j;
            }
        }
        int temp = a[size - i - 1];
        a[size - i - 1] = a[max_index];
        a[max_index] = temp;
    }
}