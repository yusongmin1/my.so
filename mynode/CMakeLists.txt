cmake_minimum_required(VERSION 3.8)
project(mynode)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)



add_executable(mycpp src/mycpp.cpp)
target_include_directories(mycpp PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)#包含include目录

ament_target_dependencies(
  mycpp
  rclcpp
)#不可或缺添加

install(DIRECTORY include/
  DESTINATION include
)#把include文件夹复制到install目录

install(FILES
lib/libmyclass.so
DESTINATION lib
)#.so文件复制到安装目录

target_link_libraries(mycpp  ${CMAKE_CURRENT_SOURCE_DIR}/lib/libmyclass.so)#链接.so库文件

install(TARGETS mycpp
  DESTINATION lib/${PROJECT_NAME})



ament_package()
