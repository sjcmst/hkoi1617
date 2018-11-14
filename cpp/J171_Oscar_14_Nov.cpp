#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    //initialize variables
    char acr[100];
    int N;
    char guess[100][5000];

    cin >> acr;
    cin >> N;
    
    //get input
    cin.getline(guess[0],5000);

    for(int i=0;i<N;i++){
        cin.getline(guess[i],5000);
    }

    //Output Marker
    // cout << endl;
    // cout << "Results:" << endl;

    //Prcoess
    for(int i=0;i<N;i++){
        bool needCheck=true;
        int acr_i=0;
        for(int j=0;j<strlen(guess[i]);j++){
            if(needCheck){
                if(guess[i][j]>=97&&guess[i][j]<=122){
                    guess[i][j]-=32;
                }
                if(guess[i][j]==acr[acr_i]){
                    acr_i++;
                }else{
                    guess[i][j]+=32;
                }
                needCheck=false;
            }else{
                if(guess[i][j]>=65&&guess[i][j]<=97){
                    guess[i][j]+=32;
                }
            }
            if(guess[i][j]==32){
                needCheck=true;
            }
        }

        //Output
        if(acr_i==strlen(acr)){
            cout << guess[i] << endl;
        }else{
            cout << "No :(" << endl;
        }
    }


    return 0;
}
