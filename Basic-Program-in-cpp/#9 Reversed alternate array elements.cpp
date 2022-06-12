//#9 Reversed alternate array elements.cpp
#include <iostream>

using namespace std;

void ReversedArrayElements(int a[],int size){
    for(int i =0;i<size;i+=2){
        if(i+1<size){
            swap(a[i],a[i+1]);
        }
    }
    cout<<"YOUR ALTERNATE Reversed ARRAYS elements :"<<endl;
    for(int i =0;i<size;i++){
        cout<<" "<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int size;
    std::cout << "enter the size of the array" << std::endl;
    std::cin >> size;
    int a[size];
    std::cout << "enter the all elements of the array" << std::endl;
    for(int i = 0;i<size;i++){
    std::cin >> a[i];
    }
    cout<<"Your input array"<<" ";
    for(int i=0;i<size;i++){
        cout<<" "<<a[i]<<" ";
    }
    cout<<endl;
    ReversedArrayElements(a , size);
    return 0;
}
