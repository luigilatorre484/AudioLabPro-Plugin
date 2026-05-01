#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class AudioLabProAudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Timer
{
public:
    AudioLabProAudioProcessorEditor (AudioLabProAudioProcessor&);
    ~AudioLabProAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void timerCallback() override;

private:
    AudioLabProAudioProcessor& audioProcessor;

    juce::Image backgroundImage;
    juce::TextButton analyzeButton;
    juce::TextButton bypassButton;
    juce::ComboBox genreSelector;
    
    // SLIDER ORIZZONTALI
    juce::Slider loudnessSlider;
    juce::Slider widthSlider;

    // MANOPOLE (QUELLE CHE MANCAVANO!)
    juce::Slider toneKnob;
    juce::Slider driveKnob;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioLabProAudioProcessorEditor)
};
