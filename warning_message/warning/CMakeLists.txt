
find_package(PkgConfig)
pkg_check_modules(GLIB-2.0 glib-2.0)
pkg_check_modules(GIO-2.0 gio-2.0)

include_directories(
  ${Qt5Gui_PRIVATE_INCLUDE_DIRS}
  ${GLIB-2.0_INCLUDE_DIRS}
  ${GIO-2.0_INCLUDE_DIRS})

set(SOURCES
  warning.cpp)

qt5_add_resources(UI_RESOURCES resources.qrc)

add_executable(warning ${SOURCES} ${UI_RESOURCES})
qt5_use_modules(warning Qml Quick Gui)
TARGET_LINK_LIBRARIES(warning ${WRAPPER_STATIC_LIBRARIES} ${GLIB-2.0_LIBRARIES})

