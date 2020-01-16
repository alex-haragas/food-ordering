#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "choosing.h"
#include "signing.h"
#include "food.h"
#include "foodtype.h"
#include "drink.h"

#define MAX_CUSTOMERS 9
#define MAX_NAME 100
#define MAX_PASS 100
#define MAX_COMMENT 100
#define LOAD_DATA "Please load the data"

int main( )
{
    FILE *datafile, *customerdata;
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
    food *foods;
    for(int i=0;i<nofood;i++)
    {
        foods[i]=createfood();
        if(isfile==1)
        readfood(datafile,&foods[i]);
        else
            readfood(stdin,&foods[i]);
    }
    int nodrink;
    fscanf(datafile,"%d",&nodrink);
    fgetc(datafile);//reads the ':' after the number
    fgetc(datafile);
    drink *drinks;
    drinks=(drink*)malloc(nodrink* sizeof(drink));
    if(isfile==0) {
        readdrink(stdin,nodrink,drinks);
    }
    else
    {
        readdrink(datafile,nodrink,drinks);
    }
    customerdata=fopen("D:\\CP\\food-ordering\\customerdata.txt","r");
    int key;
    fscanf(customerdata,"%d",&key);
    fgetc(customerdata);
    int nocustomers;
    fscanf(customerdata,"%d",&nocustomers);
    fgetc(customerdata);
    char** namelist=(char**)malloc(MAX_CUSTOMERS * sizeof(char*));
    char** paslist=(char**)malloc(MAX_CUSTOMERS * sizeof(char*));
    for(int i=0;i<MAX_CUSTOMERS;i++)
    {
        namelist[i]=(char*)malloc(MAX_NAME * sizeof(char));
        paslist[i]=(char*)malloc(MAX_PASS * sizeof(char));
    }
    for(int i=0;i<nocustomers;i++) {
        fscanf(customerdata, "%s", namelist[i]);
        fscanf(customerdata, "%s", paslist[i]);
    }
    fclose(customerdata);
    char* name=(char*)malloc(MAX_NAME*sizeof(char));
    char* comment=(char*)malloc(MAX_COMMENT*sizeof(char));
    comment[0]='\0';
    int state=0,sign=0, chosefood=0, chosefoodtipe=0,chosedrink=0,isdrink=1, cutlery=0;
    while(sign==0)
    {
        switch(state)
        {
            case 0:
            {
                customersignin();
                char choice=getchar();
                getchar();
                if(choice=='a')
                    signin(namelist,paslist,nocustomers,name,key,&state);
                    else
                        if(choice=='b')
                        {
                            if(nocustomers==MAX_CUSTOMERS)
                                printf("You can't create an account right now");
                            {
                                nocustomers++;
                                signup(namelist, paslist, nocustomers, name,key, &state);
                            }
                        }
                break;
            }
            case 1:
            {
                displayfood(nofood,foods);
                chosefood=choicevalue(&state, nofood);
                break;
            }
            case 2:
            {
                dispayfoodtype(foods[chosefood].nofoodtypes,foods[chosefood].name,foods[chosefood].foodtypes);
                chosefoodtipe=choicevalue(&state, foods[chosefood].nofoodtypes);
                break;
            }
            case 3:
            {
                displaydrink(nodrink,foods[chosefood].name,drinks);
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
                displayreceipt(name, foods[chosefood].foodtypes[chosefoodtipe].name,foods[chosefood].foodtypes[chosefoodtipe].price, drinks[chosedrink].name, drinks[chosedrink].price, isdrink, cutlery, comment);
                signchoice(&state, &sign, name);
                break;
            }
        }
    }
    for(int i=0;i<nofood;i++)
        freefood(&foods[i]);
    free(foods);
    for(int i=0;i<nodrink;i++)
        freedrink(&drinks[i]);
    free(drinks);
    free(comment);
    free(namelist);
    free(paslist);
    return 0;
}
