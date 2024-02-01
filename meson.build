project(
  'dev-tut',
  'c',
  'cpp',
  default_options: [
    'cpp_std=c++20',
    'prefix=' + meson.source_root() + '/'
    ],
  version: '0.0.1'
  )

cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')
host_system = host_machine.system()

# Dependencies


glfw_dep = dependency('glfw3', required: true)
gleq_dep = dependency('gleq', required: true)
glew_dep = dependency('glew', required: true)
fmt_dep = dependency('fmt', required: true)
glm_dep = dependency('glm', required: true)
imgui_dep = dependency('imgui', required: true) 

threads_dep = dependency('threads',   static : true)



if host_machine.system() == 'darwin'
    gl_dep = dependency('Metal', required: false) 
  elif host_machine.system() == 'windows'
    gl_dep = cc.find_library('opengl32', required: true)
else
   gl_dep = dependency('opengl', required: true)
endif
stb_dep = dependency('stb', required: true) 
subdir('src')
