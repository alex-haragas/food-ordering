//
// Created by Alex on 03.11.2019.
//

#ifndef FOOD_ORDERING_DISPLAY_H
#define FOOD_ORDERING_DISPLAY_H

void customersignin();
void displaycutlery();//It displays the "Yes"/"No"/"Go back" options for the cutlery selection.
void displayreceipt(char* name, char* food, double foodprice, char* drink, double drinkprice, int isdrink,int cutlery,char* comment);//It displays the receipt.
#endif //FOOD_ORDERING_DISPLAY_H
