/*
https://www.codingninjas.com/codestudio/problems/quick-sort_983625?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_15
*/

int partion(vector<int>& arr,int s,int e){
    int pivot = arr[s];
    int count = 0;
    
    for(int i = s+1;i<=e;i++){
        if(arr[i]<=pivot) count++;
    }
    int pivotIndex = s+count;
    swap(arr[pivotIndex],arr[s]);
    int i = s;
    int j = e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot) {
            i++;
        }
        while(arr[j]>pivot){
             j--;   
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}
void Sort(vector<int>& arr,int s,int e){
    if(s >= e){
        return ;
    }
    int p = partion(arr,s,e);
    Sort(arr,s,p-1);
    Sort(arr,p+1,e);
}

vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    Sort(arr,0,arr.size()-1);
    return arr;
}
