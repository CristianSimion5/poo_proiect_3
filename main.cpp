#include <iostream>
#include <vector>
#include <string>
#include <complex>
#include <typeinfo>

#include "library.hpp"
#include "client.hpp"

using namespace std;

int main() {
    library L;
    client C;
    //L.addFromClient(C);
    //d->print(cout);
    L.showMenu();
    return 0;
    
}