#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ComputerComponents {
  public:
  
    // Factory Method, note it's static
    static ComputerComponents *make_computercomponents(string choice);
  
    // method that we will use polymorphically per product
    virtual void io() = 0;
    
    // Note: need to specify an explicicit default destructor
    virtual ~ComputerComponents() = default;
};

class Cpu: public ComputerComponents {
  public:
    void io() {
        cout << "Cpu: Central Processing Unit\n";
    }
};

class Gpu: public ComputerComponents {
  public:
    void io() {
        cout << "Gpu: Graphics Processing Unit\n";
    }
};

class Motherboard: public ComputerComponents {
  public:
    void io() {
        cout << "Motherboard: Backbone of a computer\n";
    }
};

class Ram: public ComputerComponents {
  public:
    void io() {
        cout << "Ram: Random access memory(Short Term Memory)\n";
    }
};

class Storage: public ComputerComponents {
  public:
    void io() {
        cout << "Storage: Where the computer retains data\n";
    }
};

class Powersupply: public ComputerComponents {
  public:
    void io() {
        cout << "Power Supply: Backbone of a computer\n";
    }
};

class Case: public ComputerComponents {
  public:
    void io() {
        cout << "Case: Computer chassis, tower, system unit, or cabinet\n";
    }
};

class Core: public ComputerComponents {
  public:
    void io() {
        cout << "Core Components: There are seven core components to build a computer\n";
    }
};

// this is the FACTORY Method
// it does need to know about the derived methods
// but this allows us to abstract this from our 
// "client" calling code in main()
ComputerComponents *ComputerComponents::make_computercomponents(string choice) {
  if (choice ==  "Cpu")
    return new Cpu;
  else if (choice == "Gpu")
    return new Gpu;
  else if (choice == "Motherboard")
    return new Motherboard;
  else if (choice == "Gpu")
    return new Gpu;
  else if (choice == "Storage")
    return new Storage;
  else if (choice == "Powersupply")
    return new Powersupply;
  else if (choice == "Case")
    return new Case;
  else if (choice == "Ram")
    return new Ram;  
  else
    return new Core;
}


// main() is considered the "client"
// while in this example we could hard code the
// derived classes since we are making a menu anyway
// imagine having 

int main() {
  vector<ComputerComponents*> products;
  string choice;
  while (true) {
    cout << "Enter a Computer component you would like to know about (Core is defult) or 0 if done: ";
    cin >> choice;
    if (choice == "0") break;
    products.push_back(ComputerComponents::make_computercomponents(choice));
  }
  for (int i = 0; i < products.size(); i++) {
    products[i]->io();
  }
  for (int i = 0; i < products.size(); i++) {
    delete products[i];
  }
}