#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
    //create + declare instance variables
    private: 
        string name;
        int quantity;
        double price;

    public:
        //constructor, all variables included
        Item (string n, int q, double p) {
            name = n;
            quantity = q;
            price = p;
        }

        //display information / attributes
        void displayItem() {
            std::cout << "\nName of item: " << name 
                << "\nAvaliable units: " << quantity 
                << "\nPrice of unit: " << price;
        }

        //accessor for the item's name
        string getName() {
            return name;
        }

        //mutator of quantity (positive)
        void addItem(int amount) {
            quantity = quantity + amount;
        }

        //mutator of quantity (negative)
        void removeItem(int amount) {
            quantity = quantity - amount;
        }

        //multiply the price and quantity to get the value
        double calculateTotalValue() {
            return price * quantity;
        }
};

class Inventory {
    //create + declare instance variables
    private:
        vector<Item> items;
        int itemCount;
    public:
        //constructor, no variables included
        Inventory () {
            itemCount = 0;
        }

        //add an item object to the inventory array
        //check if the inventory has open space left
        void addItem(const Item& newItem) {
            if (itemCount < 64) {
                items.push_back(newItem);
                itemCount = itemCount + 1;
            } else {
                std::cout << "Inventory full.";
            }
        }

        //accessor for the size of the vector
        int getInventorySize() {
            return itemCount;
        }

        //remove an item from the array, located by name
        //check if there are enough items and if the named item is in the vector
        void removeItem(const string& itemName) {
            if (itemCount > 0) {
                //look through the vector to check for an item with the given name
                for (int i = items.size() - 1; i > -1; i--) {
                    if (items.at(i).getName().compare(itemName)) {
                        items.erase(items.begin() + i);
                        itemCount = itemCount - 1;
                    }
                }
            } else {
                std::cout << "Inventory empty.";
            }
        }

        //display all items stored in the array
        void displayInventory() {
            for (int i = 0; i < items.size(); i++) {
                items.at(i).displayItem();
            }
        }

        //find a pointer to an item based off of its name
        Item* findItem(const string& itemName) {
            for (int i = items.size() - 1; i > -1; i--) {
                    if (items.at(i).getName().compare(itemName)) {
                        return &items.at(i);
                    }
                }
        }

        //find a pointer to an item based off of its location
        Item findItemLoc(int num) {
            return items.at(num);
        }
};

int main() {
    double totalPrice = 0.0;
    Inventory inventory;
    Item dirt("dirt", 3, 4.0);
    Item diamond("diamond", 1, 50.0);

    inventory.addItem(dirt);
    inventory.addItem(diamond);
    inventory.displayInventory();
    for (int i = 0; i < inventory.getInventorySize(); i++) {
        //cout << inventory.findItemLoc(i);
        totalPrice += inventory.findItemLoc(i).calculateTotalValue();
    }
    std::cout << totalPrice;
    inventory.removeItem("dirt");
    inventory.displayInventory();

}