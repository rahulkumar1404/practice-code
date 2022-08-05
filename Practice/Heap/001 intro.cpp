#include <iostream>

using namespace std;

class Heap{
    public:
        int arr[10000];
        int size;
        
        Heap(){
            arr[0] = -1;
            size = 0;
        }
        void insert(int val){
            size = size + 1;
            int index = size;
            arr[index] = val;
            while(index > 1){
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }else return;
            }
        }
        void print(){
            for(int i = 1;i<=size;i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }
        void deleteFromHeap(){
            if(size <= 0){
                cout<<"Nothing to delete"<<endl;
                return;
            }
            arr[1] = arr[size];
            size--;
            int i = 1;
            while(i<size){
                int left = 2*i;
                int right = 2*i +1;
                int temp = i;
                if(left <= size && arr[temp] < arr[left]){
                    temp = left;
                }
                if(right <= size && arr[temp] < arr[right]){
                    temp = right;
                }
                if(arr[temp] > arr[i]){
                    swap(arr[temp],arr[i]);
                    i = temp;
                }
                else return;
            }
        }
};
int main()
{
    Heap h;
    std::cout << "enter the size for creating heap " << std::endl;
    int n;
    std::cin >> n;
    std::cout << "enter the values wanted to store in Heap" << std::endl;
    int val;
    for(int i = 1;i<=n;i++){
        cin>>val;
        h.insert(val);
    }
    h.print();
    std::cout << "enter the number of elements you wanted to be delete" << std::endl;
    int d;
    cin>>d;
    for(int i = 1;i<=d;i++){
        h.deleteFromHeap();
        std::cout << "Deleteion succesfully at index = "<< i <<" elements " << std::endl;
        h.print();
    }
    return 0;
}
/*
T.C for Inseration O(log n)

T.c for Deleteion O(logn)
enter the size for creating heap
5 6
enter the values wanted to store in Heap
115
584
285
152
251
125
584 251 285 115 152 125 
enter the number of elements you wanted to be delete
6
Deleteion succesfully at index = 1 elements 
285 251 125 115 152 
Deleteion succesfully at index = 2 elements 
251 152 125 115 
Deleteion succesfully at index = 3 elements 
152 115 125 
Deleteion succesfully at index = 4 elements 
125 115 
Deleteion succesfully at index = 5 elements 
115 
Deleteion succesfully at index = 6 elements 


*/
