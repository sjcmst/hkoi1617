//
//  main.c
//  rrtr
//
//  Created by Travis Chan on 18/10/2018.
//  Copyright © 2018 Travis Chan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    char acronym[100], guess[100][5000], acronymOfGuess[100][5000], dummyChar;
    int indexOfAcronym[100][5000];
    int numOfGuess=1;
//    printf("acronym: ");
    fgets(acronym, sizeof(acronym), stdin);
    acronym[strlen(acronym)-1] = '\0';
//    printf("|%s|\n", acronym);
//    printf("number of guess: ");
    scanf(" %d",&numOfGuess);
    dummyChar = getchar();
    
    // input guesses
    for (int i=0; i<numOfGuess; i++) {
//        printf("guess: ");
        fgets(guess[i], sizeof(guess[i]), stdin);
        guess[i][strlen(guess[i])-1] = '\0';
//        printf("|%s|\n", guess[i]);
    }
    
    // check for correct acronym
    for (int i=0; i<strlen(acronym); i++) {
        if(!(acronym[i]>=65 && acronym[i]<=90)) { //good
//            printf("Acronym not all capital letters");
            return 0;
        }
    }
    
    for (int k=0; k<numOfGuess; k++) {
        int i=0, j=0;
        guess[k][j]= toupper(guess[k][j]);
        acronymOfGuess[k][i]=guess[k][0];
        indexOfAcronym[k][i]=0;
        i++;
        while (j<strlen(guess[k])) {
            while (!isspace(guess[k][j]) && j<strlen(guess[k])) {
                j++;
                guess[k][j]= tolower(guess[k][j]);
                
            }
            if (j>=strlen(guess[k])) {
                break;
            }
            
            j++;
            guess[k][j]= toupper(guess[k][j]);
            acronymOfGuess[k][i]=guess[k][j];
            indexOfAcronym[k][i]=j;
            i++;
           
        }
        
//        printf("%s", guess[k]);
//        printf("\n");
//        for (int i=0; i<strlen(acronymOfGuess[k]); i++) {
//            printf("%d %c\n", indexOfAcronym[k][i], acronymOfGuess[k][i]);
//        }
//        printf("\n");
        
    }
        
    for (int k=0; k<numOfGuess; k++) {
        int i=0, j=0, exitFlag=0;
        while (j<=strlen(acronymOfGuess[k]) && i<=strlen(acronym)) {
            if(acronym[i]!=acronymOfGuess[k][j]) {
                guess[k][indexOfAcronym[k][j]]=tolower(guess[k][indexOfAcronym[k][j]]);
                j++;
                exitFlag=1;
            }else{
                j++;
                i++;
                exitFlag=0;
            }
        }
        if(!exitFlag){
            printf("%s\n", guess[k]);
        }else{
            printf("No :(\n");
        }
    }
    

    return 0;
}


