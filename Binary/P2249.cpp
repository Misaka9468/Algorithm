#include<iostream>
#include<algorithm>

using namespace std;
#define MAXN 1000010
int n,m,target,mid,l,r;
int idx;
int arr[MAXN];

// 一眼没看别人手写出的无bug二分查找 泪目
int main(){
    scanf("%d %d",&n,&m);
    // 有效是0~n-1
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    // 0 1 2  [0,ok] [1,ok] [2,ok]
    for(int i=0;i<m;i++){
        scanf("%d",&target);
        l=0;r=n-1;
        idx = -1;
        while(1){
            if(l==r){
                break;
            }
            mid = l + (r-l)/2;
            if(arr[mid]>=target){
                r = mid;
            }    
            else{
                l = mid+1;
            }
        }
        if(arr[l]==target) printf("%d ",l);
        else printf("%d ",-1);
    }
    return 0;
}