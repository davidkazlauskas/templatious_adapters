

if("${is_defined(UPP_INCLUDE_DIR)}" AND "${is_defined(UPP_CORE_LIB)}")
    SET( UPP_CORE_LIB
        "/home/deividas/Desktop/storage/Prj/upp/out/bazaar/Core/GCC4.Debug.Debug_Full.Noblitz.Shared.Sse2/Core.a")
        #"/home/deividas/Desktop/storage/Prj/upp/out/bazaar/Core/GCC4.Debug.Debug_Full.Noblitz.Shared.Sse2/Core.a")
    SET( UPP_INCLUDE_DIR
        "/usr/share/upp/uppsrc/" )
        #"/usr/share/upp/uppsrc/" )

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

