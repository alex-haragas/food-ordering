//
// Created by Alex on 03.11.2019.
//

#include <stdio.h>
void displayfood(int nofood, char food[][100])
{
    for (int i = 0; i < nofood; i++) {
        printf("%c) %s \n", 'a' + i, food[i]);
    }
    printf("%c) Go back \n>", 'a' + nofood);
}
void displaydrink(int nodrink, char drink[][100])
{
for(int i=0;i<nodrink;i++)
{
printf("%c) %s \n",'a'+i,drink[i]);
}
printf("%c) No, thanks!\n", 'a'+nodrink);
printf("%c) Go back \n>",'a'+nodrink+1);
}
void displaycutlery()
{
printf("Do you want cutlery?\n");
printf("a) Yes\n");
printf("b) No thanks!\n");
printf("c) Go back!\n>");
}

