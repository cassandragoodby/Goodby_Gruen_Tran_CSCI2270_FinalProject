# Goodby_Gruen_Tran_CSCI2270_FinalProject
# contributer
Project	Summary:
Final Project for data structures spring 2016. Our group is planning to have a program that can read in a file of groceries, types, prices and stock and the user would be able to go shopping and choose the items they would like to buy. Then it will allow a check out and inform the user of how much it costs as well as what items/types they bought and reduce the stock. 

How	to	Run:
When this project runs, a menu will first open up with four different options.

1: Print Inventory
2: Shop Item
3: Check Out
4. Delete item in cart
5. Print amount of options
6: Quit

(1) When the user presses 1 the entire list is printed out for the user. 
What is displayed is:
    Type: what the product is, such as milk, bread, vegetables.
    Brand: What the name of the product is, such as whole, white, carrots.
    Price: The cost associated with that item.
    Stock: How much of that item there is.
    
(2) When the user presses 2, hopefully looking at all the items gave them an idea of what they wanted.
    Enter Product wanted will pop up and type in the type of products you want. (EX: milk, bread, vegetables)
        1. Print Brands
        2. Print Prices
        3. Print Stock
        4. Print Rating
        5. Print All
        6. Choose Option with brand name:
        7. Go back to main menu
        
        (1-5) Prints different infromation for the type of food you are interested in buying depending on what you want to look at for information on what to buy. Always prints brand name because that is what is used to put in cart. 
        (6) Please enter the brand of food you would like to place in your cart:
        This allows you to put brand name (EX for milk brand would be chocolate, organic or 2%)
        This will add it to the cart linked list and decrease stock by one.
        (7) Returns back to main menu
        
(3) Check out prints reciept of all items in cart as well as total price.

(4) Delete item in cart pops up the question choose item in cart to be deleted: This type in the type (EX milk,  vegetable,     bread) then pops up Choose item brand in cart to be deleted: Put in brand name. This will remove from cart linked list     increase quantity in BST.

(5) Print amount of options tells you how many options there are to put in cart

(6) Quits and delete/clears BST to clear memory.

Dependencies:
Everything is included in file to run properly on codeblocks.
Do not use capitilzation or spaces while typing in.
Print (option 1) first to see options for buying. This will explain type vs brand.

System	Requirements:
Runs through codeblocks on VM. Will download the .cpp, .h and main.cpp if you would like to implement it using another option.

Group	Members:
Cassandra Goodby, Amanda Tran, Jon Gruen

Contributors:

ADD IF YOU CONTRIBUTE

Open	issues/bugs:

LIST ANY BUGS OR IDEAS YOU HAVE HERE
