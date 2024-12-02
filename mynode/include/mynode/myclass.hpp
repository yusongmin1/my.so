#ifndef MY_CLASS_HPP
#define MY_CLASS_HPP
#include<iostream>
class MYCLASS{
public:
    int a;
    int b;
    MYCLASS(int a,int b);
    ~MYCLASS();
    int MYCLASS_ADD();
};

void print_myclass()
{
    std::cout<<"我创建的.so文件输出东西了\n";
}
#endif //MY_CLASS_HPP

