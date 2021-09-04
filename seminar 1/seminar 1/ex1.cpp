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
    std::cout.unsetf(std::ios::dec);
    std::cout.setf(std::ios::hex);
    std::cout << "Price:...........";
    std::cout.width(8);
    std::cout << std::setfill('0') << price;
    std::cout << '\n' << "Has cash-back:";
    std::cout.setf(std::ios::boolalpha);
    std::cout.width(11);
    std::cout << std::setfill('.') << hasCashback;
    std::cout.unsetf(std::ios::hex);
    std::cout.setf(std::ios::dec);
    std::cout << '\n' << "Max temperature:......";
    std::cout.setf(std::ios::showpos);
    std::cout << temperature;
    std::cout << "\n\n";
    system("pause");

    return 0;
}
