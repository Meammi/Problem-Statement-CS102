#include <stdio.h>

int sizeofString(char word[],int length);
void checkConVow(char word[],int length,int *pcon,int *pvow);
void checkUpperLower(char word[],int length,int *pupper,int *plower);
int checkPalindrome(char word[],int length);

int main(){
    //input
    int length = 60; //จองช่องเผื่อไว้ 60 จาก 50
    int count = 0;
    int consonants = 0;
    int vowels = 0;
    int upper = 0;
    int lower = 0;
    int palindrome = 0;
    char word[length];
    scanf(" %s",word);

    count = sizeofString(word,length);
    checkConVow(word,length,&consonants,&vowels);
    checkUpperLower(word,length,&upper,&lower);
    palindrome = checkPalindrome(word,length);

    printf("Size of input string is %d",count);
    printf("\nConsonants: %d",consonants);
    printf("\nVowels: %d",vowels);
    printf("\nUpper-case letters: %d",upper);
    printf("\nLower-case letters: %d",lower);
    if (palindrome == 1)
    {
        printf("\nIs a palindrome strings: Yes");
    }
    else
    {
        printf("\nIs a palindrome strings: No");
    }
    
    return 0;
}
//Check Length ของ String Btw สามารถใช้ strlen จาก string.h ได้
int sizeofString(char word[],int length){
    int count = 0;
    
    while(count < length){
        if (word[count] == '\0')
        {
            break;
        }
        count++;
    }
    return count;
}
//Check Vowels and Consonants
void checkConVow(char word[],int length,int *pcon,int *pvow){
    length = sizeofString(word,length);
    int i = 0;

    while(i < length){
        if (word[i] == 'a'||
            word[i] == 'e'||
            word[i] == 'i'||
            word[i] == 'o'||
            word[i] == 'u'||
            word[i] == 'A'||
            word[i] == 'E'||
            word[i] == 'I'||
            word[i] == 'O'||
            word[i] == 'U')
        {
            (*pvow)++;
        }
        else{
            (*pcon)++;
        }
        i++;
    }
}
//Check Uppercase and Lowercase
void checkUpperLower(char word[],int length,int *pupper,int *plower){
    length = sizeofString(word,length);
    int i = 0;

    while (i < length)
    {
        if (word[i] >= 'a')//Check if ascii number of letter more than a that means that letter is lowercase
        {
            (*plower)++;
        }
        else{
            (*pupper)++;
        }
        i++;
    }
}
//Check Palindrome
int checkPalindrome(char word[],int length){
    length = sizeofString(word,length);
    int i = 0;

    while (i < length)
    {
        if(word[i] != word[length-i-1]){
            return 0;
        }
        i++;
    }
    return 1;
}
// 0 1 2 3 4 5 index
// 6 length
// 1 2 3 3 2 1 elements
// i = 0 word[0]= 1 check Element for tail = 5-i-1 word[5] = 1
// i = 1 word[1]= 2 check Element for tail = 5-i-1 word[4] = 2
// i = 2 word[2]= 3 check Element for tail = 5-i-1 word[3] = 3
// i = 3 word[3]= 3 check Element for tail = 5-i-1 word[2] = 3
// i = ...
// if it can end loop then return 1(means it is palindrome) else return 0 (means it is not palindrome)