//
// Created by Alex on 17.12.2019.
//

#ifndef FOOD_ORDERING_FOODTYPE_H
#define FOOD_ORDERING_FOODTYPE_H

typedef struct _foodtype
{
    char* name;
    double price;
}foodtype;
foodtype createfoodtype();
void freefoodtype(foodtype *ft);
void dispayfoodtype(int nofoodtype,char *foodname,foodtype *ft);
#endif //FOOD_ORDERING_FOODTYPE_H
