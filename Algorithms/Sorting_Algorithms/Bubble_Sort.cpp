#include <iostream>

using namespace std;

void Bubble_Sort(int a[],int size);

int main(){
    int size = 5;
    int arr[size] = {8,2,22,4,5};
    Bubble_Sort(arr,size);
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}

void Bubble_Sort(int a[],int size){
    for(int i = 0;i<size - 1;i++){
        bool isSorted = true;
        for(int j = 0;j<size-i-1;j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = false;
            }
        }
        if(isSorted){
            break;
        }
    }
}