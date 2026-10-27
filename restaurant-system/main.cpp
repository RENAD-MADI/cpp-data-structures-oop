#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Food {
private:
    int ID;
    string name;
    int calories;
    double price;

public:
    int getID() const {
        return ID;
    }

    string getName() const {
        return name;
    }

    int getCalories() const {
        return calories;
    }

    double getPrice() const {
        return price;
    }

    void setID(int id) {
        ID = id;
    }

    void setName(const string& foodName) {
        name = foodName;
    }

    void setCalories(int foodCalories) {
        calories = foodCalories;
    }

    void setPrice(double foodPrice) {
        price = foodPrice;
    }
};

class Stock {
private:
    int ID;
    Food foodItem;
    int quantity;

public:
    int getID() const {
        return ID;
    }

    Food getFoodItem() const {
        return foodItem;
    }

    int getQuantity() const {
        return quantity;
    }

    void setID(int id) {
        ID = id;
    }

    void setFoodItem(const Food& item) {
        foodItem = item;
    }

    void setQuantity(int itemQuantity) {
        quantity = itemQuantity;
    }
};

class Customer {
private:
    int ID;
    string name;
    string phone;

public:
    int getID() const {
        return ID;
    }

    string getName() const {
        return name;
    }

    string getPhone() const {
        return phone;
    }

    void setID(int id) {
        ID = id;
    }

    void setName(const string& customerName) {
        name = customerName;
    }

    void setPhone(const string& customerPhone) {
        phone = customerPhone;
    }
};

class Menu {
private:
    int ID;
    string name;
    vector<Food> foodList;

public:
    int getID() const {
        return ID;
    }

    string getName() const {
        return name;
    }

    vector<Food> getFoodList() const {
        return foodList;
    }

    void setID(int id) {
        ID = id;
    }

    void setName(const string& menuName) {
        name = menuName;
    }

    void addFood(const Food& food) {
        foodList.push_back(food);
    }
};

class Branch {
private:
    int ID;
    string address;
    vector<Menu> menuList;
    vector<Stock> stockList;
    vector<Customer> customerList;

public:
    int getID() const {
        return ID;
    }

    string getAddress() const {
        return address;
    }

    vector<Menu> getMenuList() const {
        return menuList;
    }

    vector<Stock> getStockList() const {
        return stockList;
    }

    vector<Customer> getCustomerList() const {
        return customerList;
    }

    void setID(int id) {
        ID = id;
    }

    void setAddress(const string& branchAddress) {
        address = branchAddress;
    }

    void addMenu(const Menu& menu) {
        menuList.push_back(menu);
    }

    void addStock(const Stock& stock) {
        stockList.push_back(stock);
    }

    void addCustomer(const Customer& customer) {
        customerList.push_back(customer);
    }
};

int main() {
  
    vector<Food> foodList;
    vector<Stock> stockList;
    vector<Customer> customerList;
    vector<Menu> menuList;
    vector<Branch> branchList;

   
    Food food1;
    food1.setID(1);
    food1.setName("Burger");
    food1.setCalories(300);
    food1.setPrice(5.99);
    foodList.push_back(food1);

    Stock stock1;
    stock1.setID(1);
    stock1.setFoodItem(food1);
    stock1.setQuantity(10);
    stockList.push_back(stock1);

    Customer customer1;
    customer1.setID(1);
    customer1.setName("John Doe");
    customer1.setPhone("1234567890");
    customerList.push_back(customer1);

    Menu menu1;
    menu1.setID(1);
    menu1.setName("Lunch Menu");
    menu1.addFood(food1);
    menuList.push_back(menu1);

    Branch branch1;
    branch1.setID(1);
    branch1.setAddress("123 Main Street");
    branch1.addMenu(menu1);
    branch1.addStock(stock1);
    branch1.addCustomer(customer1);
    branchList.push_back(branch1);

    
    cout <<"Restaurant Information:" << endl;
    cout << "Branch ID: " << branchList[0].getID() << endl;
    cout << "Branch Address: " << branchList[0].getAddress() << endl;

    cout << "Menu Information:" << endl;
    vector<Menu> menus = branchList[0].getMenuList();
    for (const auto& menu : menus) {
        cout << "Menu ID: " << menu.getID() << endl;
        cout << "Menu Name: " << menu.getName() << endl;

        vector<Food> foods = menu.getFoodList();
        for (const auto& food : foods) {
            cout << "Food ID: " << food.getID() << endl;
            cout << "Food Name: " << food.getName() << endl;
            cout << "Food Calories: " << food.getCalories() << endl;
            cout << "Food Price: $" << food.getPrice() << endl;
        }
    }

    cout << "Stock Information:" << endl;
    vector<Stock> stocks = branchList[0].getStockList();
    for (const auto& stock : stocks) {
        cout << "Stock ID: " << stock.getID() << endl;
        cout << "Food ID: " << stock.getFoodItem().getID() << endl;
        cout << "Food Name: " << stock.getFoodItem().getName() << endl;
        cout << "Quantity: " << stock.getQuantity() << endl;
    }

    cout << "Customer Information:" << endl;
    vector<Customer> customers = branchList[0].getCustomerList();
    for (const auto& customer : customers) {
        cout << "Customer ID: " << customer.getID() << endl;
        cout << "Customer Name: " << customer.getName() << endl;
        cout << "Customer Phone: " << customer.getPhone() << endl;
    }

    return 0;
}