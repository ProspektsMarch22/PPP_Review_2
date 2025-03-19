#include <stdio.h>
#include <string.h>

int substr(char * a, char * b);

int main(){
    char * a = "Isaac";
    char * b = "aa";
    printf("A primeira ocorrência de b em a ocorre no índice %d de a\n", substr(a, b));
    return 0;
}

int substr(char * a, char * b){
    int i = 0;
    while(*(a + i) != '\0'){
        int j = 0;
        if(*(a + i) == *(b + j)){
            while(*(b + j) != '\0'){
                if(*(a + i + j) == *(b + j)){
                    j++;
                } else {
                    break;
                }
            }
        }
        if((j + 1) == (int)strlen(b)){
            return i - 1;
        }
        i++;
    }
    return 0;
}