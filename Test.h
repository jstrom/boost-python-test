

#ifndef Test_h
#define Test_h

#include <iostream>

class Test {
public:
    Test(): x(0){};
    ~Test(){};

    void setInt(int y){x = y;  std::cout << "set int to " <<y <<std::endl;}
    void printInt(){ std::cout << "The value of the int is " <<x <<std::endl; }

private:
    int x;

};
#endif


