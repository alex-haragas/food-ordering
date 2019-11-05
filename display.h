//
// Created by Alex on 03.11.2019.
//

#ifndef FOOD_ORDERING_DISPLAY_H
#define FOOD_ORDERING_DISPLAY_H

void displayfood(int nofood, char food[][100]);//It displays food options.
void displayfoodtype(int nofood, char foodtype[][100], int price[], char food[]);//It display the types available for the chosen food and their prices.
void displaydrink(int nodrink, char drink[][100], int price[], char food[]);//It displays drink options. I would have used the displayfood function, but I wanted to have it display the "No thanks option!".
void displaycutlery();//It displays the "Yes"/"No"/"Go back" options for the cutlery selection.
void displayreceipt(char name[], char food[], int foodprice, char drink[], int drinkprice, int isdrink,int cutlery, char comment[]);//It displays the receipt.
#endif //FOOD_ORDERING_DISPLAY_H
