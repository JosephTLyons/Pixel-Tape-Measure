/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Interface  : public Component
{
public:
    //==============================================================================
    Interface ();
    ~Interface() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    void setUpCustomCursor();
    void createEndPointDot(Graphics &g, const int &x, const int &y);
    void passPixelDistanceToLabel(const int &input);

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void mouseDown (const MouseEvent& e) override;
    void mouseDrag (const MouseEvent& e) override;
    void mouseUp (const MouseEvent& e) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    int pixelDistanceInt;
    String pixelDistanceText;
    Image cursorImage;
    Point<int> startingCoordinate;
    Point<int> currentCoordinate;


    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> pixelDistanceLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Interface)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

