//
// Created by Alex on 17.12.2019.
//

#ifndef FOOD_ORDERING_FOOD_H
#define FOOD_ORDERING_FOOD_H

#include "foodtype.h"
#include <stdio.h>
typedef  struct _food
{
    char *name;
    int nofoodtypes;
    foodtype *foodtypes;
}food;
food createfood();
void freefood(food *f);
void readfood(FILE *datafile,food *f);
void displayfood(int nofood,food *f);
#endif //FOOD_ORDERING_FOOD_H
