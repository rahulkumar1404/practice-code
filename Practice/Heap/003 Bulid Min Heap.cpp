/*
https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/
void heapify(vector<int>& arr,int n,int index){
    int smallest = index;
    int left = 2*index+1;
    int right = 2*index+2;
    if( (left < n) && (arr[smallest] > arr[left]) ){
        smallest = left;
    }
    if( (right < n) && (arr[smallest] > arr[right]) ){
        smallest = right;
    }
    if(smallest != index){
        swap(arr[smallest],arr[index]);
        heapify(arr,n,smallest);
    }else {
        return ;
    }
    
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i = n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    return arr;
}

