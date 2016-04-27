#ifndef SHOPPING_H
#define SHOPPING_H
#include <iostream>

struct Rec{
    std::string name;
    std::string brand;
    int cost;
    Rec *next = NULL;
};

struct ShoppingNode{
    std::string type;
    std::string brand;
    int price;
    int quantity;
    int rating;
    ShoppingNode *parent;
    ShoppingNode *leftChild;
    ShoppingNode *rightChild;

    ShoppingNode(){};

    ShoppingNode(std::string in_type, std::string in_brand, int in_price, int in_quantity, int in_rating)
    {
        type = in_type;
        brand = in_brand;
        price = in_price;
        quantity = in_quantity;
        rating = in_rating;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

};

class Shopping
{

    public:
        Shopping();
        ~Shopping();
        void printFoodInventory();
        void putitemincart(std::string userTitle, std::string userBrand);
        int countFoodNodes();
        void deleteFoodNode(std::string title);
        void addFoodNode(std::string type, std::string brand, int price, int quantity, int rating);
        void findFood(std::string title, std::string printType);
        void rentFood(std::string title);
        void insert1(std::string name, std::string brand, int cost);
        void delete1(std::string usertype, std::string userbrand);
        void printpath();
        Rec *head = NULL;
        Rec *tail = NULL;

    protected:

    private:
        void DeleteAll(ShoppingNode * node); //use this for the post-order traversal deletion of the tree
        void printFoodInventory(ShoppingNode * node);
        int countFoodNodes(ShoppingNode *node);
        ShoppingNode* search(std::string title);
        ShoppingNode* treeMinimum(ShoppingNode *node);
        ShoppingNode *root = NULL;
};

#endif
