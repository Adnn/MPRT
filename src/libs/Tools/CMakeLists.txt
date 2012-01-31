project(Tools)

# Configure (and thus copy) the template export file to the build dir
# The export file will be added to the project headers list (and installed with them)
configure_file(${CMAKE_SOURCE_DIR}/cmake/Export.h.in
        ${CMAKE_BINARY_DIR}/include/${PROJECT_NAME}_Export.h
        @ONLY)

set(${PROJECT_NAME}_HEADERS
	${CMAKE_BINARY_DIR}/include/${PROJECT_NAME}_Export.h
	AbstractVec3.h
	Image.h
	mprt.h
	OrthonormalBasis.h
	Rgb.h
	Sampler.h
	Vec2.h
	Vec3.h
)

set(${PROJECT_NAME}_SOURCES
	AbstractVec3.cpp
	Image.cpp
	OrthonormalBasis.cpp
	Rgb.cpp
	Sampler.cpp
	Vec2.cpp
	Vec3.cpp
)

add_library(${PROJECT_NAME}
	${${PROJECT_NAME}_SOURCES}
	${${PROJECT_NAME}_HEADERS}
)

include_directories(
)

target_link_libraries(${PROJECT_NAME}
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
