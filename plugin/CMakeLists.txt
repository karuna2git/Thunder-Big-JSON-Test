list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

project(TestPlugin)
find_package(WPEFramework REQUIRED)
find_package(${NAMESPACE}Core REQUIRED)
find_package(${NAMESPACE}Plugins REQUIRED)

set(MODULE_NAME ${NAMESPACE}TestPlugin)
include(CmakeHelperFunctions)

# Build the main plugin that runs inside the WPEFramework daemon
add_library(${MODULE_NAME} SHARED TestPlugin.cpp)

target_link_libraries(${MODULE_NAME}  PRIVATE
                      ${NAMESPACE}Core::${NAMESPACE}Core
                      ${NAMESPACE}Plugins::${NAMESPACE}Plugins)

set_target_properties(${MODULE_NAME} PROPERTIES
                      CXX_STANDARD 11
                      CXX_STANDARD_REQUIRED YES)

install(TARGETS ${MODULE_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/wpeframework/plugins)

write_config()
