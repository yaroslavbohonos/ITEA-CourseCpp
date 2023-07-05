/* Task in Replit(Compiler) - https://replit.com/@Bgns/Sites-bag-with-items-or-uniqueptr-OOP-72#main.cpp

Task: You have been assigned the task to fulfill an order for items in a shopping cart. Your classes should be named ShopItem and ShopOrder.
The ShopItem class should have the following attributes: an identifier, the name of the item, and its price.
The ShopOrder class should store the following information: the name of the item, the unit price of the item, and the quantity of ordered items.
The ShopItem class should provide accessor methods that allow you to retrieve and set all the aforementioned information.
The ShopOrder class should have a method to calculate and display the total cost of the order in a user-friendly format.
Objects of the ShopItem class can be stored in an array. You should utilize an approach for order management and total cost 
calculation that involves accessing objects and invoking methods using smart pointers.*/

#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <cstdlib>

class ShopItem
{
private:
  std::string good_name;
  int price, id;
  static int staticId;
  std::vector<int> prices{1000, 2000, 3000, 4000, 5000};
  std::vector<std::string> names{"TV", "Laptop", "Sweater", "Pants", "Jacket"};

public:
  ShopItem()
  {
    price = prices[rand() % 5];
    good_name = names[rand() % 5];
    id = staticId;
    staticId++;
  }

  int getItemPrice() const { return price; }
  const std::string& getItemName() const { return good_name; }
  int getItemId() const { return id; }

  void printInfo() const
  {
    std::cout << "Good's id: " << id << ", name: "
              << good_name << ", price: " << price << "\n";
  }
};

int ShopItem::staticId = 1;

class ShopOrder
{
private:
  int sum;
  static int amount;
  std::vector<std::unique_ptr<ShopItem>> bag;

public:
  void addItem(const ShopItem& item)
  {
    bag.push_back(std::make_unique<ShopItem>(item));
    amount++;
  }

  bool finishShopping()
  {
    if (bag.empty())
    {
      std::cout << "\nBag is empty";
    }
    else
    {
      sum = 0;
      for (const auto& item : bag)
        sum += item->getItemPrice();
      printInfo();
      bool temp;
      std::cout << "Do you want to purchase?\n1-yes\n0-no: ";
      std::cin >> temp;
      if (temp && !bag.empty())
      {
        std::cout << "Successful operation\n";
        return true;
      }
      std::cout << "Let's continue shopping\n\n";
      return false;
    }
    return false;
  }

  void printInfo() const
  {
    std::cout << "Overall price: " << sum << "$\n";
    std::cout << "Amount of Items: " << amount << "\n";
    if (amount <= 0)
      return;
    std::cout << "Items in bag: ";
    for (size_t i = 0; i < bag.size(); i++)
    {
      std::cout << bag[i]->getItemName();
      if (i != bag.size() - 1)
        std::cout << ", ";
    }
    std::cout << "\n";
  }
};

int ShopOrder::amount = 0;

void printInfo(const std::vector<ShopItem>& items)
{
  for (const auto& item : items)
    item.printInfo();
}

int main()
{
  srand(time(NULL));
  std::vector<ShopItem> items(4);
  std::unique_ptr<ShopOrder> order = std::make_unique<ShopOrder>();

  printInfo(items);
  char temp;
  int id, amount;
  while (true)
  {
    id = 0, amount = 0, temp = ' ';
    std::cout << "\nCommands:\n1 - Move goods in the bag";
    std::cout << "\n2 - Print items\n3 - Finish shopping\n4 - Exit";
    std::cout << "\n-> ";
    std::cin >> temp;

    if (temp == '1')
    {
      std::cout << "\nWrite the good's id: ";
      std::cin >> id;

      if (id < 1 || id - 1 >= items.size())
      {
        std::cout << "Error, try once again\n";
        continue;
      }

      std::cout << "\nWrite the amount: ";
      std::cin >> amount;

      for (int i = 0; i < amount; i++)
        order->addItem(items[id - 1]);

      continue;
    }

    if (temp == '2')
    {
      system("clear");
      printInfo(items);
      std::cout << std::endl;
      continue;
    }

    if (temp == '3')
    {
      if (order->finishShopping())
      {
        break;
      }
      continue;
    }
    else
    {
      break;
    }
  }
  return 0;
}
