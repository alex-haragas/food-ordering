#include <stdio.h>
#include "display.h"
#include "choosing.h"

#define MAX_FOOD_NAME 100
#define MAX_FOOD_TYPE_NAME 100
#define MAX_DRINK_NAME 100

void getcustomerdata(char *name, char *password);

int main( )
{
    char name[100], pas[100], comment[100]="\0";
    char food [3][MAX_FOOD_NAME]={"Pizza","Pasta","Salad"};
    int nofood=3;
    int nofoodtype[4]={3, 2, 4};
    char foodtype[3][4][MAX_FOOD_TYPE_NAME]={{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
                              {"Chicken alfredo", "Mac & cheese"},
                              {"Tuna Salad",      "Chicken Salad", "Greek Salad", "Cobb"}};
    int  foodprice[3][4]={{21,23,19},
                          {23,21},
                          {23,22,19,21}};
    int nodrink=4;
    char drink[4][MAX_DRINK_NAME]={"Coca-cola","Fanta","Lipton","Water"};
    int drinkprice[5]={5,5,5,4}; // The 5th position will be zero, so the final price wont increase in chase option e is chosen.
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
                    printf("Any additional info?(Press Enter if you don't want to write.)\n>");
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
    return 0;
}
void getcustomerdata(char *name, char *password)
{
    printf("Welcome to Food Thingies!\n");
    printf("Please Sing in to continue!\n");
    printf("--Username\n>");
    gets(name);
    printf("--Password\n>");
    gets(password);
}
