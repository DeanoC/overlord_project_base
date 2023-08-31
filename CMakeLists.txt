set(project bob)
project(${project} C CXX ASM)

file(GLOB LINKSCRIPT CONFIGURE_DEPENDS src/lscript.ld)
file(GLOB ASMFILES CONFIGURE_DEPENDS src/*.S)
file(GLOB HEADERLIST CONFIGURE_DEPENDS
		src/*.h
		src/${BOARD}/*.h
		src/${SOC}/*.h
		src/${CPU_ARCH}/*.h
		src/${CPU}/*.h )

file(GLOB CLIST CONFIGURE_DEPENDS
		src/*.c
		src/${BOARD}/*.c
		src/${SOC}/*.c
		src/${CPU_ARCH}/*.c
		src/${CPU}/*.c )

file(GLOB CPPLIST CONFIGURE_DEPENDS
		src/*.cpp
		src/${BOARD}/*.cpp
		src/${SOC}/*.cpp
		src/${CPU_ARCH}/*.cpp
		src/${CPU}/*.cpp )

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-M=${project}.map -T ${LINKSCRIPT}")

add_executable(${project} ${CLIST} ${CPPLIST} ${ASMFILES} ${HEADERLIST} ${LINKSCRIPT} ${PROJECT_EMBED_OBJ_FILES})
add_compile_definitions(${project} BOARD_${BOARD}=1 SOC_${SOC}=1 CPU_${CPU}=1 CPU_${CPU_ARCH}=1)
target_link_libraries(${project} PRIVATE core)
target_link_libraries(${project} PRIVATE dbg)
target_link_libraries(${project} PRIVATE utils)

target_link_libraries(${project} PRIVATE xilinx)