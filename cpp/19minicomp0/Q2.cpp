#include <iostream>
#include <cmath>

using namespace std;

bool timeslots[961];

int main(){
    int N,M;
    cin >> N;
    char timeN[N][12];
    for(int i=0;i<N;i++){
        cin >> timeN[i];
        cin.clear();
        cin.ignore(500,'\n');
    }
    cin >> M;
    char timeM[M][12];
    for(int i=0;i<M;i++){
        cin >> timeM[i];
        cin.clear();
        cin.ignore(500,'\n');
    }
    for(int i=0;i<961;i++){
        timeslots[i]=true;
    }
    for(int i=0;i<N;i++){
        int start_h = ((int)(timeN[i][0])-48)*10+((int)(timeN[i][1]-48));
        int start_m = ((int)(timeN[i][3])-48)*10+((int)(timeN[i][4]-48));
        int end_h = ((int)(timeN[i][6])-48)*10+((int)(timeN[i][7]-48));
        int end_m = ((int)(timeN[i][9])-48)*10+((int)(timeN[i][10]-48));
        
        for(int j=(start_h-7)*60+start_m+1;j<(end_h-7)*60+end_m;j++){
            timeslots[j]=false;
        }
    }
    for(int i=0;i<M;i++){
        int start_h = ((int)(timeM[i][0])-48)*10+((int)(timeM[i][1]-48));
        int start_m = ((int)(timeM[i][3])-48)*10+((int)(timeM[i][4]-48));
        int end_h = ((int)(timeM[i][6])-48)*10+((int)(timeM[i][7]-48));
        int end_m = ((int)(timeM[i][9])-48)*10+((int)(timeM[i][10]-48));
    
        for(int j=(start_h-7)*60+start_m+1;j<(end_h-7)*60+end_m;j++){
            timeslots[j]=false;
        }
    }
    int c=0, maxim=0, start_serial=0, maxim_start_serial=0;
    for(int i=0;i<961;i++){
        if(timeslots[i]==true){
            if(c==0) start_serial=i;
            c++;
            if(c>maxim){
                maxim = c;
                maxim_start_serial = start_serial;
            } 
        }else{
            c=0;
        }
    }
    maxim--;
    if(maxim<=0){
        cout << "SAD";
    }else{
        cout << (maxim_start_serial/60+7)/10;//hour tens
        cout << (maxim_start_serial/60+7)%10;//hour units
        cout << ":";
        cout << (maxim_start_serial%60)/10;//minute tens
        cout << (maxim_start_serial%60)%10;//minute units
        cout << "-";
        cout << ((maxim_start_serial+maxim)/60+7)/10;//hour tens
        cout << ((maxim_start_serial+maxim)/60+7)%10;//hour units
        cout << ":";
        cout << ((maxim_start_serial+maxim)%60)/10;//minute tens
        cout << ((maxim_start_serial+maxim)%60)%10;//minute units
        cout << " ACTIVITY";
    }
    return 0;
}