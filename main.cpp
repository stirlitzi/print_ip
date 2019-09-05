#include <iostream>
#include "printip.h"

using namespace std;

int main() {
    print_ip(char(-1));
    std::cout << "\n";
    print_ip(short(0));
    std::cout << "\n";
    print_ip(int(2130706433));
    std::cout << "\n";
    print_ip(long(8875824491850138409));
    std::cout << "\n";
    print_ip(string("123.45.67.89.101.112.131.41"));
    std::cout << "\n";
    vector<string> v{"this", "is", "vector"};
    print_ip(vector<string>(v));
    std::cout << "\n";
    std::list<char> l{'l', 'i', 's', 't'};
    print_ip(list<char>(l));
    std::cout << "\n";
    print_ip(std::make_tuple('t', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'u', 'p', 'l', 'e'));
    std::cout << endl;


    return 0;
}