//
// Created by Alex on 30.11.2019.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERROR_PASSWORD_LONG "The password must be at least 7 characters long"
#define ERROR_PASSWORD_NOT_USERNAME "The password must not contain the username"
#define ERROR_PASSWORD_SPECIAL_CHAR "The password must contain one of the following characters: {'.','_','!')"
#define ERROR_PASSWORD_DIGITS "The password must contain digits"
#define SIGNING_IN "Signing in!"
#define SIGNING_UP "Signing up!"
#define USER__NOT_FOUND "Username doesn't exist"
#define DUPLICATE_USER "Please choose another user"
#define INCORRECT_PASSWORD "Incorrect password"
#define MAX_NAME 100
#define MAX_PASS 100

int checkname(char **namelist,int nocustomers,char* name)
{
    for(int i=0;i<nocustomers;i++)
    {
        if(strcmp(name,namelist[i])==0)
            return i;
    }
    return -1;
}

void signin(char **namelist,char **passlist,int nocustomers,char *name,int *state)
{
    printf("%s\n", SIGNING_IN);
    while(*state==0) {
        char *customername = (char *) malloc(MAX_NAME * sizeof(char));
        char *customerpas = (char *) malloc(MAX_PASS * sizeof(char));
        printf("--Username\n");
        gets(customername);
        int poz = checkname(namelist, nocustomers, customername);
        if (poz == -1) {
            printf("%s\n\n", USER__NOT_FOUND);
            return;
        } else {
            printf("--Password\n");
            gets(customerpas);
            if (strcmp(customerpas, passlist[poz]) != 0)
                printf("%s\n",INCORRECT_PASSWORD);
            else
            {
                *state=1;
                strcpy(name,customername);
            }
        }
    }
}

int finddigit(char *s)
{
    for(int i=0;i<strlen(s);i++)
        if(s[i]>='0' && s[i]<='9')
            return 1;
    return 0;
}
int checkpas(char* password, char* name) {
    int ok = 1;
    if (strlen(password) < 7) {
        printf("%s\n", ERROR_PASSWORD_LONG);
        ok = 0;
    }
    if (strstr(password, name)) {
        printf("%s\n", ERROR_PASSWORD_NOT_USERNAME);
        ok = 0;
    }
    if (!strchr(password, '.') && !strchr(password, '_') && !strchr(password, '1')) {
        printf("%s\n", ERROR_PASSWORD_SPECIAL_CHAR);
        ok = 0;
    }
    if (!finddigit(password))
    {
        printf("%s\n", ERROR_PASSWORD_DIGITS);
        ok=0;
    }
    return ok;
}
void signup(char **namelist,char **passlist,int nocustomers,char *name,int *state)
{
    printf("%s\n", SIGNING_UP);
    while(*state==0)
    {
        char *customername = (char *) malloc(MAX_NAME * sizeof(char));
        char *customerpas = (char *) malloc(MAX_PASS * sizeof(char));
        printf("--Username\n");
        gets(customername);
        if(checkname(namelist,nocustomers,customername)!=-1)
            printf("%s\n",DUPLICATE_USER);
        else
        {
            printf("--Password\n");
            gets(customerpas);
            *state=checkpas(customerpas,customername);
            if(*state==1) {
                strcpy(name, customername);
                strcpy(namelist[nocustomers-1],customername);
                strcpy(passlist[nocustomers-1],customerpas);
            }
        }
    }
}