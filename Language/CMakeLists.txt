add_library(creation_modeler_language_host STATIC
    AppLanguagePolicy.cpp
    AppLanguagePolicy.h
)

target_include_directories(creation_modeler_language_host PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

if(CREATION_MODELER_ENABLE_SCRIPTING)
    target_include_directories(creation_modeler_language_host PRIVATE "${CREATION_MODELER_LLVM_ROOT}/include")
    target_compile_definitions(creation_modeler_language_host PUBLIC CREATION_MODELER_ENABLE_SCRIPTING=1)
else()
    target_compile_definitions(creation_modeler_language_host PUBLIC CREATION_MODELER_ENABLE_SCRIPTING=0)
endif()

