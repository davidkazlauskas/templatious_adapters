
find_package(Qt4 COMPONENTS QTCORE REQUIRED)

if(Qt4)
    SET( UPP_CORE_LIB $ENV{UPP_CORE_LIB} )
    SET( UPP_INCLUDE_DIR $ENV{UPP_INCLUDE_DIR} )

    message( STATUS "Qt test suite is compiled.")
    include_directories( ${TEMPLATIOUS_DIR} ${UPP_INCLUDE_DIR} )
    find_package( ZLIB REQUIRED )
    SET( QTSOURCES UppTests.cpp )
    add_library( QtTests ${QTSOURCES} )
    target_link_libraries( QtTests ${UPP_CORE_LIB} ${ZLIB_LIBRARIES} )
else()
    message( STATUS "Qt test suite is NOT compiled.")
    add_definitions( -DNO_QT_TEST_SUITE )
    SET( QTSOURCES QtTests.cpp )
    add_library( QtTests ${QTSOURCES} )
endif()

