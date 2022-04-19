#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<utility>

using namespace std;
int M,S,T;
int s0,s1;

int main(){
    scanf("%d%d%d",&M,&S,&T);
    for(int i=1;i<=T;i++){
        s0 += 17; // run
        if(M>=10) M-=10,s1+=60;
        else M+=4;
        if(s0<s1) s0 = s1;
        if(s0>=S){
            printf("Yes\n%d",i);
            return 0;
        }
    }
    printf("No\n%d",s0);
    return 0; 
}