#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// ============ To get time ============
char* getDate(char* date){
    time_t now;
    time(&now);
    strcpy(date, ctime(&now));
}

void extractDate(char* date){
    char onlyDate[13];
    int i = 0;
    //  Sat Nov 27 20:10:21 2021
    int mark = 4;
    for(int r = 0; r < 7; r++){
        onlyDate[i++] = date[mark++];
    }
    mark = 20;
    for(int r = 0; r < 4; r++){
        onlyDate[i++] = date[mark++];
    }
    onlyDate[i] = '\0';
    // printf("\n in extract: %s\n", onlyDate);
    strcpy(date, onlyDate);
}
// ========== To get time Over ==========

// =========== String Formatters ===========
char toUpper(char ch){
    if(ch >= 'a' && ch <= 'z'){
        ch = ch-32;
    }
    return ch;
}

char toLower(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        ch = ch+32;
    }
    return ch;
}

// tested
void spaceFormat(char* str){
    int len = strlen(str);
    
    char formattedString[100];
    
    int j = 0;
    int i = 0;
    
    while(1){
        while(str[i] != '\0' && str[i] == ' '){
            i++;
        }
        while(str[i] != '\0' && str[i] != ' '){
            formattedString[j++]  = str[i++];
        }
        if(str[i] == '\0'){
            break;
        }
        formattedString[j++] = ' ';
    }

    if(formattedString[j-1] == ' '){
        formattedString[j-1] = '\0';
    }else{
        formattedString[j] = '\0';
    }

    strcpy(str, formattedString);
}

// tested
void formatName(char* firstName){

    spaceFormat(firstName);

    int len = strlen(firstName);
    if(len == 0){
        return;
    }

    firstName[0] = toUpper(firstName[0]);
    for(int i = 1; i < len; i++){
        if(firstName[i-1] == ' '){
            firstName[i] = toUpper(firstName[i]);
        }else{
            firstName[i] = toLower(firstName[i]);
        }
    }
}

void trimSpaces(char* str){
    char trimmed[500];
    int st = 0, end = strlen(str) - 1;

    while(str[st] != '\0' && (str[st] == ' ' || str[st] == '\t')){
        st++;
    }

    while(end >= 0 && (str[end] == ' ' || str[end] == '\t')){
        end--;
    }

    if(st > end){
        trimmed[0] = '\0';
    }else{
        int j = 0;
        for(int i = st; i <= end; i++){
            trimmed[j++] = str[i];
        }
        trimmed[j] = '\0';
    }
    strcpy(str, trimmed);
}

void formatNumber(char* mobNo){
    char formatted[15];
    int i = 0, j = 0;
    while(mobNo[j] != '\0'){
        if(mobNo[j] != ' '){
            formatted[i++] = mobNo[j];
        }
        j++;
    }
    formatted[i] = '\0';
    strcpy(mobNo, formatted);
}

bool checkNumber(char* mobNo){
    formatNumber(mobNo);
    int i = 0;
    while(mobNo[i] != '\0'){
        if(!(mobNo[i] >= '0' && mobNo[i] <= '9')){
            printf("\n\t\t\t\t     ERROR: Mob No. can only contain digits! Try again!\n\n");
            return false;
        }
        i++;
    }

    int len = strlen(mobNo);
    if(len == 10){
        return true;
    }else if(len < 10){
        printf("\n\t\t\t\t     ERROR: Mob No. seems SHORT! Try again!\n\n");
    } else {
        printf("\n\t\t\t\t     ERROR: Mob No. seems LONG! Try again!\n\n");
    }
    fflush(stdout);
    return false;
}

int stringCompare(char* str1, char* str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if(len1 > len2){
        return 1;
    }else if(len1 < len2){
        return -1;
    }else{
        for(int i = 0; i < len1; i++){
            if(str1[i] < str2[i]){
                return -1;
            }else if(str1[i] > str2[i]){
                return 1;
            }
        }
    }
    return 0;
}

void getSubstring(char* ans, char* str, int start, int end){
    if(start > end || strlen(str)-1 < end){
        ans[0] = '\0';
        printf("\nGet string error from function getString\n");
        return;
    }

    int run = 0;
    for(int i = start; i <= end; i++){
        ans[run++] = str[i]; 
    }
    ans[run] = '\0';
}

void stringCopy(char* str1, char* str2){
    int i = 0;
    while(str2[i] != '\0'){
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}

int stringToInt(char* str){
    int ans = 0;
    sscanf (str, "%d", &ans);
    return ans; 
}
// =========== String Formatters Over ===========

// int main(){
//     // for testing

//     // char str[] = "         my baby i love your voice             ";
//     // printf("~%s~\n", str);
//     // trim(str);
//     // printf("~%s~\n", str);
//     // char date[50];
//     // getDate(date);
//     // printf("%s", date);

//     char str[] = "| Para                 | Sir                  | 7040911715   | Pune                 | Nov 30 2021   | NIL         |";
//     char temp[21];
//     getSubstring(temp, str, 2, 21);
//     printf("%s\n", temp);

//     return 0;
// }