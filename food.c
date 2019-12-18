//
// Created by Alex on 17.12.2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foodtype.h"
#include "food.h"

#define MAX_FOOD_NAME 100
#define MAX_LINE_LENGHT 255

food createfood(){
    food f;
    f.name=(char*)malloc(MAX_FOOD_NAME* sizeof(char));
    f.foodtypes=NULL;
    return f;
}
void freefood(food *f)
{
    for(int i=0;i<f->nofoodtypes;i++)
    {
        freefoodtype(&f->foodtypes[i]);
    }
    free(f->foodtypes);
    free(f->name);
}

int firstnumber(char* s)
{
    for(int i=0;i<strlen(s);i++)
        if(s[i]>='0' && s[i]<='9')
            return i;
}
void separatefoods(char *line, food *f)
{
    int braket=strchr(line,'(')-line;
    for(int i=0; i < f->nofoodtypes; i++)
    {
        int minus=strchr(line+braket,'-')-line;
        while(line[minus+1]!=' ')//makes sure the '-' is not int the name of the item
            minus=strchr(line+minus+1,'-')-line;
        strncpy(f->foodtypes[i].name, line + braket + 1, minus - braket - 2);//-2 is needed to make sure only the name is copied
        f->foodtypes[i].name[minus-braket-2]='\0';
        f->foodtypes[i].price=atof(line + minus + 2);//2 is needed to get to the starting position of the number
        braket=strchr(line+braket+1,'(')-line;
    }
}
void readfood(FILE *datafile,food *f)
{
    char* line=(char*)malloc(MAX_LINE_LENGHT* sizeof(char));
    fgets(line, 250, datafile);
    int poznumber= firstnumber(line);
    strncpy(f->name, line, poznumber-1);
    f->name[poznumber-1]='\0';
    f->nofoodtypes=atoi(line+poznumber);
    f->foodtypes=(foodtype*)malloc(f->nofoodtypes* sizeof(foodtype));
    for(int i=0;i<f->nofoodtypes;i++)
    {
        f->foodtypes[i]=createfoodtype();
    }
    separatefoods(line,f);
    free(line);
}
void displayfood(int nofood,food *f)
{
    printf("Please choose the food you feel like eating today:\n");
    for (int i = 0; i < nofood; i++)
    {
    printf("%c) %s \n", 'a' + i, f[i].name);
    }
    printf("%c) Go back \n", 'a' + nofood);
}