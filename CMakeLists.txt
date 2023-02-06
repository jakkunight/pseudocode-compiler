cmake_minimum_required(VERSION 3.10)
project(pseudocode_compiler)
set(CLASES
	
	)
set(LIBS
	)
foreach(clase ${CLASES})
	add_library(
		pseudocode_compiler STATIC
		${CMAKE_CURRENT_SOURCE_DIR}/headers/${clase}.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/headers/${clase}.cpp
	)
endforeach(clase ${CLASES})
add_executable(psc ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp)
foreach(clase ${CLASES})
	target_link_libraries(psc PUBLIC
	${clase}
	)
	target_include_directories(${clase} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers")
endforeach(clase ${CLASES})
