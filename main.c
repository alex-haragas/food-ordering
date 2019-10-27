#include <stdio.h>
#include <string.h>
int main( )
{
    char name[100], pas[100], comment[100]="\0";
    char food [3][100]={"Pizza","Pasta","Salad"};
    int nofood=3;
    int nofoodtipe[4]={3,2,4};
    char foodtipe[3][4][100]={{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
                             {"Chicken alfredo", "Mac & cheese"},
                             {"Tuna Salad","Chicken Salad", "Greek Salad", "Cobb"}};
    int  foodprice[3][4]={{21,23,19},
                          {23,21},
                          {23,22,19,21}};
    int nodrink=4;
    char drink[4][100]={"Coca-cola","Fanta","Lipton","Water"};
    int drinkprice[5]={5,5,5,4}; // The 5th position will be zero, so the final price wont increase in chase option e is chosen.
    int state=0, price=0, sign=0, chosefood=0, chosefoodtipe=0,chosedrink=0, cutlery;
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
                char choice;
                for (int i = 0; i < nofood; i++) {
                    printf("%c) %s \n", 'a' + i, food[i]);
                }
                printf("%c) Go back \n>", 'a' + nofood);
                choice = getchar();
                getchar();
                chosefood = choice - 'a';
                if (chosefood == nofood)
                    state = 0;
                else
                    state = 2;
                break;
            }
            case 2: {
                printf("Please choose the type of %s:\n", food[chosefood]);
                char choice;
                for (int i = 0; i < nofoodtipe[chosefood]; i++) {
                    printf("%c) %s \n", 'a' + i, foodtipe[chosefood][i]);
                }
                printf("%c) Go back \n>", 'a' + nofoodtipe[chosefood]);
                choice = getchar();
                getchar();
                chosefoodtipe = choice - 'a';
                if (chosefoodtipe == nofoodtipe[chosefood])
                    state = 1;
                else
                    state = 3;
                break;
            }
            case 3:
            {
                printf("Please choose a drink to go with your %s:\n" ,food[chosefood]);
                char choice;
                for(int i=0;i<nodrink;i++)
                {
                    printf("%c) %s \n",'a'+i,drink[i]);
                }
                printf("%c) No, thanks!\n", 'a'+nodrink);
                printf("%c) Go back \n>",'a'+nodrink+1);
                choice=getchar();
                getchar();
                chosedrink=choice-'a';
                if(chosedrink==nodrink+1)
                    state=2;
                else
                    state=4;
                break;
            }
            case 4:
            {
                printf("Do you want cutlery?\n");
                printf("a) Yes\n");
                printf("b) No thanks!\n");
                printf("c) Go back!\n>");
                char choice;
                choice=getchar();
                getchar();
                cutlery=choice-'a';
                if(cutlery==2)
                    state=3;
                else
                    state=5;
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
                printf("---%s: %d\n",foodtipe[chosefood][chosefoodtipe], foodprice[chosefood][chosefoodtipe]);
                if(chosedrink!=nodrink)
                    printf("---%s: %d\n",drink[chosedrink],drinkprice[chosedrink]);
                if(cutlery==0)
                    printf("Cutlery: no\n");
                else
                    printf("Cutlery: yes\n");
                if(strlen(comment)!=0)
                printf("Additional info: %s\n", comment);
                price=foodprice[chosefood][chosefoodtipe]+drinkprice[chosedrink];
                printf("Payment amount: %d\n\n", price);
                printf("a) Confirm order\n");
                printf("b) Go back\n>");
                char choice;
                choice=getchar();
                getchar();
                if(choice=='a')
                {
                    sign=1;
                    printf("Order confirmed! Thank you for buying from us, %s",name);
                }
                else
                    state=4;
                break;
            }
        }
    }
    return 0;
}
