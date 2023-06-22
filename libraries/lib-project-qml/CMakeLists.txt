#[[
A library that attaches QML environment(QQmlApplicationEngine) to the Project
]]#

set( SOURCES
   ProjectQMLEnvironment.cpp
   ProjectQMLEnvironment.h
)

set( LIBRARIES
   lib-registries-interface
   lib-project-interface
   PUBLIC
      Qt6::Qml
)

audacity_library( lib-project-qml "${SOURCES}" "${LIBRARIES}"
   "" ""
)
