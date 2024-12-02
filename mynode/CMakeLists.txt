cmake_minimum_required(VERSION 3.8)
project(mynode)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(mylib REQUIRED)#包含生成的库文件


add_executable(mycpp src/mycpp.cpp)
target_include_directories(mycpp PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)#包含include目录

ament_target_dependencies(
  mycpp
  rclcpp
  mylib#包含生成的库文件
)#不可或缺添加

install(DIRECTORY include/
  DESTINATION include
)#把include文件夹复制到install目录


install(TARGETS mycpp
  DESTINATION lib/${PROJECT_NAME})



ament_package()
