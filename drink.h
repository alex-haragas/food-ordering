//
// Created by Alex on 17.12.2019.
//

#ifndef FOOD_ORDERING_DRINK_H
#define FOOD_ORDERING_DRINK_H

#include <stdio.h>

typedef struct _drink
{
    double price;
    char *name;
}drink;
drink createdrink();
void freedrink(drink *d);
void readdrink(FILE *datafile,int nodrink,drink *d);
void displaydrink(int nodrink,char *food,drink *d);
#endif //FOOD_ORDERING_DRINK_H
