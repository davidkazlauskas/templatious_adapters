
find_package(Qt4 COMPONENTS QTCORE REQUIRED)

if(Qt4)
    message( STATUS "Qt test suite is compiled.")
    include_directories( ${TEMPLATIOUS_DIR} ${UPP_INCLUDE_DIR} )
    SET( QTSOURCES QtTests.cpp )
    add_library( QtTests ${QTSOURCES} )
    target_link_libraries( QtTests ${QT_QTCORE_LIBRARY} )
else()
    message( STATUS "Qt test suite is NOT compiled.")
    add_definitions( -DNO_QT_TEST_SUITE )
    SET( QTSOURCES QtTests.cpp )
    add_library( QtTests ${QTSOURCES} )
endif()

