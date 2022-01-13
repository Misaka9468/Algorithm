#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define MAXN 255
string s;
int arr[MAXN];
int k;
int len;
int min_idx;


int main(){
    cin>>s>>k;
    len = s.length();
    for(int i=0;i<len;i++)  arr[i] = s[i]-'0';
    int tmp = k;
    int start = 0;
    bool is_first = 1;
    for(int count=0;count<len-k;count++){
        min_idx = start;
        for(int i = min_idx;i<=tmp+start;i++)
            min_idx = (arr[min_idx]>arr[i])?i:min_idx; 
        if(arr[min_idx]==0) ;
        else is_first = 0;
        if(!is_first)
            printf("%d",arr[min_idx]);
        tmp -= (min_idx - start);
        start = min_idx + 1;
    }
    if(is_first)
        printf("0");
    return 0;
}