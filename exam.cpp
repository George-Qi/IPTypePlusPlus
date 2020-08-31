#include "iptype.h"
#include <string>

int main(){
    IPv4Type ip1("192.168.0.1");
    IPv4Type ip2;
    ip2 = "255.255.255.123";


    cout << ip1 << " " << ip2 << endl;

    // IPType ip3 = ip2;



}