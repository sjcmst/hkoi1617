#include <iostream>

using namespace std;

char nMinusOne[10000000];
char nMinusTwo[10000000];
int secondSecti=0;
int thirdSecti=0;
int totallen=0;
int Q;
int count = 0;

int process(long long int L, long long int R, char W1,char W2){
        if(W1=='1'&&W2=='1'){
            return 0;
        }
        nMinusOne[0] = '0';
        nMinusOne[1] = '1';
        nMinusTwo[0] = '0';
        secondSecti=2;
        thirdSecti=3;
        totallen = 5;
        count = 0;

        while(totallen<R){
            for(int i=secondSecti;i<thirdSecti;i++){
                nMinusOne[i]=nMinusTwo[i-secondSecti];
            }
            for(int i=0;i<secondSecti;i++){
                nMinusTwo[i]=nMinusOne[i];
            }
            secondSecti = thirdSecti;
            thirdSecti = totallen;
            totallen = secondSecti + thirdSecti;
        }
        nMinusOne[secondSecti]=nMinusTwo[0];
        nMinusTwo[thirdSecti-secondSecti]=nMinusOne[0];
        for(int i=L;i<R;i++){
            if(i<secondSecti){
                if(nMinusOne[i]==W1&&nMinusOne[i+1]==W2){
                    count++;
                }
            }else if(i<thirdSecti){
                if(nMinusTwo[i-secondSecti]==W1&&nMinusTwo[i-secondSecti+1]==W2){
                    count++;
                }
            }else{
                if(nMinusOne[i-thirdSecti]==W1&&nMinusOne[i-thirdSecti+1]==W2){
                    count++;
                }
            }
        }
        return count;
    
}
int main(){
    cin >> Q;
    long long int L[Q],R[Q];
    char W[Q][2];
    for(int i=0;i<Q;i++){
        cin >> L[i] >> R[i] >> W[i];
    }

    for(int i=0;i<Q;i++){
        cout << process(L[i]-1,R[i]-1,W[i][0],W[i][1]) << endl;
    }
    
    return 0;
}
