#include<iostream>

class A{
  //public:
  A(){
    std::cout<<"A def"<<std::endl;
  }
};

class B: public A {};

int main(){
  B x = B();

}
