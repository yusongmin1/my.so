#include "rclcpp/rclcpp.hpp"
#include "mylib/myclass.hpp"
int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    auto node_=std::make_shared<rclcpp::Node>("mynode");
    MYCLASS* myclass=new MYCLASS(1,1);
    print_myclass();
    while (rclcpp::ok())
    {
      std::cout<<"开始使用类了"<<myclass->MYCLASS_ADD()<<"\n";
      myclass->a++;
      sleep(1);
    }
    return 0;
    rclcpp::shutdown();
}

