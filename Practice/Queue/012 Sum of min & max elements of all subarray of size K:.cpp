/*
https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/
*/
#include <iostream>
#include <queue>
using namespace std;
void solve(int* arr,int n,int k){
    std::deque<int> maxi;
    std::deque<int> mini;
    int sum = 0;
    //addition of first K size window
    for(int i= 0;i<k;i++){
        
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        cout<<"Maximum element in arr in k = "<<i<<" size of window = "<<arr[maxi.front()]<<endl;
        cout<<"Minimum element in arr in k = "<<i<<" size of window = "<<arr[mini.front()]<<endl;
    }
    for(int i=k;i<n;i++){
        sum+= arr[maxi.front()] + arr[mini.front()];
        
        std::cout << "Sum of max and min in k = "<<i <<" size window = " <<sum <<std::endl;
        //next window
        //removal
        while(!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_back();
        while(!mini.empty() && i - mini.front() >= k)
            mini.pop_back();
        
        //addition
        
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        
        cout<<"Maximum element in arr in k = "<<i<<" size of window = "<<arr[maxi.front()]<<endl;
        cout<<"Minimum element in arr in k = "<<i<<" size of window = "<<arr[mini.front()]<<endl;
    }
    sum+= arr[maxi.front()] + arr[mini.front()];
    std::cout << "Sum of max and min in k size window = " <<sum <<std::endl;
}
int main()
{
    int arr[7] = {2, 5 ,-1, 7, -3, -1 ,2};
    int k = 4;
    solve(arr,7,k);
    return 0;
}
/*output
Maximum element in arr in k = 0 size of window = 2
Minimum element in arr in k = 0 size of window = 2
Maximum element in arr in k = 1 size of window = 5
Minimum element in arr in k = 1 size of window = 2
Maximum element in arr in k = 2 size of window = 5
Minimum element in arr in k = 2 size of window = -1
Maximum element in arr in k = 3 size of window = 7
Minimum element in arr in k = 3 size of window = -1
Sum of max and min in k = 4 size window = 6
Maximum element in arr in k = 4 size of window = 7
Minimum element in arr in k = 4 size of window = -3
Sum of max and min in k = 5 size window = 10
Maximum element in arr in k = 5 size of window = 7
Minimum element in arr in k = 5 size of window = -3
Sum of max and min in k = 6 size window = 14
Maximum element in arr in k = 6 size of window = 7
Minimum element in arr in k = 6 size of window = -3
Sum of max and min in k size window = 18
*/
