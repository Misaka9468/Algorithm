#include<iostream>
#include<algorithm>

using namespace std;
#define MAXN 30010
int cnt;
int w,n;
int arr[MAXN];

int main(){
    scanf("%d %d",&w,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int i=0,j=n-1;
    while(i<=j){
        if(i==j){
            cnt++;
            i++;j--;
        }
        else if(arr[j]+arr[i]<=w){
            cnt++;
            i++;j--;
        }
        else if(arr[j]+arr[i]>w){
            cnt++;
            j--;
        }
    }
    printf("%d",cnt);
    return 0;
}   
