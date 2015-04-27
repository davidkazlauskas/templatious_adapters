
SET( UPP_INCLUDE_DIR $ENV{UPP_INCLUDE_DIR} )
SET( UPP_CORE_LIB $ENV{UPP_CORE_LIB} )

if(UPP_INCLUDE_DIR AND UPP_CORE_LIB)
    SET( UPP_CORE_LIB $ENV{UPP_CORE_LIB} )
    SET( UPP_INCLUDE_DIR $ENV{UPP_INCLUDE_DIR} )

    message( STATUS "Ultimate++ test suite is compiled.")
    include_directories( ${TEMPLATIOUS_DIR} ${UPP_INCLUDE_DIR} )
    find_package( ZLIB REQUIRED )
    SET( UPPSOURCES UppTests.cpp )
    add_library( UltimateppTests ${UPPSOURCES} )
    target_link_libraries( UltimateppTests ${UPP_CORE_LIB} ${ZLIB_LIBRARIES} )
else()
    message( STATUS "Ultimate++ test suite is NOT compiled.")
    add_definitions( -DNO_UPP_TEST_SUITE )
    SET( UPPSOURCES UppTests.cpp )
    add_library( UltimateppTests ${UPPSOURCES} )
endif()

