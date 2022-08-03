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
                if(left<size && arr[i] < arr[left]){
                    swap(arr[i],arr[left]);
                    i = left;
                }else if(right < size && arr[i] < arr[right]){
                    swap(arr[i],arr[right]);
                    i = right;
                }
                else return;
            }
        }
};
int main()
{
    Heap h;
    
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(6);
    h.print();
    h.deleteFromHeap();
    h.print();
    return 0;
}
/*
T.C for Inseration O(log n)
6 4 5 1 3 2 
4 2 5 1 3 
T.c for Deleteion O(logn)
*/
