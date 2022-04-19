#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>

#define MAXN 22
#define ll long long
using namespace std;
// 2-dim
vector<int> idx[MAXN];
vector<int> len[MAXN];
vector<string> words;
int visited[MAXN];
ll now_length=0,max_length=0;
string word;
char ch;
int n;

// compute over-lap
void judge(int i, int j){
    bool flag=true;
    string a = words[i], b=words[j];
    int len_a = a.length(), len_b = b.length(), min_len = min(len_a,len_b);
    int k = 1;
    while(k<min_len){
        const char* tmp_a = (const char*)a.substr(len_a-k,k).c_str();
        const char* tmp_b = (const char*)b.substr(0,k).c_str();
        if(strcmp(tmp_a,tmp_b)==0){
            break;
        }
        k++;
    }
    if(k!=min_len){
        idx[i].push_back(j);
        len[i].push_back(len_b-k);
    } 
}

void dfs(int index){
    int tmp_len = idx[index].size();
    for(int i=0;i<tmp_len;i++){
        visited[idx[index][i]]++;
        if(visited[idx[index][i]]>2){
            visited[idx[index][i]]--;
        }
        else{
            now_length+=len[index][i];
            max_length = max(max_length,now_length);
            dfs(idx[index][i]);
            now_length-=len[index][i];
            visited[idx[index][i]]--;
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>word;
        words.push_back(word);
    }
    cin>>ch;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            judge(i,j);
        }
    }
    for(int i=0;i<n;i++){
        memset(visited,0,sizeof(visited));
        if(words[i][0]==ch){
            visited[i]++;
            now_length = words[i].length();
            max_length = max(now_length,max_length);
            dfs(i);
            visited[i]--;
        }
    }
    printf("%lld",max_length);
    return 0;
}
