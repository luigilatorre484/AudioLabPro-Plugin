cmake_minimum_required(VERSION 3.15)

# Aggiungiamo la versione qui (1.0.0)
project(AudioLabPro VERSION 1.0.0)

include(FetchContent)
FetchContent_Declare(juce URL https://github.com/juce-framework/JUCE/archive/refs/tags/7.0.5.zip)
FetchContent_MakeAvailable(juce)

juce_add_plugin(AudioLabPro
    COMPANY_NAME "LuigiLaTorre"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT TRUE
    FORMATS VST3
    PRODUCT_NAME "AudioLabPro")

target_sources(AudioLabPro PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp)

target_link_libraries(AudioLabPro PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_gui_basics)
