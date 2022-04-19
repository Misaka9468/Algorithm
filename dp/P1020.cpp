#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
#define MAXN 100005

/*** dp(n^2) version ***/
// int n;
// int arr[MAXN];
// int low[MAXN];
// int up[MAXN];
// int max1,max2;
// int main(){
//     int i=1;
//     while(cin>>arr[i]) 
//         i++;
//     n = --i;
//     for(int i=1;i<=n;i++){
//         low[i] = 1;
//         up[i] =1;
//     }
//     for(int i=2;i<=n;i++){
//         for(int j=i-1;j>=1;j--){
//             if(arr[i]<=arr[j]){
//                 low[i] = max(low[i],low[j]+1);
//                 max1 = max(max1,low[i]);
//             }
//             if(arr[i]>arr[j])
//                 up[i] = max(up[j]+1,up[i]);
//                 max2 = max(max2,up[i]);
//         }
//     }
//     printf("%d\n%d",max1,max2);
//     return 0;
// }


/*** greedy(nlogn) version ***/

int n;
int arr[MAXN];
int up[MAXN];
int low[MAXN]; 
int main(){
    int i=1;
    while(cin>>arr[i]) 
        i++;
    n = --i;
    int tail = 1;
    low[1] = arr[1];
    for(int i=2;i<=n;i++){
        if(arr[i]<=low[tail]) low[++tail] = arr[i];
        else{
            // handwriting binary search
            int l=1,r=tail,mid=0;
            while(l<r){ 
                mid = (l+r)>>1;
                if(arr[i]>low[mid])
                    r = mid; // r always right
                else l = mid+1;
            }
            low[r] = arr[i];
        }
    }
    printf("%d\n",tail);
    tail = 1;
    up[1] = arr[1];
    for(int i=2;i<=n;i++){
        if(arr[i]>up[tail]) up[++tail] = arr[i];
        else{
            // handwriting binary search
            int l=1,r=tail,mid=0;
            while(l<r){ 
                mid = (l+r)>>1;
                if(arr[i]<=up[mid]) // <= matters
                    r = mid; // r always right
                else l = mid+1;
            }
            up[r] = arr[i];
        }
    }
    printf("%d",tail);
    return 0;
}
