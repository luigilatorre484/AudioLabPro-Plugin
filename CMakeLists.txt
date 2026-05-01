cmake_minimum_required(VERSION 3.15)

project(AudioLabPro VERSION 0.0.1)

# Aggiunge i file della cartella Source
file(GLOB_RECURSE SourceFiles "Source/*.cpp" "Source/*.h")

add_executable(AudioLabPro ${SourceFiles})