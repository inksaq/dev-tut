subdir('runtime')
#subdir('gl')
subdir('graphics')


dependencies = [
    fmt_dep, 
    threads_dep, 
    gl_dep,
    glm_dep,
    glfw_dep,
    gleq_dep,
    glew_dep,
    imgui_dep,
    stb_dep
]

lib_inc = include_directories('.','runtime','graphics')
dep_inc = include_directories('../')

sources = runtime_sources + graphics_sources

dev_lib = library(
    'core-framework', 
    dependencies :dependencies,
    include_directories: lib_inc,
    sources : sources
)

dev_dep = declare_dependency(
    link_with: dev_lib, 
    include_directories: dep_inc,
    dependencies: dependencies
)
