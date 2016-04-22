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
    inputfile.open("ShoppingText");
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

            run.addMovieNode(type,brand,in_price,in_quantity);
    }
    }
        else{
        cout << "File not opened properly" << endl;
    }

    inputfile.close();


    cout << "======Main Menu======" << endl;
    cout << "1. Shop Item" << endl;
    cout << "2. Print the inventory" << endl;
    cout << "3. Check Out" << endl;
    cout << "4. Quit" << endl;
    getline(cin,decision);

    while(decision != "4"){
        if(decision == "1") {
            string userChoice;
            cout << "Enter Product wanted: " << endl;
            getline(cin,userChoice);
            run.findMovie(userChoice);
            string decision2;
            while (decision2 != "7"){
                cout << "1. Print Brands"<<endl;
                cout << "2. Print Prices"<<endl;
                cout << "3. Print Stock"<<endl;
                cout << "4. Print Rating"<<endl;
                cout << "5. Print All"<<endl;
                cout << "6. Choose Option with brand name: "<<endl;
                cout << "7. Go back to main menu"<<endl;
                getline(cin, userChoice);
                if (userChoice== "1"){

                }
                if (userChoice== "2"){

                }
                if (userChoice== "3"){

                }
                if (userChoice== "4"){

                }
                if (userChoice== "5"){

                }
                if (userChoice== "6"){

                }
            }
        }
        if (decision == "2") {
            run.printMovieInventory();
        }

        if (decision == "3"){

        }


    cout << "======Main Menu======" << endl;
    cout << "1. Shop Item" << endl;
    cout << "2. Print the inventory" << endl;
    cout << "3. Check Out" << endl;
    cout << "4. Quit" << endl;
    getline(cin,decision);
    }

    if(decision=="6"){
        cout << "Goodbye!" << endl;
    }

    return 0;

}
