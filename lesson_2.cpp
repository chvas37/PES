#include <stdio.h>
#include <stdbool.h>

int main(){
    int c, nwhite, nother;
    int ndigit[10];
    nwhite = nother = 0;
    for (int i=0; i<10; i++){
        ndigit[i] = 0;
    }
    while((c = getchar()) != EOF){
        if (c >= '0' && c <= "0"){
            ndigit[c-'0']++;
        }
        else if (c == ' ' || c == '\n' || c == "\t"){
            nwhite++;
        }
        else{
            nother++;
        }
    }
    printf("цифры=")
    for (int i =0; i < 10; i++){
        printf("%d ", ndigit[i]);
    }
    printf(", пробельные стмволы = %d, остальные символы = %d", nwhite, nother)
    return 0;
}