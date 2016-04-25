#include "Shopping.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Shopping::Shopping()
{
    root = NULL;
}

Shopping::~Shopping()
{
    //DeleteAll(root);
}

void Shopping::printpath()
{
    Rec *curr = head;
    cout << "=====Receipt=====" << endl;
    while(curr != NULL)
    {
        cout << curr->name <<" "<<curr->brand <<" "<< curr->cost <<endl;
        curr = curr->next;
    }

    cout << "=================" << endl;

}

void Shopping::insert1(std::string name, std::string brand, int cost){
	Rec *newNode = new Rec();
	newNode->name = name;
	newNode->brand = brand;
	newNode->cost = cost;

	if(head == NULL){
		head = newNode;

	}
	else{
		Rec* curr = head;
		while (curr->next != NULL){
			curr = curr->next;
		}
		curr->next = newNode;
	}
	//size++;
}

void Shopping::putitemincart(string userTitle, string userBrand){
     ShoppingNode *temp = root;
    while(temp!= NULL){

     if(userTitle == temp->type && userBrand == temp->brand) {

         Shopping::insert1(temp->type, temp->brand, temp->price);
         break;
         //Shopping::insert1(temp->type, temp->brand, temp->price);
         //Shopping::insert1(bread, nbread, x);
     }

     else if(userTitle>=temp->type){
         temp= temp->rightChild;
     }

     else {
         temp=temp->leftChild;
     }
     }
     if(temp==NULL){
         cout<< "Item not found."<<endl;
     }

 }



void Shopping::addFoodNode(std::string type,std::string brand, int price, int quantity,int rating){
    ShoppingNode *node=new ShoppingNode(type,brand,price,quantity,rating);
    ShoppingNode *temp = root;
    ShoppingNode *parent=NULL;

    while(temp!=NULL){
        parent=temp;
        if(node->type.compare(temp->type)<0){
            temp=temp->leftChild;
        }
        else{
            temp=temp->rightChild;
        }
    }
    if(parent==NULL){
        root=node;
    }
    else if(node->type.compare(parent->type)<0){
        parent->leftChild=node;
        node->parent=parent;
    }
    else{
        parent->rightChild=node;
        node->parent=parent;
    }
}

void Shopping::findFood(string userTitle, string printType = ""){
    ShoppingNode *temp = root;


    while(temp!= NULL){


    //if(userTitle == temp->type) {
            while(printType == "brands"&&userTitle == temp->type){
                cout << "===========" << endl;
                cout << "Brand: " << temp->brand << endl;
                //cout << "Food Type:" << temp->type << endl;
               // cout << "Price:" << temp->price << endl;
                //cout << "Quantity:" << temp->quantity << endl;
               // cout << "Rating:"<<temp->rating<<endl;
                break;
            }
            while(printType == "prices"&&userTitle == temp->type){
                cout << "===========" << endl;
                cout << "Price: $" << temp->price << endl;
                cout << "Brand: " << temp->brand << endl;
                //cout << "Food Type:" << temp->type << endl;
               // cout << "Quantity:" << temp->quantity << endl;
               // cout << "Rating:"<<temp->rating<<endl;
                break;
            }
            while(printType == "stock"&&userTitle == temp->type){
                cout << "===========" << endl;
                cout << "Quantity: " << temp->quantity << endl;
               // cout << "Price:" << temp->price << endl;
                cout << "Brand: " << temp->brand << endl;
               // cout << "Food Type:" << temp->type << endl;
                //cout << "Rating:"<<temp->rating<<endl;
                break;
            }
            while(printType == "rating"&&userTitle == temp->type){
                cout << "===========" << endl;
                cout << "Rating: "<<temp->rating<<endl;
               // cout << "Quantity:" << temp->quantity << endl;
                //cout << "Price:" << temp->price << endl;
                cout << "Brand: " << temp->brand << endl;
                //cout << "Food Type:" << temp->type << endl;
                break;
            }
            while(printType == "all"&&userTitle==temp->type){
                cout << "===========" << endl;
                cout << "Food Type: " << temp->type << endl;
                cout << "Brand: " << temp->brand << endl;
                cout << "Price: $" << temp->price << endl;
                cout << "Quantity: " << temp->quantity << endl;
                cout << "Rating: "<<temp->rating<<endl;
                break;
            }


        //break;
    //}

    if(userTitle>=temp->type){
        temp= temp->rightChild;
    }

    else {
        temp=temp->leftChild;
    }

    }


}


void Shopping::rentFood(string userTitle){
    ShoppingNode *temp = root;
    while(temp!= NULL){

    if(userTitle == temp->type && temp->quantity!=0) {
        temp->quantity--;
        cout << "Food has been taken." << endl;
        cout << "Food Info:" << endl;
        cout << "===========" << endl;
        cout << "Food Type:" << temp->type << endl;
        cout << "Brand:" << temp->brand << endl;
        cout << "Price:" << temp->price << endl;
        cout << "Quantity:" << temp->quantity << endl;
        break;
    }
        else if (temp->quantity==0){
        cout<<"Food out of stock."<<endl;
        break;
    }

    else if(userTitle>=temp->type){
        temp= temp->rightChild;
    }
    else {
        temp=temp->leftChild;
    }
    }

    if(temp==NULL){
        cout<< "Food not found."<<endl;
    }
if(temp!=NULL){
    if (temp->quantity==0){
    deleteFoodNode(userTitle);
    }
}

}

void Shopping::printFoodInventory(){
    printFoodInventory(root);
}

void Shopping::printFoodInventory(ShoppingNode *temp){
    if (temp->leftChild!=NULL){
        printFoodInventory(temp->leftChild);
    }
        cout << "===========" << endl;
        cout << "Type:" << temp->type << endl;
        cout << "Brand:" << temp->brand << endl;
        cout << "Price:" << temp->price << endl;
        cout << "Quantity:" << temp->quantity << endl;
    if (temp->rightChild!=NULL){
        printFoodInventory(temp->rightChild);
    }
}

void Shopping::deleteFoodNode(string title){
    ShoppingNode *tmp = root;
    while(tmp != NULL){
        if(tmp->type == title){
            break;
    }
    else if(title >= tmp->type){
            tmp = tmp->rightChild;
        }
        else{
            tmp = tmp->leftChild;
        }
    }
    if(tmp == NULL){
        cout<<"Food not found."<<endl;
    }

    else{
        if(tmp->leftChild == NULL && tmp->rightChild == NULL){     //none
            //cout << "No child deleting"<<endl;
            if(tmp->parent->leftChild == tmp){
                tmp->parent->leftChild = NULL;
            }
            else{
                tmp->parent->rightChild = NULL;
            }
            delete tmp;
        }

    else if(tmp->leftChild == NULL && tmp->rightChild != NULL){ //one right
            //cout << "One right child deleting"<<endl;
            ShoppingNode *x = tmp->rightChild;
            if(tmp==tmp->parent->rightChild){
                tmp->parent->rightChild = x;
            }
            if(tmp==tmp->parent->leftChild){
                tmp->parent->leftChild = x;
            }
            x->parent = tmp->parent;
            delete tmp;
    }
    else if(tmp->rightChild == NULL && tmp->leftChild != NULL){ //one left
           // cout << "One left child Deleting"<<endl;
            ShoppingNode *x = tmp->leftChild;
            if(tmp==tmp->parent->rightChild){
                tmp->parent->rightChild = x;
            }
            if(tmp==tmp->parent->leftChild){
                tmp->parent->leftChild = x;
            }
            x->parent = tmp->parent;
            delete tmp;
    }

    else if(tmp->rightChild != NULL && tmp->leftChild != NULL){  //replacing
        ShoppingNode *x = tmp->rightChild;
        while (x->leftChild != NULL){
            x = x->leftChild;
        }

        if(tmp != root){

        if(tmp->parent->leftChild == tmp){
            if(x == tmp->rightChild){
                tmp->parent->leftChild = x;
                x->parent = tmp->parent;
                x->leftChild = tmp->leftChild;
            }
            else{
                x->parent->leftChild = x->rightChild;
                x->parent = tmp->parent;
                x->rightChild->parent = x->parent;
                tmp->parent->leftChild = x;
                x->leftChild = tmp->leftChild;
                x->rightChild = tmp->rightChild;
                tmp->rightChild->parent = x;
                tmp->leftChild->parent = x;
            }
        }
        else{
            if(x == tmp->rightChild){
                tmp->parent->rightChild = x;
                x->parent = tmp->parent;
            }
            else{
                x->parent->leftChild = x->rightChild;
                x->parent = tmp->parent;
                x->rightChild->parent = x->parent;
                tmp->parent->rightChild = x;
                x->leftChild = tmp->leftChild;
                x->rightChild = tmp->rightChild;
                tmp->rightChild->parent = x;
                tmp->leftChild->parent = x;
            }


        }
        delete tmp;

        }
    }
}
}

int Shopping::countFoodNodes(){
    countFoodNodes(root);
}

int Shopping::countFoodNodes(ShoppingNode *node){
    if(node==NULL){
        return 0;
    }
    else{
        return countFoodNodes(node->leftChild)+countFoodNodes(node->rightChild)+1;
    }
}

void Shopping::DeleteAll(ShoppingNode *node){
   if(node->leftChild != NULL){
    DeleteAll(node->leftChild);
   }
   if(node->rightChild != NULL){
    DeleteAll(node->rightChild);
   }
   cout<<"Deleting: "<<node->type<<endl;
   delete node;

}

