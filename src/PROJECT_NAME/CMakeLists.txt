# VV May extract to root (can we specifiy python and numpy separatly
find_package(
  Python3
  COMPONENTS Development.Module
  REQUIRED) # NumPy)
  
set(sources "")

set(<PROJECT_NAME>_<MODULE_NAME>_module "")

# Switching to Module (over shared) as A) Thats what Python3_add_library expects for
# Development.Module and it prevents one from trying to link to it which
# I think is the correct behavoir

add_library(<PROJECT_NAME>_<MODULE_NAME> MODULE ${sources})

target_sources(
  <PROJECT_NAME>_<MODULE_NAME>
  PUBLIC 
    FILE_SET HEADERS # # config_headers # < is that correct?
    TYPE HEADERS
    BASE_DIRS ${MODULE_ROOT}
    FILES "${MODULE_ROOT}/_<PROJECT_NAME>_config.h
           ${<PROJECT_NAME>_<MODULE_NAME>_module}")

target_include_directories(
  <PROJECT_NAME>_<MODULE_NAME> PUBLIC ${Python3_INCLUDE_DIRS}
                      # ${Python3_NumPy_INCLUDE_DIRS}
)

target_link_libraries(<PROJECT_NAME>_<MODULE_NAME> PRIVATE Python3::Module) # Python3::NumPy)

# target_compile_definitions(<PROJECT_NAME>_<MODULE_NAME> PRIVATE
# NPY_NO_DEPRECATED_API=NPY_1_7_API_VERSION)

set_python_extension_suffix(<PROJECT_NAME>_<MODULE_NAME>)


if(WIN32)
  target_compile_definitions(<PROJECT_NAME>_<MODULE_NAME> PRIVATE APEP_BUILD_DLL)
endif()

# Can we check if dll system explicitly? Other than checking original suffix
# Which would be hacky anyway!
if(WIN32)
  set_target_properties(<PROJECT_NAME>_<MODULE_NAME> PROPERTIES RUNTIME_OUTPUT_NAME "<MODULE_NAME>")
else()
  set_target_properties(<PROJECT_NAME>_<MODULE_NAME> PROPERTIES LIBRARY_OUTPUT_NAME "<MODULE_NAME>")
endif()
