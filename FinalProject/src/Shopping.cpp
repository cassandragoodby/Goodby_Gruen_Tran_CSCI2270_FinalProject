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

void Shopping::returnitemtoinventory(string userTitle, string userBrand)
{
    ShoppingNode *temp = root;
     while(temp != NULL)
     {
         if(userTitle == temp->type && userBrand == temp->brand) {
         Shopping::insert1(temp->type, temp->brand, temp->price);
         break;
         }

        else if(userTitle>=temp->type){
        temp= temp->rightChild;
        }

        else {
        temp=temp->leftChild;
        }
        temp->quantity++; //increase the stock

    }
    if(temp == NULL)
    {
        cout << "Food item not found" << endl;
    }

}
void Shopping::putitemincart(string userTitle, string userBrand){
     ShoppingNode *temp = root;
     while(temp != NULL)
     {
         if(userTitle == temp->type && userBrand == temp->brand) {
         Shopping::insert1(temp->type, temp->brand, temp->price);
         break;
         }

        else if(userTitle>=temp->type){
        temp= temp->rightChild;
        }

        else {
        temp=temp->leftChild;
        }

        if(temp->quantity == 0)
        {
            cout << "Food out of stock." << endl;
        }

        else
        {
            temp->quantity--; //decrease the stock
            if(temp->quantity == 0)
            {
                deleteFoodNode(temp->type, temp->brand); //delete if quantity reaches zero
            }
        }
    }
    if(temp == NULL)
    {
        cout << "Food item not found" << endl;
    }

 }

void Shopping::delete1(std::string userbrand)
{
    Rec *curr = head;
    Rec *nodetodelete;
    if(head->brand == userbrand){
        head = head->next;
        delete curr;
        return;
    }
    Rec *previous;
    while(curr != NULL && curr->brand != userbrand){
       previous = curr;
       curr = curr->next;
    }
    if(curr != NULL)
    {
        previous->next = curr->next;
        delete curr;
    }
    else{
        cout << "not found" << endl;
    }
}

void Shopping::deleteitemfromcart(string userTitle, string userBrand)
{
    ShoppingNode *temp = root;
    if (temp == NULL)
    {
        cout<<"Item not found."<<endl;
    }
    else
    {
        deleteFoodNode(temp->type, temp->brand);
    }
    while(temp != NULL)
    {
        if(userTitle == temp->type && userBrand == temp->brand) {
        deleteFoodNode(temp->type, temp->brand);
        Shopping::delete1(userBrand);
        break;
        }

        else if(userTitle>=temp->type){
        temp= temp->rightChild;
        }

        else {
        temp=temp->leftChild;
        }

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
            while(printType == "types"&&userTitle == temp->type){
                cout << "===========" << endl;
                cout << "Type: " << temp->brand << endl;
                //cout << "Food Type:" << temp->type << endl;
               // cout << "Price:" << temp->price << endl;
                //cout << "Quantity:" << temp->quantity << endl;
               // cout << "Rating:"<<temp->rating<<endl;
                break;
            }
            while(printType == "prices"&&userTitle == temp->type){
                cout << "===========" << endl;
                cout << "Price: $" << temp->price << endl;
                cout << "Type: " << temp->brand << endl;
                //cout << "Food Type:" << temp->type << endl;
               // cout << "Quantity:" << temp->quantity << endl;
               // cout << "Rating:"<<temp->rating<<endl;
                break;
            }
            while(printType == "stock"&&userTitle == temp->type){
                cout << "===========" << endl;
                cout << "Quantity: " << temp->quantity << endl;
        //print function for stock. to update. recursive like print function??
               // cout << "Price:" << temp->price << endl;
                cout << "Type: " << temp->brand << endl;
               // cout << "Food Type:" << temp->type << endl;
                //cout << "Rating:"<<temp->rating<<endl;
                break;
            }
            while(printType == "rating"&&userTitle == temp->type){
                cout << "===========" << endl;
                cout << "Rating: "<<temp->rating<<endl;
               // cout << "Quantity:" << temp->quantity << endl;
                //cout << "Price:" << temp->price << endl;
                cout << "Type: " << temp->brand << endl;
                //cout << "Food Type:" << temp->type << endl;
                break;
            }
            while(printType == "all"&&userTitle==temp->type){
                cout << "===========" << endl;
                cout << "Food Item: " << temp->type << endl;
                cout << "Type: " << temp->brand << endl;
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

void Shopping::deleteFoodNode(string title, string brand){
    ShoppingNode *tmp = root;
    while(tmp != NULL)
    {
        if(tmp->type == title)
        {
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

/*void Shopping::clearShoppingCart()
{
    clearShoppingCart(root);
}

void Shopping::clearShoppingCart(ShoppingNode *temp){
   if(temp->leftChild != NULL){
    clearShoppingCart(temp->leftChild);
   }
   if(temp->rightChild != NULL){
    clearShoppingCart(temp->rightChild);
   }
   cout<<"Deleting: "<<temp->type<<endl;
   delete temp;
   temp->quantity++;

}
*/

