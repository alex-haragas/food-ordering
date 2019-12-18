//
// Created by Alex on 17.12.2019.
//
#include "foodtype.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX_FOOD_TYPE_NAME 100

foodtype createfoodtype()
{
    foodtype ft;
    ft.name=(char*)malloc(MAX_FOOD_TYPE_NAME*sizeof(char));
    return ft;
}

void freefoodtype(foodtype *ft)
{
    free(ft->name);
}
void dispayfoodtype(int nofoodtype,char *foodname,foodtype *ft)
{
    printf("Please choose the type of %s:\n", foodname);
    for (int i = 0; i < nofoodtype; i++)
    {
        printf("%c) %s: %.2f \n", 'a' + i, ft[i].name,ft[i].price);
    }
    printf("%c) Go back \n", 'a' + nofoodtype);
}