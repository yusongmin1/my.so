#include "mylib/myclass.hpp"

int MYCLASS::MYCLASS_ADD() {
    return this->a + this->b;
}

MYCLASS::MYCLASS(int a, int b) {
    this->a = a;
    this->b = b;
}

MYCLASS::~MYCLASS() {
  std::cout<<"cnmcnmcnmcncmcnmccnm\n";
}

int main(int argc, char ** argv)
{
  (void) argc;
  (void) argv;

  ;
}
