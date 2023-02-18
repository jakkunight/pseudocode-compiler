cmake_minimum_required(VERSION 3.10)
project(pseudocode_compiler)

# LLVM:
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

# Libs and clases for the project:
set(CLASES
	
	)
set(LIBS
	)
set(EXT_LINK_DIRS
	
	)
foreach(clase ${CLASES})
	add_library(
		${clase} STATIC
		${CMAKE_CURRENT_SOURCE_DIR}/headers/${clase}.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/sources/${clase}.cpp
	)
endforeach(clase ${CLASES})
add_executable(psc ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp)

# LLVM:
# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

# Link against LLVM libraries
target_link_libraries(psc ${llvm_libs})

# Linking clases and libraries:
foreach(clase ${CLASES})
	target_link_libraries(psc
	${clase}
	)
	foreach(class ${CLASES})
		if(NOT ${clase} STREQUAL ${class})
			target_link_libraries(${clase}
				${class}
				)
		endif(NOT ${clase} STREQUAL ${class})
	endforeach(class ${CLASES})
endforeach(clase ${CLASES})
foreach(clase ${CLASES})
	target_include_directories(${clase} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers")
endforeach(clase ${CLASES})

