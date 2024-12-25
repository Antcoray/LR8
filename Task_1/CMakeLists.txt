cmake_minimum_required(VERSION 3.22)
project(LR8)

add_executable(main Task_1.cpp CreatingNewStructArray.cpp utils.cpp mainmenu.cpp findStructs.cpp addstructs.cpp deleteOrChange.cpp quicksort.cpp)

#Address Sanitizer
#add_executable(AddressSan main.cpp Task_1.cpp Task_2.cpp Task_3.cpp Task_4.cpp Task_5.cpp)
#target_compile_options(AddressSan PRIVATE -fsanitize=address)
#target_link_options(AddressSan PRIVATE -fsanitize=address)

# Thread Sanitizer
#add_executable(ThreadSan main.cpp Task_1.cpp Task_2.cpp Task_3.cpp Task_4.cpp Task_5.cpp)
#target_compile_options(ThreadSan PRIVATE -fsanitize=thread)
#target_link_options(ThreadSan PRIVATE -fsanitize=thread)