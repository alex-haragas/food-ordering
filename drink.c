//
// Created by Alex on 17.12.2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "drink.h"

#define MAX_DRINK_NAME 100
#define MAX_LINE_LENGHT 255

drink createdrink(){
    drink d;
    d.name=(char*)malloc(MAX_DRINK_NAME* sizeof(char));
    return d;
}
void freedrink(drink *d)
{
    free(d->name);
}

void separatedrinks(char *line,int nodrink ,drink *d)
{
    int braket=strchr(line,'(')-line;
    for(int i=0; i < nodrink; i++)
    {
        int minus=strchr(line+braket,'-')-line;
        while(line[minus+1]!=' ')//makes sure the '-' is not int the name of the item
            minus=strchr(line+minus+1,'-')-line;
        strncpy(d[i].name, line + braket + 1, minus - braket - 2);//-2 is needed to make sure only the name is copied
        d[i].name[minus-braket-2]='\0';
        d[i].price=atof(line + minus + 2);//2 is needed to get to the starting position of the number
        braket=strchr(line+braket+1,'(')-line;
    }
}
void readdrink(FILE *datafile,int nodrink,drink *d)
{
    char* line=(char*)malloc(MAX_LINE_LENGHT* sizeof(char));
    fgets(line, 250, datafile);
    for(int i=0;i<nodrink;i++)
        d[i]=createdrink();
    separatedrinks(line,nodrink,d);
    free(line);
}
void displaydrink(int nodrink,char *food,drink *d)
{
    printf("Please choose a drink to go with your %s:\n" ,food);
    for(int i=0;i<nodrink;i++)
    {
        printf("%c) %s: %.2f \n",'a'+i,d[i].name,d[i].price);
    }
    printf("%c) No, thanks!\n", 'a'+nodrink);
    printf("%c) Go back \n",'a'+nodrink+1);
}
