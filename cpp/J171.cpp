#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
    if (argc > 2)
    {  //Arguments check
       cout << "Usage: ./J171 [-d|--debug]" << endl; 
       return 1;
    }else
    {   //Checks for Debug Mode
        bool isDebugging = false;
        if (argc == 2 && (strcmp(argv[1], "-d")==0 || strcmp(argv[1],"--debug")==0 ) ){
            isDebugging = true;
            cout << "Debug mode ON" << endl << endl;
        }

        //initialize variables
        char acroym[100];           //the acroym to check for
        int n;                      //the amount of inputs
        char inputs[100][5000];     //the inputs to guess for
        char results[100][5000];

        //get the inputs from terminal
        if(isDebugging) cout << "Acroym : ";
        cin >> acroym;
        if(isDebugging) cout << "# of inputs : ";
        cin >> n;
        cin.ignore();               //since cin >> tokenizes and leaved the newline in the stream
                                    //we need to clear it using ignore;
        for(int i=0; i<n; i++){
            if(isDebugging) cout << "Input " << i+1 << " : " ;
            cin.getline(inputs[i],5000);
        }

        //Prcoess
        for(int i=0; i<n; i++){       //Loop thru inputs arr to process every input
            
            int acr_i=0;            //counter for the acroym characters
            bool isInitial=true;    //if character is behind a space
                                    //Flag as an initial char for checking
            
            if(isDebugging) cout << "Debug : " << inputs[i] << " >> ";
            for(int j=0; j<strlen(inputs[i]); j++)
            {   //Loop thru every char in input
                
                if(isInitial && toupper(inputs[i][j]) == acroym[acr_i])
                {   //Case if this char is an initial char and is part of an acronym
                    if(isDebugging) cout << "1";
                    results[i][j] = toupper(inputs[i][j]);
                    acr_i++;
                    isInitial=false;

                }else if(inputs[i][j]==' ')
                {   //Case if this char is a space, then next char must be an initial
                    if(isDebugging) cout << " ";
                    results[i][j] = ' ';
                    isInitial=true;

                }else
                {   //Everything else should be lowercased
                    if(isDebugging) cout << "0";
                    results[i][j] = tolower(inputs[i][j]);
                }   //endif
                
            }   //endfor

            
            if(acr_i != strlen(acroym))
            {   //if the accroymn is not completely looped thru
                //record as failure
                if(isDebugging) cout << " >> Fail " << acr_i << "/" << strlen(acroym);
                strcpy(results[i], "No :(");
            }
            
            if(isDebugging) cout << endl;
            
        }

        
        if(isDebugging) cout << endl << "--RESULTS--" << endl;
        for(int i=0 ; i<n; i++)
        {   //Output 
            cout << results[i] << endl;
        }

        return 0;
    }
}
