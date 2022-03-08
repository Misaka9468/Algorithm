#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
#define MAXN 105
int arr[MAXN];
// l and r means need to deleted
int l[MAXN],r[MAXN];
int max_num = 1;
int n;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        l[i]=1;
        r[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            if(arr[i]>arr[j])
                l[i] = max(l[i],l[j]+1);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            if(arr[i]>arr[j])
                r[i] = max(r[i],r[j]+1);
        }
    }    
    for(int i=1;i<=n;i++){
        max_num = max(max_num,l[i]+r[i]-1);
    }
    printf("%d",n-max_num);
    return 0;
}
