
find_package(Qt4 COMPONENTS QTCORE)

SET( QTSOURCES
    QVectorTests.cpp
    QListTests.cpp
)

if(QT_QTCORE_INCLUDE_DIR AND QT_QTCORE_LIBRARY)
    message( STATUS "Qt test suite is compiled.")
    include_directories( ${TEMPLATIOUS_DIR} ${QT_INCLUDES} )
    add_library( QtTests ${QTSOURCES} )
    target_link_libraries( QtTests ${QT_QTCORE_LIBRARY} )
else()
    message( STATUS "Qt test suite is NOT compiled.")
    add_definitions( -DNO_QT_TEST_SUITE )
    add_library( QtTests ${QTSOURCES} )
endif()

