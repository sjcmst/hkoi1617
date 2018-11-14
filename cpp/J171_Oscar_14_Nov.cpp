#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    //initialize variables
    char acr[100];
    int N;
    char guess[100][5000];
    // bool isValidAcr = true;
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

    //Acronym Input Check
    // for(int k=0;k<strlen(acr);k++){
    //     if(!isalpha(acr[k])){
    //         isValidAcr = false;
    //     }
    // }

    //Prcoess
    for(int i=0;i<N;i++){

        //If character is behind a space, marked for checking
        bool needCheck=true;
        int acr_i=0;
        for(int j=0;j<strlen(guess[i]);j++){
            if(needCheck){
                guess[i][j] = toupper(guess[i][j]);

                if(guess[i][j]==acr[acr_i]){
                    acr_i++;
                }else{
                    guess[i][j] = tolower(guess[i][j]);
                }

                needCheck=false;
            }else{
                guess[i][j] = tolower(guess[i][j]);
            }
            if(guess[i][j]==' '){
                needCheck=true;
            }
        }

        //Output
        if(acr_i==strlen(acr)){
            cout << guess[i] << endl;
        }else{
            // cout << guess[i] <<endl;
            cout << "No :(" << endl;
        }
    }


    return 0;
}
