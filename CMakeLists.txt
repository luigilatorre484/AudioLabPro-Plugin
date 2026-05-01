cmake_minimum_required(VERSION 3.15)
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

# Questa riga collega l'immagine background.png al progetto
# Usa console.png invece di background.png
juce_add_binary_data(AudioLabAssets SOURCES console.png)

target_sources(AudioLabPro PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp)

# Qui aggiungiamo tutte le librerie necessarie, incluso il modulo DSP
target_link_libraries(AudioLabPro PRIVATE
    AudioLabAssets
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_gui_basics
    juce::juce_dsp)
