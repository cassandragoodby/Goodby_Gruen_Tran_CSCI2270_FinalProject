#include "Shopping.h"
#include <iostream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>

using namespace std;

//Cassandra Goodby, Jon Gruen, Amanda Tran, Thursday 11 AM 315

int main(int argc, char *argv[])
{
    string decision;
    ifstream inputfile;
    string data;
    Shopping run;
    inputfile.open("GroceryList");
    //inputfile.open(argv[1]);
    if(inputfile.good()) {

    while((getline(inputfile,data))){
            stringstream ss(data);

            string type;
            getline(ss,type,',');
            //int in_type=atoi(type.c_str());

            string brand;
            getline(ss,brand,',');
            //int in_brand=atoi(brand.c_str());

            string price;
            getline(ss,price,',');
            int in_price=atoi(price.c_str());

            string quantity;
            getline(ss,quantity,',');
            int in_quantity=atoi(quantity.c_str());

            string rating;
            getline(ss,rating,',');
            int in_rating=atoi(rating.c_str());

            run.addFoodNode(type,brand,in_price,in_quantity,in_rating);
    }
    }
        else{
        cout << "File not opened properly" << endl;
    }

    inputfile.close();


    cout << "======Main Menu======" << endl;
    cout << "1. Print the inventory" << endl;
    cout << "2. Shop Item" << endl;
    cout << "3. Check Out" << endl;
    cout << "4. Delete item in cart"<<endl;
    cout<<"5. Print amount of options"<<endl;
    cout << "6. Quit" << endl;
    getline(cin,decision);
    if (decision != "1" && decision != "2" && decision != "3" && decision != "4"&& decision != "5"&& decision != "6") {
            cout << "" << endl;
            cout << "Please Select a number 1-6" << endl;
            cout << "" << endl;
    }

    while(decision != "6"){
        if(decision == "2") {
            string userChoice;
            cout << "Enter Product wanted: " << endl;
            getline(cin,userChoice);
            int searchFoods=run.searchFood(userChoice,"");
            if(searchFoods==0){
                cout<<"This product was not found."<<endl;
                cout<<"Perhaps you were typing in a brand? Try again."<<endl;
            }else{

                run.findFood(userChoice,"");
                string decision2;
                while (decision2 != "7"){
                    cout << "1. Print Brands"<<endl;
                    cout << "2. Print Prices"<<endl;
                    cout << "3. Print Stock"<<endl;
                    cout << "4. Print Rating"<<endl;
                    cout << "5. Print All"<<endl;
                    cout << "6. Choose Option with brand name: "<<endl;
                    cout << "7. Go back to main menu"<<endl;
                    getline(cin, decision2);

                    if (decision2 != "1" && decision2 != "2" && decision2 != "3" && decision2 != "4" && decision2 != "5" && decision2 != "6" && decision2 != "7" ) {
                cout << "" << endl;
                cout << "Please Select a number 1-7" << endl;
                cout << "" << endl;
                     }

                    if (decision2 == "1"){
                    cout<<"Your options for brands for this type of item are as follows: "<<endl;
                    run.findFood(userChoice, "brands");
                    }
                    if (decision2== "2"){
                    cout<<"Your options for prices for this type of item are are as follows: "<<endl;
                    run.findFood(userChoice, "prices");
                    }
                    if (decision2== "3"){
                    cout<<"Your options for stock amounts for this type of item are are as follows: "<<endl;
                    run.findFood(userChoice, "stock");
                    }
                    if (decision2== "4"){
                    cout<<"Your options for ratings for this type of item are are as follows: "<<endl;
                    run.findFood(userChoice, "rating");
                    }
                    if (decision2== "5"){
                    cout<<"This is all the information for this type of item: "<<endl;
                    run.findFood(userChoice,"all");
                    }
                    if (decision2== "6"){
                    cout<<"Please enter the brand of food you would like to place in your cart: "<<endl;
                    string userBrand;
                    getline(cin,userBrand);
                    run.putitemincart(userChoice,userBrand);
                    }
                }//while decision2 isn't 7
            }//else loop


        }
        if (decision == "1") {
            cout << "Food Info:" << endl;
            run.printFoodInventory();
        }

        if (decision == "3"){
            run.printpath();
        }
        if(decision =="4"){
            string item;
            string brand;
            cout << "Choose item in cart to be deleted:"<<endl;
            getline(cin, item);
            cout<<"Choose item brand in cart to be deleted:"<<endl;
            getline(cin,brand);
            run.delete1(item,brand);
        }
        if(decision =="5"){
            cout<< "There are ";
            run.countFoodNodes();
            cout<<" options."<<endl;
        }

    cout << "======Main Menu======" << endl;
    cout << "1. Print the inventory" << endl;
    cout << "2. Shop Item" << endl;
    cout << "3. Check Out" << endl;
    cout << "4. Delete item in cart"<<endl;
    cout<<"5. Print amount of options"<<endl;
    cout << "6. Quit" << endl;
    getline(cin,decision);
    if (decision != "1" && decision != "2" && decision != "3" && decision != "4"&& decision != "5"&& decision != "6") {
            cout << "" << endl;
            cout << "Please Select a number 1-6" << endl;
            cout << "" << endl;
    }

    }

    if(decision=="5"){
        cout << "Goodbye!" << endl;
        //return 0;
    }

    return 0;

}
