Import("env")


arduino_core_defines = [
    
]

# A sebesség kulcsa: Ofast és a hardveres flag-ek
speed_flags = [
    # "-Ofast",           # <--- Ezt ne cseréld Os-re, ha sebesség kell!    
]

# C flags (LVGL fordításához)
env.Replace(CFLAGS=[
    "-std=gnu11"
] + speed_flags + arduino_core_defines)

# C++ flags (Arduino kódhoz)
env.Replace(CXXFLAGS=[
    "-std=gnu++14",
    "-fno-rtti",
    # "-x","c++",
    "-Wvla"
] + speed_flags + arduino_core_defines)

# Import("env")
# import os

# def add_lvgl_demos():
#     # végigmegyünk a LibraryDependencyGraph-on
#     for lib in env.GetLibBuilders():
#         if lib.name == "lvgl":
#             lvgl_path = lib.path
#             demos_path = os.path.join(lvgl_path, "demos")
#             lvgl_include = os.path.join(lvgl_path, "src")  # LVGL fő include

#             if os.path.isdir(demos_path):
#                 print("Adding LVGL demos from:", demos_path)

#                 # Itt a kulcs: include path a demos fordításához
#                 env.Append(CPPPATH=[lvgl_include])

#                 # Fordítási cél: külön build könyvtár
#                 env.BuildSources(
#                     os.path.join("$BUILD_DIR", "lvgl_demos"),
#                     demos_path
#                 )
#             else:
#                 print("LVGL demos folder not found!")

# add_lvgl_demos()