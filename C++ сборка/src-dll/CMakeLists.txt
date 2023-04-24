set(targetDll "${MP2_LIBRARY}_dll") # create var target(project) dll name

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

# Create DLL target (project)
add_library(${targetDll} SHARED ${srcs} ${hdrs})
# Connect static lib polinome.lib
target_link_libraries(${targetDll} ${MP2_LIBRARY})
# name is different from target name therefore  we set a new one
set_target_properties(${targetDll} PROPERTIES OUTPUT_NAME ${MP2_LIBRARY})
# output directory for .lib
set_target_properties(${targetDll} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
# dll is used c style cdecl type
set_property(TARGET ${targetDll} PROPERTY LINKER_LANGUAGE C)
# for preprocess library library.h (MATH_DLL_EXPORTS is used by library.h)
target_compile_definitions(${targetDll} PRIVATE  MATH_DLL_EXPORTS)