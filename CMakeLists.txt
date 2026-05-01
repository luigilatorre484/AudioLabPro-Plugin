cmake_minimum_required(VERSION 3.15)
project(AudioLabPro VERSION 1.0.0)

include(FetchContent)
FetchContent_Declare(juce URL https://github.com/juce-framework/JUCE/archive/refs/tags/7.0.5.zip)
FetchContent_MakeAvailable(juce)

# Creiamo il plugin forzando SOLO il formato VST3 e disabilitando i controlli VST2
juce_add_plugin(AudioLabPro
    COMPANY_NAME "LuigiLaTorre"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT TRUE
    FORMATS VST3 # Solo VST3, niente VST2 o Standalone per ora
    PRODUCT_NAME "AudioLabPro"
    COPY_PLUGIN_AFTER_BUILD FALSE)

# Carica l'immagine console.png
juce_add_binary_data(AudioLabAssets SOURCES console.png)

target_sources(AudioLabPro PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp)

# Colleghiamo le librerie necessarie inclusa la DSP per la FFT
target_link_libraries(AudioLabPro PRIVATE
    AudioLabAssets
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_gui_basics
    juce::juce_dsp)

# Questa riga dice a JUCE di ignorare completamente la mancanza dell'SDK VST2
target_compile_definitions(AudioLabPro PRIVATE JUCE_VST3_CAN_REPLACE_VST2=0)
