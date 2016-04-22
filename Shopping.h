#ifndef MOVIETREE_H
#define MOVIETREE_H
#include <iostream>

struct ShoppingNode{
    std::string type;
    std::string brand;
    int price;
    int quantity;
    ShoppingNode *parent;
    ShoppingNode *leftChild;
    ShoppingNode *rightChild;

    ShoppingNode(){};

    ShoppingNode(std::string in_type, std::string in_brand, int in_price, int in_quantity)
    {
        type = in_type;
        brand = in_brand;
        price = in_price;
        quantity = in_quantity;
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
        void printMovieInventory();
        int countMovieNodes();
        void deleteMovieNode(std::string title);
        void addMovieNode(std::string type, std::string brand, int price, int quantity);
        void findMovie(std::string title);
        void rentMovie(std::string title);

    protected:

    private:
        void DeleteAll(ShoppingNode * node); //use this for the post-order traversal deletion of the tree
        void printMovieInventory(ShoppingNode * node);
        int countMovieNodes(ShoppingNode *node);
        ShoppingNode* search(std::string title);
        ShoppingNode* treeMinimum(ShoppingNode *node);
        ShoppingNode *root;
};

#endif // MOVIETREE_H
