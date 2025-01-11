#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Product {
    string name;
    double price;
};

void displayProducts(const vector<Product>& products) {
    for (size_t i = 0; i < products.size(); ++i) {
        cout << i + 1 << ". " << products[i].name << " - $" << fixed << setprecision(2) << products[i].price << "\n";
    }
}

int main() {
    vector<Product> gadgets = {
        {"Samsung phone A12", 199.99},
        {"Smart Panasonic tv", 799.99},
        {"Ps5", 499.99},
        {"Smart watch", 149.99},
        {"Laptop (Lenovo thinkpad)", 999.99},
        {"Iphone 17 pro", 1299.99}
    };

    vector<Product> accessories = {
        {"Phone case", 19.99},
        {"Charging cable type C", 9.99},
        {"Earbud", 29.99},
        {"Power bank", 39.99},
        {"Keyboard and mouse", 49.99},
        {"Mouse Pad", 9.99},
        {"Sony speaker", 99.99},
        {"Wired earphone", 14.99},
        {"Sound equipment", 199.99}
    };

    vector<Product> components = {
        {"Resistor (5 ohm)", 0.10},
        {"Capacitor(1 f)", 0.50},
        {"Battery lithium", 5.99},
        {"Led light", 0.20},
        {"Buzzer", 1.99},
        {"Transistor", 0.99},
        {"Switch", 2.99},
        {"Relay", 4.99},
        {"Connecting wire", 1.50},
        {"PCB board", 3.99},
        {"Bread board", 5.99},
        {"Soldering equipment", 24.99}
    };

    vector<Product> cart;
    int categoryChoice;
    int productChoice;

    cout << "Welcome to the store!\n";
    while (true) {
        cout << "\nCategories:\n";
        cout << "1. Gadgets\n2. Accessories\n3. Components\n4. Checkout\n";
        cout << "Enter the number of the category you want to browse: ";
        cin >> categoryChoice;

        if (categoryChoice == 4) break;

        vector<Product> *selectedCategory = nullptr;
        switch (categoryChoice) {
            case 1:
                selectedCategory = &gadgets;
                break;
            case 2:
                selectedCategory = &accessories;
                break;
            case 3:
                selectedCategory = &components;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                continue;
        }

        cout << "\nAvailable products:\n";
        displayProducts(*selectedCategory);

        cout << "\nEnter the number of the product you want to add to your cart (0 to go back): ";
        cin >> productChoice;

        if (productChoice == 0) continue;
        if (productChoice < 1 || productChoice > selectedCategory->size()) {
            cout << "Invalid product choice. Please try again.\n";
            continue;
        }

        cart.push_back((*selectedCategory)[productChoice - 1]);
        cout << (*selectedCategory)[productChoice - 1].name << " added to your cart.\n";
    }

    if (cart.empty()) {
        cout << "\nYour cart is empty. Thank you for visiting!\n";
    } else {
        cout << "\nReceipt:\n";
        cout << "-------------------------\n";
        double total = 0.0;
        for (const auto& item : cart) {
            cout << item.name << " - $" << fixed << setprecision(2) << item.price << "\n";
            total += item.price;
        }
        cout << "-------------------------\n";
        cout << "Total: $" << fixed << setprecision(2) << total << "\n";
        cout << "Thank you for your purchase!\n";
    }

    return 0;
}

