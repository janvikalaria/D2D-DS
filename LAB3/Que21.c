#include <stdio.h>
#include <string.h>

void main()
{
    char word[50], userWord[50], temp1[50], temp2[50];
    int i, j;
    char ch;

    printf("Enter a word: ");
    scanf("%s", word); //SILENT

    printf("Enter its anagram: ");
    scanf("%s", userWord);//LISTEN

    strcpy(temp1, word);
    strcpy(temp2, userWord);

    for(i=0; temp1[i]!='\0'; i++)
    {
        for(j=i+1; temp1[j]!='\0'; j++)
        {
            if(temp1[i] > temp1[j])
            {
                ch = temp1[i];
                temp1[i] = temp1[j];
                temp1[j] = ch;
            }
        }
    }  //EILNST

    for(i=0; temp2[i]!='\0'; i++)  //LISTEN
    {
        for(j=i+1; temp2[j]!='\0'; j++)
        {
            if(temp2[i] > temp2[j])
            {
                ch = temp2[i];
                temp2[i] = temp2[j];
                temp2[j] = ch;
            }
        }
    } //EILNST

    if(strcmp(temp1, temp2) == 0)
        printf("\nCorrect! It is an anagram.");
    else
        printf("\nWrong! It is not an anagram.");
}