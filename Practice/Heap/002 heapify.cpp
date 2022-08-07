#include <iostream>
#include <vector>

using namespace std;
void heapify(int arr[],int n,int index){
    int largest = index;
    int left = 2*index;
    int right = 2*index + 1;
    
    
    if(left < n && arr[largest] < arr[right]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right] ){
        largest = right;
    }
    
    if(largest != index){
        swap(arr[largest] , arr[index]);
        heapify(arr,n,largest);
    }
}
int main()
{
    int n = 5;
    int arr[6] = {-1,54,53,55,51,52};
    for(int i = n/2; i>0;i--){
        heapify(arr,n,i);
    }
    std::cout << "printing the heapify elements" << std::endl;
    for(int i = 1;i<=n;i++){
        cout << arr[i]<<" ";
    }cout<<endl;
    return 0;
}
