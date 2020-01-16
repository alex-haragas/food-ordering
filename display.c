//
// Created by Alex on 03.11.2019.
//

#include <stdio.h>
#include <string.h>

#define SIGN_IN "Sign in"
#define SIGN_UP "Sign up"
#define SIGN_IN_UP "Do you want to sign in ot sign up?"
void customersignin()
{
    printf("Welcome to Food Thingies!\n");
    printf("%s\n",SIGN_IN_UP);
    printf("a) %s\n",SIGN_IN);
    printf("b) %s\n",SIGN_UP);
}

void displaycutlery()
{
    printf("Do you want cutlery?\n");
    printf("a) Yes\n");
    printf("b) No thanks!\n");
    printf("c) Go back!\n");
}
void displayreceipt(char* name, char* food, double foodprice, char* drink, double drinkprice, int isdrink, int cutlery, char* comment)
{
    printf("\nYour order:\n");
    printf("Name: %s\n",name);
    printf("Food items:\n");
    printf("---%s: %.2f\n", food, foodprice);
    if(isdrink==1)
        printf("---%s: %.2f\n",drink,drinkprice);
    if(cutlery==0)
        printf("Cutlery: yes\n");
    else
        printf("Cutlery: no\n");
    if(strlen(comment)!=0)
        printf("Additional info: %s\n", comment);
    printf("Payment amount: %.2f\n\n", foodprice+drinkprice);
    printf("a) Confirm order\n");
    printf("b) Go back\n");
}
