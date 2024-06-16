find_package(WPEFramework REQUIRED)
find_package(WPEFrameworkCore REQUIRED)
find_package(WPEFrameworkWebSocket REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_executable(TestConsumer TestConsumer.cpp)

set_target_properties(TestConsumer PROPERTIES
                                   CXX_STANDARD 11
                                   CXX_STANDARD_REQUIRED YES)

target_link_libraries(TestConsumer PRIVATE
                                   ${NAMESPACE}Core::${NAMESPACE}Core
                                   ${NAMESPACE}WebSocket::${NAMESPACE}WebSocket)

install(TARGETS TestConsumer DESTINATION bin)
