#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "choosing.h"

#define MAX_FOOD_NAME 100
#define MAX_MENU_ITEM_NAME 100//since they were equal, I've decided to combine MAX_FOOD_TYPE_NAME and MAX_DRINK_NAME into one costant, this way I won't have to make two functions
#define MAX_NAME 100
#define MAX_PASS 100
#define MAX_COMMENT 100
#define LOAD_DATA "Please load the data"
#define MAX_LINE_LENGHT 250

int firstnumber(char* s);
void getcustomerdata(char *name, char *password);
void separateitems(char *line, char ** menuitemtype, int nomenuitemtype, double* menuitemprice);
void freemenuitem(char** menuitemtype, int nomenuitemtype, double* menuitemprice);

int main( )
{
    FILE *datafile;
    int isfile=0;
    datafile=fopen("D:\\CP\\food-ordering\\data.txt","r");
    if(datafile==NULL)
    {
        printf("Error opening the file. %s\n", LOAD_DATA);
    }
    else
        isfile=1;
    int nofood;
    if(isfile==0) {
        scanf("%d", &nofood);
        getchar();//reads the ':' after the number
        getchar();
    } else
    {
        fscanf(datafile,"%d",&nofood);
        fgetc(datafile);//reads the ':' after the number
        fgetc(datafile);
    }
    char** food=(char**)malloc(nofood* sizeof(char*));
    int* nofoodtype=(int*)malloc((nofood* sizeof(int)));
    char*** foodtype=(char***)malloc(nofood* sizeof(int**));
    double**  foodprice=(double**)malloc(nofood* sizeof(double*));
    for(int i=0;i<nofood;i++)
    {
        char* line=(char*)malloc(MAX_LINE_LENGHT* sizeof(char));
        food[i]=(char*)malloc(MAX_FOOD_NAME* sizeof(char));
        if(isfile==0)
        gets(line);
        else
            fgets(line, 250, datafile);
        int poznumber= firstnumber(line);
        strncpy(food[i], line, poznumber-1);
        food[i][poznumber-1]='\0';
        nofoodtype[i]=atoi(line+poznumber);
        foodtype[i]=(char**)malloc(nofoodtype[i]* sizeof(char*));
        foodprice[i]=(double*)malloc(nofoodtype[i]* sizeof(double));
        for(int j=0;j<nofoodtype[i];j++)
            foodtype[i][j]=(char*)malloc(MAX_MENU_ITEM_NAME* sizeof(char));
        separateitems(line,foodtype[i],nofoodtype[i],foodprice[i]);
        free(line);
    }
    int nodrink;
    if(isfile==0)
    {
    scanf("%d",&nodrink);
    getchar();//read the ':' after the number
    getchar();}
    else
    {
        fscanf(datafile,"%d",&nodrink);
        fgetc(datafile);//reads the ':' after the number
        fgetc(datafile);
    }
    char** drink=(char**)malloc(nodrink* sizeof(char*));
    for(int i=0;i<nodrink;i++)
        drink[i]=(char*)malloc(MAX_MENU_ITEM_NAME* sizeof(char*));
    double* drinkprice=(double*)malloc((nodrink+1)* sizeof(double));//I want to have a 0 on the nodrink th position
    drinkprice[nodrink]=0;
    char* line=(char*)malloc(MAX_LINE_LENGHT* sizeof(char));
    if(isfile==0)
        gets(line);
    else
    {
        fgets(line,250,datafile);
    }
    separateitems(line,drink,nodrink,drinkprice);
    free(line);
    fclose(datafile);
    char* name=(char*)malloc(MAX_NAME*sizeof(char));
    char* pas=(char*)malloc(MAX_PASS*sizeof(char));
    char* comment=(char*)malloc(MAX_COMMENT*sizeof(char));
    comment[0]='\0';
    int state=0,sign=0, chosefood=0, chosefoodtipe=0,chosedrink=0,isdrink=1, cutlery=0;
    while(sign==0)
    {
        switch(state)
        {
            case 0:
            {
                getcustomerdata(name, pas);
                state = 1;
                break;
            }
            case 1:
            {
                displayfood(nofood,food);
                chosefood=choicevalue(&state, nofood);
                break;
            }
            case 2:
            {
                displayfoodtype(nofoodtype[chosefood],foodtype[chosefood],foodprice[chosefood],food[chosefood]);
                chosefoodtipe=choicevalue(&state, nofoodtype[chosefood]);
                break;
            }
            case 3:
            {
                displaydrink(nodrink,drink,drinkprice,food[chosefood]);
                chosedrink= choicevalue(&state,(nodrink+1));
                if(chosedrink==nodrink)
                    isdrink=0;
                break;
            }
            case 4:
            {
                displaycutlery();
                cutlery=choicevalue(&state,2);
                break;
            }
            case 5:
            {
                printf("Any additional info?(Press Enter if you don't want to write.)\n");
                gets(comment);
                state=6;
                break;
            }
            case 6:
            {
                displayreceipt(name, foodtype[chosefood][chosefoodtipe],foodprice[chosefood][chosefoodtipe],drink[chosedrink],drinkprice[chosedrink],isdrink,cutlery,comment);
                signchoice(&state, &sign, name);
                break;
            }
        }
    }
    for(int i=0;i<nofood;i++)
    {
        freemenuitem(foodtype[i], nofoodtype[i], foodprice[i]);
        free(food[i]);
    }
    free(food);
    freemenuitem(drink,nodrink,drinkprice);
    free(drink);
    free(comment);
    free(name);
    free(pas);
    return 0;
}
void getcustomerdata(char *name, char *password)
{
    printf("Welcome to Food Thingies!\n");
    printf("Please Sing in to continue!\n");
    printf("--Username\n");
    gets(name);
    printf("--Password\n");
    gets(password);
}

void separateitems(char *line, char** menuitemtype, int nomenuitemtype, double* menuitemprice)
{
    int braket=strchr(line,'(')-line;
    for(int i=0; i < nomenuitemtype; i++)
    {
        int minus=strchr(line+braket,'-')-line;
        while(line[minus+1]!=' ')//makes sure the '-' is not int the name of the item
            minus=strchr(line+minus+1,'-')-line;
        strncpy(menuitemtype[i], line + braket + 1, minus - braket - 2);//-2 is needed to make sure only the name is copied
        menuitemtype[i][minus-braket-2]='\0';
        menuitemprice[i]=atof(line + minus + 2);//2 is needed to get to the starting position of the number
        braket=strchr(line+braket+1,'(')-line;
    }
}
void freemenuitem(char** menuitemtype, int nomenuitemtype, double* menuitemprice)
{
    for(int i=0;i<nomenuitemtype;i++)
    {
        free(menuitemtype[i]);
    }
    free(menuitemprice);
    free(menuitemtype);
}
int firstnumber(char* s)
{
    for(int i=0;i<strlen(s);i++)
        if(s[i]>='0' && s[i]<='9')
            return i;
}
