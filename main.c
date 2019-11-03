#include <stdio.h>
#include <string.h>
#include "display.h"
#include "choosing.h"

#define MAX_FOOD_NAME 100
#define MAX_FOOD_TYPE_NAME 100
#define MAX_DRINK_NAME 100

int choicevalue(int *state, int nochoices);

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
    int state=0, price=0, sign=0, chosefood=0, chosefoodtipe=0,chosedrink=0, cutlery=0;
    while(sign==0)
    {
        switch(state) {
            case 0: {
                printf("Welcome to Food Thingies!\n");
                printf("Please Sing in to continue!\n");
                printf("--Username\n>");
                gets(name);
                printf("--Password\n>");
                gets(pas);
                state = 1;
                break;
            }
            case 1: {
                printf("Please choose the food you feel like eating today:\n");
                displayfood(nofood,food);
                chosefood=choicevalue(&state, nofood);
                break;
            }
            case 2: {
                printf("Please choose the type of %s:\n", food[chosefood]);
                displayfood(nofoodtype[chosefood],foodtype[chosefood]);
                chosefoodtipe=choicevalue(&state, nofoodtype[chosefood]);
                break;
            }
            case 3:
            {
                printf("Please choose a drink to go with your %s:\n" ,food[chosefood]);
                displaydrink(nodrink,drink);
                int nrofchoice=nodrink+1;//since there is one more option than the nr of drinks, it is necessary to increase the number of choices by 1
                chosedrink= choicevalue(&state,nrofchoice);
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
                printf("\n Your order:\n");
                printf("Name: %s\n",name);
                printf("Food items:\n");
                printf("---%s: %d\n", foodtype[chosefood][chosefoodtipe], foodprice[chosefood][chosefoodtipe]);
                if(chosedrink!=nodrink)
                    printf("---%s: %d\n",drink[chosedrink],drinkprice[chosedrink]);
                if(cutlery==0)
                    printf("Cutlery: yes\n");
                else
                    printf("Cutlery: no\n");
                if(strlen(comment)!=0)
                printf("Additional info: %s\n", comment);
                price=foodprice[chosefood][chosefoodtipe]+drinkprice[chosedrink];
                printf("Payment amount: %d\n\n", price);
                printf("a) Confirm order\n");
                printf("b) Go back\n>");
                finalchoice(&state,&sign,name);
                break;
            }
        }
    }

    return 0;
}

