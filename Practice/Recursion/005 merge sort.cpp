/* question link
https://www.codingninjas.com/codestudio/problems/merge-sort_920442?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_14
*/
void merge(vector < int > & arr,int s,int e){
    int mid = s + (e-s)/2;
    int len1 = mid - s +1;
    int len2 = e - mid;
    int *a = new int[len1];
    int *b = new int[len2];
    int k = s;
    for(int i = 0;i<len1;i++){
        a[i] = arr[k++];
    }
    k = mid + 1;
    for(int i = 0;i<len2;i++){
        b[i] = arr[k++];
    }
    int index1 = 0;
    int index2 = 0;
    k = s;
    while(index1<len1 && index2<len2){
        if(a[index1]<b[index2]){
            arr[k++] = a[index1++];
        }else{
            arr[k++]  = b[index2++];
        }
    }
    while(index1<len1){
        arr[k++] = a[index1++];
    }
    while(index2<len2){
        arr[k++] = b[index2++];
    }
    delete[] a;
    delete[] b;
}
void Sort(vector < int > & arr,int s,int e){
    if(s>=e) return ;
    int mid = s + (e-s)/2;
    Sort(arr,s,mid);
    Sort(arr,mid+1,e);
    merge(arr,s,e);
}
void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    Sort(arr,0,n-1);
}
