project(MathematicTests)

set(${PROJECT_NAME}_HEADERS
)

set(${PROJECT_NAME}_SOURCES
)

add_executable(${PROJECT_NAME}
	main.cpp
	${${PROJECT_NAME}_SOURCES}
	${${PROJECT_NAME}_HEADERS}
)

include_directories(
)

target_link_libraries(${PROJECT_NAME}
	Tools
	Geometry
)

######################################################################
## Installation stuff - common to all projects
######################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
        VERSION "${VERSION}"
        SOVERSION "${SOVERSION}"
)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${RUNTIME_OUTPUT_DIRECTORY}
        LIBRARY DESTINATION ${LIBRARY_OUTPUT_DIRECTORY}
        ARCHIVE DESTINATION ${ARCHIVE_OUTPUT_DIRECTORY}
        PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
)
