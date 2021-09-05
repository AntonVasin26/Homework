#include<iostream>
#include <iomanip>

int main()
{
    std::string name;
    int price;
    int temperature;
    bool hasCashback;

    std::cout << "Product's name: ";
    std::cin >> name;

    std::cout << "Product's price: ";
    std::cin >> price;

    std::cout << "Is cash-back available for this product? (true/false) ";
    std::cin >> std::boolalpha >> hasCashback;

    std::cout << "Maximum storing temperature: ";
    std::cin >> temperature;

    std::cout << '\n' << "*************** OUTPUT ***************" << "\n\n";

    std::cout << name << '\n';

    std::cout << "Price:";
    std::cout << std::setfill('.') << std::setw(12) << '\0' << std::setfill('0') << std::setw(8) << std::hex << price;
    
    std::cout << '\n' << "Has cash-back:";
    std::cout << std::setfill('.') <<std::setw(11)<< std::boolalpha << hasCashback;
    
    std::cout << '\n' << "Max temperature:";
    std::cout.width(9);
    std::cout << std::setfill('.') << std::showpos << std::dec << temperature;
    std::cout << "\n\n";
    system("pause");

    return 0;
}
