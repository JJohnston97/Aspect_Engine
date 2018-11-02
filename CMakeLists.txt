cmake_minimum_required(VERSION 2.6)
project(ASPECT)

include_directories(src Contrib)


if(MSVC)
  include_directories(
    Contrib/SDL2-2.0.8/include
    Contrib/glew-1.11.0/include
    Contrib/freeglut/include
	Contrib/openal-soft/include
	Contrib/ogg/include
	Contrib/vorbis/include
    
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/Contrib/SDL2-2.0.8/lib/x86
    ${CMAKE_SOURCE_DIR}/Contrib/glew-1.11.0/lib
    ${CMAKE_SOURCE_DIR}/Contrib/freeglut/lib
	${CMAKE_SOURCE_DIR}/Contrib/openal-soft/lib
	${CMAKE_SOURCE_DIR}/Contrib/ogg/lib
	${CMAKE_SOURCE_DIR}/Contrib/vorbis/lib
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(aspect
  src/Aspect/Program.cpp
  src/Aspect/Program.h
  src/Aspect/Entity.cpp
  src/Aspect/Entity.h
  src/Aspect/Component.h
  src/Aspect/Component.cpp
  src/Aspect/ShaderProgram.h
  src/Aspect/ShaderProgram.cpp
  src/Aspect/VertexArray.h
  src/Aspect/VertexArray.cpp
  src/Aspect/VertexBuffer.h
  src/Aspect/VertexBuffer.cpp
  src/Aspect/MeshRender.h
  src/Aspect/MeshRender.cpp
  src/Aspect/Audio.h
  src/Aspect/Audio.cpp
  src/Aspect/Material.cpp
  src/Aspect/Material.h
  Contrib/stb_image/stb_image.cpp
  src/Aspect/Transform.h
  src/Aspect/Transform.cpp
 

)

add_executable(game
  src/game/main.cpp
)

if(MSVC)
  target_link_libraries(aspect
    SDL2 glew32 opengl32 OpenAL32 ogg vorbis vorbisfile
  )

target_link_libraries(game aspect)

else()
  target_link_libraries(aspect
    SDL2 GLU GLEW GL AL ogg vorbis vorbisfile
  )
endif()


if(MSVC)
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/Contrib/SDL2-2.0.8/lib/x86/SDL2.dll"
      "$<TARGET_FILE_DIR:game>"
  )

  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/Contrib/glew-1.11.0/bin/Release/Win32/glew32.dll"
      "$<TARGET_FILE_DIR:game>"
  )
   
   add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/Contrib/openal-soft/bin/OpenAL32.dll"
      "$<TARGET_FILE_DIR:game>"
  )
endif()
