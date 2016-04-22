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

void Shopping::addMovieNode(std::string type,std::string brand, int price, int quantity){
   // cout<<"add movie called"<<endl;
    ShoppingNode *node=new ShoppingNode(type,brand,price,quantity);
    //cout<<type<<" "<<brand<<endl;
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

void Shopping::findMovie(string userTitle){
    ShoppingNode *temp = root;
    while(temp!= NULL){

    if(userTitle == temp->type) {
        cout << "Food Info:" << endl;
        cout << "===========" << endl;
        cout << "Type:" << temp->type << endl;
        cout << "Brand:" << temp->brand << endl;
        cout << "Price:" << temp->price << endl;
        cout << "Quantity:" << temp->quantity << endl;
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
        cout<< "Movie not found."<<endl;
    }

}


void Shopping::rentMovie(string userTitle){
    ShoppingNode *temp = root;
    while(temp!= NULL){

    if(userTitle == temp->type && temp->quantity!=0) {
        temp->quantity--;
        cout << "Food has been taken." << endl;
        cout << "Food Info:" << endl;
        cout << "===========" << endl;
        cout << "Movie:" << temp->type << endl;
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
    deleteMovieNode(userTitle);
    }
}

}

void Shopping::printMovieInventory(){
    printMovieInventory(root);
}

void Shopping::printMovieInventory(ShoppingNode *temp){
    if (temp->leftChild!=NULL){
        printMovieInventory(temp->leftChild);
    }
    cout << "Type: "<<temp->type<<" "<<temp->quantity << endl;
    if (temp->rightChild!=NULL){
        printMovieInventory(temp->rightChild);
    }
}

void Shopping::deleteMovieNode(string title){
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

int Shopping::countMovieNodes(){
    countMovieNodes(root);
}

int Shopping::countMovieNodes(ShoppingNode *node){
    if(node==NULL){
        return 0;
    }
    else{
        return countMovieNodes(node->leftChild)+countMovieNodes(node->rightChild)+1;
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

