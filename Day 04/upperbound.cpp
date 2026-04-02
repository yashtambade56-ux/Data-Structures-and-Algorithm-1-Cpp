#include<iostream>
using namespace std;

int upperBound(int arr[],int n, int key){
    int low=0, high=n-1;
    int ans=n; //defould if not found

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]<=key){
            ans=mid;
            high=mid-1;//move left
        }else{
            low=mid+1;//move right
        }
    }
    return ans;

}

int main(){
    int arr[]={1,3,5,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=4;
    cout<<upperBound(arr,n,key)<<endl;

}