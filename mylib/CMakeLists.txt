cmake_minimum_required(VERSION 3.8)
project(mylib)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)

add_library(myclass SHARED src/myclass.cpp)#生成.so文件
# add_executable(myclass src/myclass.cpp)
target_include_directories(myclass PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)#包含include目录
target_compile_features(myclass PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  myclass
  "rclcpp"
  "rclpy"
  "std_msgs"
)
install(DIRECTORY include/
  DESTINATION include
)#把include文件夹复制到install目录

install(TARGETS myclass
  DESTINATION lib)#把.so文件安装到安装目录

# # Export CMake configuration
# ament_export_include_directories(include)
# ament_export_libraries(myclass)

ament_package()
