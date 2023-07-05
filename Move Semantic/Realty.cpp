/* Task in Replit(Compiler) - https://replit.com/@Bgns/Ownership-or-Move-semantic-61#main.cpp

Create a class for property objects. Each object is characterized by a unique address pointer, a name, and a price.

Then create a class for owners. Each owner has a unique identifier (such as a tax code), a first name, a last name, an account with a balance, and a vector (list or other container) of pointers to property objects.

Develop methods for transferring ownership from one owner to another. In this case, the pointer to the property object should move from one owner to another, and the transfer of funds should also take place. In the main function, create a list of property objects with all attributes, including the price.

Create an initial list of owners who already own certain properties from the aforementioned list. Apply the methods to change the owner in such a way that one of them receives a new property object, and the other owner's account balance increases.*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class Realty {
protected:
    static std::vector<std::string> streets_numbers;
    static std::vector<std::string> streets;

    std::string realty;
    double cost;
    std::string address;

public:
    Realty(const std::string& name) : realty(name) {
        cost = (rand() % 10 + 1) * 500;
        address = streets_numbers[rand() % streets_numbers.size()] + " " + streets[rand() % streets.size()];
    }

    void setCost(double c) {
        cost = c;
    }

    double getCost() const {
        return cost;
    }

    const std::string& getName() const {
        return realty;
    }

    const std::string& getAddress() const {
        return address;
    }
};

std::vector<std::string> Realty::streets = { "Letsby Avenue", "Cavalier Approach", " Needless Alley", "Crutched Friars", "Whip-Ma-Whop-Ma-Gate" };
std::vector<std::string> Realty::streets_numbers = { "2", "77", "12", "55", "44" };

void PrintRealty(const std::vector<Realty*>& Realties) {
    if (Realties.empty()) {
        std::cout << "The person hasn't realty\n";
        return;
    }

    for (int i = 0; i < Realties.size(); i++) {
        std::cout << i + 1 << ". " << Realties[i]->getName() << " - " << Realties[i]->getCost() << "$,  " << Realties[i]->getAddress() << std::endl;
    }
}

class Customer {
protected:
    static int mainId;
    int id;
    double money;
    std::string name;
    std::vector<Realty*> properties;

public:
    Customer() : id(mainId++), money((rand() % 10 + 1) * 5000) {
        static std::vector<std::string> names = { "Andriy", "Alex", "Jake", "Hanna", "Kenny" };
        static std::vector<std::string> surnames = { "Heron", "Deffy", "Perk", "Franc", "Bush" };
        name = names[rand() % names.size()] + " " + surnames[rand() % surnames.size()];
    }

    void AddRealty(Realty* realty) {
        properties.push_back(realty);
    }

    void PrintInfo() const {
        std::cout << "\nName: " << name;
        std::cout << "\nMoney: " << money << "$";
        std::cout << "\nRealty:\n";
        PrintRealty(properties);
        std::cout << std::endl;
    }

    void Buy(Customer& seller, int r_id) {
        if (r_id < 0 || r_id >= seller.properties.size()) {
            std::cout << "Error, try once again\n";
            return;
        }

        Realty* property = seller.properties[r_id];
        if (money < property->getCost()) {
            std::cout << "Not enough money ;)\n";
            return;
        }

        money -= property->getCost();
        seller.money += property->getCost();
        properties.push_back(property);
        seller.properties.erase(seller.properties.begin() + r_id);
        std::cout << "Successful operation\n" << std::endl;
    }

    static int getMainId() {
        return mainId;
    }

    const std::vector<Realty*>& getProperties() const {
        return properties;
    }
};

int Customer::mainId = 1;

void PrintCustomers(const std::vector<Customer>& customers) {
    for (int i = 0; i < customers.size(); i++) {
        std::cout << "Person (id)#" << i + 1;
        customers[i].PrintInfo();
    }
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    std::vector<Customer> Customers(3);
    Realty* r1 = new Realty("Office");
    Customers[rand() % Customers.size()].AddRealty(r1);
    Realty* r2 = new Realty("Flat");
    Customers[rand() % Customers.size()].AddRealty(r2);
    Realty* r3 = new Realty("Mall");
    Customers[rand() % Customers.size()].AddRealty(r3);
    Realty* r4 = new Realty("House");
    Customers[rand() % Customers.size()].AddRealty(r4);
    Realty* r5 = new Realty("Land");
    Customers[rand() % Customers.size()].AddRealty(r5);

    char temp;
    int c_id, s_id, r_id;
    while (true) {
        c_id = 0, s_id = 0, r_id = 0, temp = ' ';
        std::cout << "\nCommands:\n1 - to buy something from the user";
        std::cout << "\n2 - to see all people\n3 - exit";
        std::cout << "\nEnter: ";
        std::cin >> temp;

        if (temp == '1') {
            std::cout << "\nWrite the buyer's id: ";
            std::cin >> c_id;
            std::cout << "Write the seller's id : ";
            std::cin >> s_id;
            std::cout << "Write the realty's id: ";
            std::cin >> r_id;

            if (c_id < 1 || c_id > Customers.size()) {
                std::cout << "Invalid buyer's id\n";
                continue;
            }

            if (s_id < 1 || s_id > Customers.size()) {
                std::cout << "Invalid seller's id\n";
                continue;
            }

            if (r_id < 1 || r_id > Customers[s_id - 1].getProperties().size()) {
                std::cout << "Invalid realty's id\n";
                continue;
            }

            Customers[c_id - 1].Buy(Customers[s_id - 1], r_id - 1);
            continue;
        }
        if (temp == '2') {
            std::cout << "\n";
            PrintCustomers(Customers);
            continue;
        }
        else {
            break;
        }
    }

    for (Customer& customer : Customers) {
        for (Realty* realty : customer.getProperties()) {
            delete realty;
        }
    }

    return 0;
}
