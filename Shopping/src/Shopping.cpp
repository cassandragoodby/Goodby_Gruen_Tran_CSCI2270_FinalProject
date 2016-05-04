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
    DeleteAll(root);
}

void Shopping::printpath() //prints receipt and total cost
{
    Rec *curr = head;
    int sum = 0;
    int x;
    cout << "" << endl;
    cout << "=====Receipt=====" << endl;
    while(curr != NULL&& head != NULL)
    {
        cout << curr->name <<" "<<curr->brand <<" "<< curr->cost <<endl;
        x = curr->cost;
        sum = sum + x;
        curr = curr->next;

    }
    cout << "_________________"<< endl;
    cout << " Total Cost:  "<< sum << endl;
    cout << "=================" << endl;
    cout << "" << endl;

}

void Shopping::insert1(std::string name, std::string brand, int cost){ //inserts item into linked list that you put in cart
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

void Shopping::putitemincart(string userTitle, string userBrand){ //puts item in linked list and decreases quantity for BST
     ShoppingNode *temp = root;
    while(temp!= NULL){

     if(userTitle == temp->type && userBrand == temp->brand) {

         insert1(temp->type, temp->brand, temp->price);
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

     else if(temp->quantity == 0){
        cout << "Food not in stock"<<endl;
     }
     else{
        temp->quantity--;
        if(temp->quantity == 0){
            deleteFoodNode(temp->type,temp->brand);
        }
    }


 }



void Shopping::addFoodNode(std::string type,std::string brand, int price, int quantity,int rating){ //builds BST from reading file
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

void Shopping::findFood(string userTitle, string printType){ //searches through BST for food
    ShoppingNode *temp = root;


    while(temp!= NULL){

    //if(userTitle == temp->type) {
            if(printType == "brands"&&userTitle == temp->type){
                cout << "===========" << endl;
                cout << "Brand: " << temp->brand << endl;
                //cout << "Food Type:" << temp->type << endl;
               // cout << "Price:" << temp->price << endl;
                //cout << "Quantity:" << temp->quantity << endl;
               // cout << "Rating:"<<temp->rating<<endl;
                break;
            }
            else if(printType == "prices"&&userTitle == temp->type){
                cout << "===========" << endl;
                cout << "Price: $" << temp->price << endl;
                cout << "Brand: " << temp->brand << endl;
                //cout << "Food Type:" << temp->type << endl;
               // cout << "Quantity:" << temp->quantity << endl;
               // cout << "Rating:"<<temp->rating<<endl;
                break;
            }
            else if(printType == "stock"&&userTitle == temp->type){
                cout << "===========" << endl;
                cout << "Quantity: " << temp->quantity << endl;
               // cout << "Price:" << temp->price << endl;
                cout << "Brand: " << temp->brand << endl;
               // cout << "Food Type:" << temp->type << endl;
                //cout << "Rating:"<<temp->rating<<endl;
                break;
            }
            else if(printType == "rating"&&userTitle == temp->type){
                cout << "===========" << endl;
                cout << "Rating: "<<temp->rating<<endl;
               // cout << "Quantity:" << temp->quantity << endl;
                //cout << "Price:" << temp->price << endl;
                cout << "Brand: " << temp->brand << endl;
                //cout << "Food Type:" << temp->type << endl;
                break;
            }
            else if(printType == "all"&&userTitle==temp->type){
                cout << "===========" << endl;
                cout << "Food Type: " << temp->type << endl;
                cout << "Brand: " << temp->brand << endl;
                cout << "Price: $" << temp->price << endl;
                cout << "Quantity: " << temp->quantity << endl;
                cout << "Rating: "<<temp->rating<<endl;
                break;
            }
            else{
                if(userTitle>=temp->type){
                    temp= temp->rightChild;
                    //cout<<"Moved right."<<endl;
                }

                else {
                    temp=temp->leftChild;
                    //cout<<"Moved left."<<endl;
                }//I DID THIS
            }


        //break;
    //}

    /*if(userTitle>=temp->type){
        temp= temp->rightChild;
        cout<<"Moved right."<<endl;
    }

    else {
        temp=temp->leftChild;
        cout<<"Moved left."<<endl;
    }*////I DID THIS

    }



}


void Shopping::rentFood(string userTitle){ //decreases quantity
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
    deleteFoodNode(userTitle,temp->brand);
    }
}

}

void Shopping::printFoodInventory(){ //prints BST
    printFoodInventory(root);
}

void Shopping::printFoodInventory(ShoppingNode *temp){ //print BST using recursion
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

void Shopping::deleteFoodNode(string title, string brand){ //deletes a node in linked list
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

int Shopping::countFoodNodes(){ //counts nodes in BST for options
    cout<<countFoodNodes(root);
}

int Shopping::countFoodNodes(ShoppingNode *node){
    if(node==NULL){
        return 0;
    }
    else{
        return countFoodNodes(node->leftChild)+countFoodNodes(node->rightChild)+1;
    }
}

void Shopping::DeleteAll(ShoppingNode *node){ //clears memory
   if(node->leftChild != NULL){
    DeleteAll(node->leftChild);
   }
   if(node->rightChild != NULL){
    DeleteAll(node->rightChild);
   }
   cout<<"Deleting: "<<node->type<<endl;
   delete node;

}

void Shopping::delete1(std::string usertype, std::string userbrand){ //deletes item from shopping cart
    if(head == NULL){
        cout<<"No Item Found"<<endl;
    }
    Rec *tmp = head;
    if(tmp != NULL){
	if (head->name == usertype && head->brand == userbrand){
        if(head->next !=NULL){
		Rec *tmp = head;
		head = head-> next;
		delete tmp;
        }
        else{
            //delete head;
            head= NULL;
        }
	}
    if(head != NULL){
		Rec *left = head;
    //cout<< "in if6"<<endl;
		Rec *tmp = head->next;
		//cout<< "in if7"<<endl;

		while (tmp != NULL){
			if( tmp->name == usertype && tmp->brand==userbrand){
				left-> next = tmp-> next;
				if (tmp == tail){
				left->next = NULL;
				tail = left;
				}
			delete tmp;
			break;
			}
		}

    }
	}
}

int Shopping::searchFood(std::string userInput, std::string printType){
    ShoppingNode *temp = root;
    int returnInt=0;
    while(temp!= NULL){

    //if(userTitle == temp->type) {
            if(userInput == temp->type){
               returnInt++;
                break;
            }
            else{
                if(userInput>=temp->type){
                    temp= temp->rightChild;
                    //cout<<"Moved right."<<endl;
                }

                else {
                    temp=temp->leftChild;
                    //cout<<"Moved left."<<endl;
                }//I DID THIS
            }
    }
    return returnInt;
}

