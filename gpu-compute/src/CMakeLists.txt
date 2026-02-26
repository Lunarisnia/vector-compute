# collect all imgui files
# file(GLOB IMGUI_SOURCES vendor/imgui/*.cpp)

# Add the source files
add_executable(${PROJECT_NAME} 
	main.cpp 

	engine/engine.cpp
	engine/pandora/pandora.cpp
	engine/vma_usage.cpp
	engine/garbage_collector/garbage_collector.cpp
	engine/vk_toolkit/vk_toolkit.cpp

	engine/shaders/file_loader.cpp
	engine/shaders/file_path.cpp

	# core/shader/shader.cpp

	# Imgui
	# ${IMGUI_SOURCES}
	# vendor/imgui/backends/imgui_impl_vulkan.cpp
	# vendor/imgui/backends/imgui_impl_sdl2.cpp
	# vendor/imgui/misc/cpp/imgui_stdlib.cpp
)

# inlcude
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
# VMA include
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/vendor/vma)
# imgui include
# target_include_directories(${PROJECT_NAME} PUBLIC vendor/imgui)

# vulkan
find_package(Vulkan REQUIRED)

target_link_libraries(${PROJECT_NAME} ${Vulkan_LIBRARY})
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIR})

# Link to vendor
target_link_libraries(${PROJECT_NAME} vendor)

