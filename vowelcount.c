    #include<stdio.h>
    #include<string.h>

    void vowel_count (char *(str), int n){
        int vowels=0, consonants=0, word=0, digits=0, spaces=0, specialCharacters = 0;
        int i;
        for(i=0;(str[i])!='\0';++i)
        {
            if((str[i])=='a' || (str[i])=='e' || (str[i])=='i' || (str[i])=='o' ||   (str[i])=='u' || (str[i])=='A' || (str[i])=='E' || (str[i])=='I' || (str[i])=='O' || (str[i])=='U')
            {
                ++vowels;
            } 
            else if(((str[i])>='a'&& (str[i])<='z') || ((str[i])>='A'&& (str[i])<='Z'))
            {
                ++consonants;
            }
            else if((str[i]) >='0' && (str[i]) <='9')
            {
                ++digits;
            }
            else if ((str[i])==' ')
            {
                ++spaces;
            }
            else {
                specialCharacters++;
             }
            if(str[i] != ' ' && str[i+1] == ' '){
            word++;
            }
            }

            if(str[n-1] != ' '){
            word++;
            }
        int characters = vowels + consonants + digits + specialCharacters;
        printf("\nNumber of words:  %d", word);
        printf("\n Number of Digits:  %d", digits);
        printf("\n Number of Consonants:  %d", consonants); 
        printf("\n Number of Vowels:  %d", vowels);
        printf("\n Number of White spaces:  %d", spaces);
        printf("\n Number of Characters: %d ", characters);
    }

    int main(){
    char string[200];
    printf("Enter a line of String :\n");
    gets(string);
                  
    vowel_count(string, strlen(string));
    return 0;
    }