#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "BinaryData.h" // <--- IMPORTANTE: Senza questo BinaryData non viene visto

//==============================================================================
AudioLabProAudioProcessorEditor::AudioLabProAudioProcessorEditor (AudioLabProAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (1000, 600);
}

AudioLabProAudioProcessorEditor::~AudioLabProAudioProcessorEditor()
{
}

//==============================================================================
void AudioLabProAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Carica l'immagine console.png
    auto backgroundImage = juce::ImageCache::getFromMemory (BinaryData::console_png, BinaryData::console_pngSize);
    
    if (backgroundImage.isValid())
    {
        g.drawImageWithin (backgroundImage, 0, 0, getWidth(), getHeight(), 
                           juce::RectanglePlacement::fillDestination);
    }
    else
    {
        g.fillAll (juce::Colours::black);
    }
}

void AudioLabProAudioProcessorEditor::resized()
{
}
