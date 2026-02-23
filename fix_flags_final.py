Import("env")

arduino_core_defines = [    
]

speed_flags = [     
]

# C flags 
env.Replace(CFLAGS=[
    "-std=gnu11"
] + speed_flags + arduino_core_defines)

# C++ flags 
env.Replace(CXXFLAGS=[
    "-std=gnu++14",
    "-fno-rtti",
    "-Wvla"
] + speed_flags + arduino_core_defines)

