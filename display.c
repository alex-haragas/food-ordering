//
// Created by Alex on 03.11.2019.
//

#include <stdio.h>
#include <string.h>
void displayfood(int nofood, char** food)
{
    printf("Please choose the food you feel like eating today:\n");
    for (int i = 0; i < nofood; i++)
    {
        printf("%c) %s \n", 'a' + i, food[i]);
    }
    printf("%c) Go back \n>", 'a' + nofood);
}
void displayfoodtype(int nofood, char** foodtype, double * price, char* food)
{
    printf("Please choose the type of %s:\n", food);
    for (int i = 0; i < nofood; i++)
    {
        printf("%c) %s: %lf \n", 'a' + i, foodtype[i],price[i]);
    }
    printf("%c) Go back \n>", 'a' + nofood);
}

void displaydrink(int nodrink, char** drink,double * price, char* food)
{
    printf("Please choose a drink to go with your %s:\n" ,food);
    for(int i=0;i<nodrink;i++)
    {
        printf("%c) %s: %lf \n",'a'+i,drink[i],price[i]);
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
void displayreceipt(char* name, char* food, double foodprice, char** drink, double drinkprice, int isdrink, int cutlery, char* comment)
{
    printf("\n Your order:\n");
    printf("Name: %s\n",name);
    printf("Food items:\n");
    printf("---%s: %lf\n", food, foodprice);
    if(isdrink==1)
        printf("---%s: %lf\n",drink,drinkprice);
    if(cutlery==0)
        printf("Cutlery: yes\n");
    else
        printf("Cutlery: no\n");
    if(strlen(comment)!=0)
        printf("Additional info: %s\n", comment);
    printf("Payment amount: %1f\n\n", foodprice+drinkprice);
    printf("a) Confirm order\n");
    printf("b) Go back\n>");
}
