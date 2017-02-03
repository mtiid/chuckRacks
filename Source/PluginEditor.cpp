/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "CustomLookAndFeel.h"


//==============================================================================
ChuckRacksAudioProcessorEditor::ChuckRacksAudioProcessorEditor (ChuckRacksAudioProcessor* ownerFilter)
: AudioProcessorEditor (ownerFilter)
{
    LookAndFeel::setDefaultLookAndFeel(new CustomLookAndFeel());
    
    // This is where our plugin's editor size is set.
    setSize (600, 700);
    
    addAndMakeVisible(managerUI = new FileContainerManagerUI(getProcessor()->getFileContainerManagerModel()));
    managerUI->setBounds(0,40, getWidth(), getHeight()-40);
    managerUI->init();
    
    addAllShredsButton = new DrawableButton("Add All Shreds", DrawableButton::ButtonStyle::ImageFitted);
    
    ScopedPointer<XmlElement> addAllShredSVGUp(XmlDocument::parse(BinaryData::addshrediconUp_svg));
    ScopedPointer<XmlElement> addAllShredSVGDown(XmlDocument::parse(BinaryData::addshrediconDown_svg));
    
    addAllShredsButton->setImages(Drawable::createFromSVG(*addAllShredSVGUp),
                                  Drawable::createFromSVG(*addAllShredSVGUp),
                                  Drawable::createFromSVG(*addAllShredSVGDown));
    
    addAndMakeVisible(addAllShredsButton);
    addAllShredsButton->setBounds(2, 4, 32,32);
    addAllShredsButton->addListener(this);
    
    removeAllShredsButton = new DrawableButton("Remove All Shreds", DrawableButton::ButtonStyle::ImageFitted);
    
    ScopedPointer<XmlElement> removeAllShredSVGUp(XmlDocument::parse(BinaryData::removeAllShredUp_svg));
    ScopedPointer<XmlElement> removeAllShredSVGDown(XmlDocument::parse(BinaryData::removeAllShredDown_svg));
    
    removeAllShredsButton->setImages(Drawable::createFromSVG(*removeAllShredSVGUp),
                                     Drawable::createFromSVG(*removeAllShredSVGUp),
                                     Drawable::createFromSVG(*removeAllShredSVGDown));
    
    addAndMakeVisible(removeAllShredsButton);
    removeAllShredsButton->setBounds(40, 4, 32,32);
    removeAllShredsButton->addListener(this);
    
    addNewFileContainerButton = new DrawableButton("Add Code Editor", DrawableButton::ButtonStyle::ImageFitted);
    
    ScopedPointer<XmlElement> addFileContainerSVGUp(XmlDocument::parse(BinaryData::addcodeeditorUp_svg));
    ScopedPointer<XmlElement> addFileContainerSVGDown(XmlDocument::parse(BinaryData::addcodeeditorDown_svg));
    
    addNewFileContainerButton->setImages(Drawable::createFromSVG(*addFileContainerSVGUp),
                                         Drawable::createFromSVG(*addFileContainerSVGUp),
                                         Drawable::createFromSVG(*addFileContainerSVGDown));
    
    addAndMakeVisible(addNewFileContainerButton);
    addNewFileContainerButton->setBounds(78, 4, 32, 32);
    addNewFileContainerButton->addListener(this);
    
    
    openParameterListButton = new DrawableButton("Open Parameter List", DrawableButton::ButtonStyle::ImageFitted);
    
    ScopedPointer<XmlElement> openParameterListSVGRight(XmlDocument::parse(BinaryData::collapse_svg));
    ScopedPointer<XmlElement> openParameterListSVGLeft(XmlDocument::parse(BinaryData::open_svg));
    
    openParameterListButton->setClickingTogglesState(true);
    openParameterListButton->setToggleState(false, dontSendNotification);
    openParameterListButton->setImages(Drawable::createFromSVG(*openParameterListSVGRight),
                                        nullptr,
                                        Drawable::createFromSVG(*openParameterListSVGLeft),
                                        nullptr,
                                        Drawable::createFromSVG(*openParameterListSVGLeft),
                                        nullptr,
                                        Drawable::createFromSVG(*openParameterListSVGRight),
                                        nullptr);
    
    openParameterListButton->setColour(DrawableButton::backgroundOnColourId, Colour(0.0f,0.0f,0.0f,1.0f));
    openParameterListButton->setColour(DrawableButton::backgroundColourId, Colour(0.0f,0.0f,0.0f,1.0f));
    openParameterListButton->setBounds(566, 4, 32, 32);
    openParameterListButton->addListener(this);
    addAndMakeVisible(openParameterListButton);
    
    parameterUI = new ParameterMapUI(getProcessor());

    parameterUI->setBounds(getWidth()-370, 40, 370, getBottom()-40);
    addChildComponent(parameterUI);
    //addAndMakeVisible(parameterUI);
    
    startTimer(50);
    timerCallback();
}

ChuckRacksAudioProcessorEditor::~ChuckRacksAudioProcessorEditor()
{
}

//==============================================================================
void ChuckRacksAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colour(38, 40, 49));
    
    g.setColour(Colour(40, 43, 34));
   // g.drawRect(getLocalBounds(), 1);
}

void ChuckRacksAudioProcessorEditor::resized()
{
    
}

void ChuckRacksAudioProcessorEditor::buttonClicked(Button *buttonThatWasPressed)
{
    if (buttonThatWasPressed==addAllShredsButton)
    {
        DBG("Add all shreds button pressed");
        getProcessor()->getFileContainerManagerModel()->addAllShreds();
    }
    
    else if (buttonThatWasPressed==removeAllShredsButton)
    {
        getProcessor()->getFileContainerManagerModel()->removeAllShreds();
    }
    
    else if (buttonThatWasPressed==addNewFileContainerButton)
    {
        auto fc = getProcessor()->getFileContainerManagerModel()->addFileContainer();
        managerUI->addNewFileContainerUI(fc);
        //getProcessor()->updateParamNames();
        //managerUI->addNewFileContainerUI(getProcessor()->getFileContainerManagerModel()->fileContainerModels.back());
    }
    
    else if (buttonThatWasPressed == openParameterListButton){
        parameterUI->setVisible(openParameterListButton->getToggleState());
    }
        
    
    
    //if (buttonThatWasPressed==browseCodeButton) {
    //    getProcessor()->fileManager.openBrowser();
    //    lastFileLoaded=getProcessor()->fileManager.fileName;
    //}
}

void ChuckRacksAudioProcessorEditor::timerCallback()
{
    
}

void ChuckRacksAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    
}
