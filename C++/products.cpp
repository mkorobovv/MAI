#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
#include<map>

using namespace std;
//enum class Type
//{
//    Milk = 1,
//   Bakery = 5,
//    Meat = 9,
//    Fish = 20,
//    Vegetabes = 51,
//    Fruits = 67
//};

struct Product
{
    int type;
    string ID;
    int price;
    string name;
    Product(string name, int price, int type, string ID) : name(name), price(price), type(type), ID(ID) {};
    
    string getName()
    {
        return name;
    }
    int getPrice()
    {
        return price;
    }
    int getType()
    {
        return type;
    }
    string getID()
    {
        return ID;
    }
};

struct Products
{
    vector<Product> products;
    void AddProduct(const Product& product)
    {
        products.push_back(product);
    }
    string getName(int position)
    {
        return products.at(position).getName();
    }
    int getPrice(int position)
    {
        return products.at(position).getPrice();
    }
    int getType(int position)
    {
        return products.at(position).getType();
    }
    string getID(int position)
    {
        return products.at(position).getID();;
    }
    int quantity()
    {
        return products.size();
    }
};

int main()
{
    map<string, int> type;
    bool flag  = true;
    Products prod;
    string nm, id;
    int pric, typ;
    do
    {
        cout << "Enter data about product(name, price, type, id): ";
        cin >> nm >> pric >> typ >> id;
        if (nm == "-" && pric == 0 && typ == 0 && id == "0") flag = false;
        else prod.AddProduct(Product(nm, pric, typ, id));
        
    } while (flag);

    cout << endl << endl << endl;

    for(int i = 0; i < prod.quantity(); i++)
    {
        cout << prod.products[i].getName() << " " << prod.products[i].getPrice() <<  " " << prod.products[i].getType() << " " << prod.products[i].getID() << endl;
    }
}