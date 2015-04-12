

SET( ENV{UPP_INCLUDE_DIR}
     "/home/deividas/Desktop/storage/Prj/upp/out/bazaar/Core/GCC4.Debug.Debug_Full.Noblitz.Shared.Sse2/Core.a" )

SET( ENV{UPP_CORE_LIB}
     "/usr/share/upp/uppsrc/" )

if("${is_defined(UPP_INCLUDE_DIR)}" AND "${is_defined(UPP_CORE_LIB)}")
    SET( UPP_CORE_LIB ${UPP_CORE_LIB} )
    SET( UPP_INCLUDE_DIR ${UPP_INCLUDE_DIR} )

    message( STATUS "Ultimate++ test suite is compiled.")
    include_directories( ${UPP_INCLUDE_DIR} )
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

