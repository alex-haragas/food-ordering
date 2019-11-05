//
// Created by Alex on 03.11.2019.
//

#include <stdio.h>

int choicevalue(int *state, int nochoices)
{
    int choiceindex=-1;
    char choice=getchar();
    getchar();
    if(choice==('a'+nochoices))
    {
        (*state)--;
        return -1;
    }
    else {
        (*state)++;
        choiceindex=choice-'a';
    }
    return choiceindex;
}
void finalchoice(int *state,int *sign,char name[])
{
    printf("a) Confirm order\n");
    printf("b) Go back\n>");
    char choice;
    choice=getchar();
    getchar();
    if(choice=='a')
    {
        *sign=1;
        printf("Order confirmed! Thank you for buying from us, %s",name);
    }
    else
        *state=4;
}