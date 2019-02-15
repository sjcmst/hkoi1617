#include <iostream>
#include <cmath>

using namespace std;
int N,Q;
void linkproblem(int* broken_this,int j, int* link, int* pw){
    for(int k=1;k<N;k++){
        if(link[k]==j){
            (*broken_this)++;
            pw[k]=-1;
            link[k]=-1;
            linkproblem(broken_this,k,link,pw);
        }
    }
    return;
}
int main(){
    cin >> N;
    int pw[N],link[N];
    for(int i=0;i<N;i++){
        cin >> pw[i];
        if(i!=0){
            cin >> link[i];
            link[i]--;
        }
    }
    cin >> Q;
    int breakthrough[Q], broken[Q];
    for(int i=0;i<Q;i++){
        cin >> breakthrough[i];
    }


    for(int i=0;i<Q;i++){
        int broken_this=0;
        for(int j=0;j<N;j++){
            if(breakthrough[i]==pw[j]){
                broken_this++;
                pw[j]=-1;
                link[j]=-1;
                linkproblem(&broken_this,j,link,pw);
            }
        }
        broken[i]=broken_this;
    }

    for(int i=0;i<Q;i++){
        cout << broken[i] << endl;
    }
    return 0;
}