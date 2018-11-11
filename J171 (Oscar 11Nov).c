#include <iostream>
using namespace std;

int main()
{
    char simplified[100];
    int n;
    char guess[100][5000];

    cin >> simplified;
    cin >> n;
    cin.getline(guess[0],5000);
    for(int i=0;i<n;i++){
        cin.getline(guess[i],5000);
        /*fgets(guess[i],5000,stdin);
        int j=0;
        do{
            j++;
        }while(guess[i][j]!='\n');
        guess[i][j]='\0';*/

    }

    for(int i=0;i<n;i++){
        bool istrue = false;
        int j=0;
        bool needcheck = true;
        int i_simplified = 0;
        do{
                if(needcheck){
                    if(guess[i][j]>=97&&guess[i][j]<=122){ //if guess is capital
                        guess[i][j]-=32;
                    }
                    if(guess[i][j]==simplified[i_simplified]){
                        i_simplified++;

                        if(simplified[i_simplified]=='\0'){
                            istrue=true;
                            i_simplified--;
                        }
                    }
                    needcheck= false;

                }else if(guess[i][j]==' '){
                    needcheck=true;
                }
            j++;
        }while(guess[i][j]!='\0');

        if(istrue){
            int j=0;
            bool needcheck = true;
            int i_simplified = 0;
            do{
                if(needcheck){
                    if(guess[i][j]>=97&&guess[i][j]<=122){ //if guess is capital
                        guess[i][j]-=32;
                    }
                    if(guess[i][j]==simplified[i_simplified]){
                        i_simplified++;
                        if(simplified[i_simplified]=='\0'){
                            i_simplified--;
                        }
                    }else{
                        guess[i][j]+=32;
                    }
                    needcheck= false;
                }else if(guess[i][j]==' '){
                    needcheck=true;
                }else if(guess[i][j]>=65&&guess[i][j]<=90){
                    guess[i][j]+=32;
                }
                cout << guess[i][j];
                j++;
            }while(guess[i][j]!='\0');
            cout << endl;
        }else{
            cout << "No :(" << endl;
        }
    }

    return 0;
}
