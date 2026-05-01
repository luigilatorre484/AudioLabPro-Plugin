#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "BinaryData.h"

AudioLabProAudioProcessorEditor::AudioLabProAudioProcessorEditor (AudioLabProAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (1000, 600);
    // Se nel tuo header c'è un timer, dobbiamo avviarlo, altrimenti lascialo così
}

AudioLabProAudioProcessorEditor::~AudioLabProAudioProcessorEditor() {}

void AudioLabProAudioProcessorEditor::paint (juce::Graphics& g)
{
    auto backgroundImage = juce::ImageCache::getFromMemory (BinaryData::console_png, BinaryData::console_pngSize);
    if (backgroundImage.isValid())
        g.drawImageWithin (backgroundImage, 0, 0, getWidth(), getHeight(), juce::RectanglePlacement::fillDestination);
    else
        g.fillAll (juce::Colours::black);
}

void AudioLabProAudioProcessorEditor::resized() {}

// AGGIUNGI QUESTA PARTE QUI SOTTO:
void AudioLabProAudioProcessorEditor::timerCallback()
{
    // Per ora la lasciamo vuota, serve solo a far smettere di protestare il compilatore
    repaint();
}
