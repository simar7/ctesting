cmake_minimum_required(VERSION 3.17)
project(ctesting C)
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)
#set_target_properties(${ctesting} PROPERTIES LINKER_LANGUAGE /MACHINE:X64)

add_compile_options("-S"
        "-D__BPF_TRACING__"
        "-D__KERNEL__"
        "-D__TARGET_ARCH_x86"
#        "-DCONFIG_64BIT"
#        "-D asm_inline"

        # working
        "-I/usr/include"
        "-include/lib/modules/5.8.0-38-generic/build/include/linux/kconfig.h"
        "-I/usr/include/x86_64-linux-gnu"
        "-I/usr/src/linux-headers-5.8.0-38-generic/include"
        "-I/usr/src/linux-headers-5.8.0-38-generic/include/generated"

        # not working
#        "-I3rdparty/include"
#        "-I3rdparty/libbpf"
#        "-Idist/include"
        "-I/usr/include/x86_64-linux-gnu/asm"
        "-I/lib/modules/5.8.0-38-generic/build/arch/x86/include"
        "-I/lib/modules/5.8.0-38-generic/build/arch/x86/include"
        "-I/lib/modules/5.8.0-38-generic/build/arch/x86/include/uapi"
        "-I/lib/modules/5.8.0-38-generic/build/arch/x86/include/generated"
        "-I/lib/modules/5.8.0-38-generic/build/arch/x86/include/generated/uapi"
        "-I/lib/modules/5.8.0-38-generic/build/include"
        "-I/lib/modules/5.8.0-38-generic/build/include"
        "-I/lib/modules/5.8.0-38-generic/build/include/uapi"
        "-I/lib/modules/5.8.0-38-generic/build/include/generated"
        "-I/lib/modules/5.8.0-38-generic/build/include/generated/uapi"


        "-Wno-address-of-packed-member"
        "-Wno-compare-distinct-pointer-types"
        "-Wno-deprecated-declarations"
        "-Wno-gnu-variable-sized-type-not-at-end"
        "-Wno-pointer-sign"
        "-Wno-pragma-once-outside-header"
        "-Wno-unknown-warning-option"
        "-Wno-unused-value"
        "-Wunused"
        "-Wall"
        "-fno-stack-protector"
        "-fno-jump-tables"
        "-fno-unwind-tables"
        "-fno-asynchronous-unwind-tables"
        "-xc"
        "-nostdinc"
        )

# Find kernel headers
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(KernelHeaders REQUIRED)
include_directories(${KERNELHEADERS_INCLUDE_DIRS})

include_directories(SYSTEM .)

# find MODULE_LICENSE("GPL"), MODULE_AUTHOR() etc.
# thanks to "merseyviking" from stack overflow
add_definitions(-D__KERNEL__ -DMODULE)


add_executable(ctesting
        tracee.bpf.c tracee.bpf.h test_tracee.bpf.c)

# CLion IDE will find symbols from <linux/*>
target_include_directories(ctesting PRIVATE ${KERNELHEADERS_INCLUDE_DIRS})
