/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "Interface.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Interface::Interface ()
{
    //[Constructor_pre] You can add your own custom stuff here..

    addMouseListener(this, true);
    setUpCursor();

    //[/Constructor_pre]

    addAndMakeVisible (pixelDistanceLabel = new Label ("pixelDistanceLabel",
                                                       String()));
    pixelDistanceLabel->setFont (Font (36.60f, Font::plain).withTypefaceStyle ("Regular"));
    pixelDistanceLabel->setJustificationType (Justification::centredLeft);
    pixelDistanceLabel->setEditable (false, false, false);
    pixelDistanceLabel->setColour (Label::backgroundColourId, Colour (0x00000000));
    pixelDistanceLabel->setColour (Label::textColourId, Colours::white);
    pixelDistanceLabel->setColour (TextEditor::textColourId, Colour (0x00000000));
    pixelDistanceLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (500, 500);


    //[Constructor] You can add your own custom stuff here..

    // Set up starting value and label
    passPixelDistanceToLabel(0);

    //[/Constructor]
}

Interface::~Interface()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    pixelDistanceLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Interface::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Interface::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    pixelDistanceLabel->setBounds (0, 0, proportionOfWidth (1.0000f), 40);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Interface::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...

    TooltipWindow tooltip(this, 600);
    
    Point<int> point(e.x, e.y);
    
    tooltip.displayTip(point, "Hi");
    
    passPixelDistanceToLabel(e.getDistanceFromDragStart());
    
    //Image graphicsImage(JPEGImageFormat, getWidth(), getHeight(), true);
    
    
    

//    Line<int> line;
//    tapeMeasureLine.drawLine(e.getMouseDownX(), e.getMouseDownY(), e.x, e.y);

    //[/UserCode_mouseDrag]
}

void Interface::mouseUp (const MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...

    passPixelDistanceToLabel(0);

    //[/UserCode_mouseUp]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void Interface::setUpCursor()
{
    // Load image from binary
    cursorImage = ImageFileFormat::loadFrom(BinaryData::Crosshair_Cursor_jpg,
                                            BinaryData::Crosshair_Cursor_jpgSize);
//
//    // Make a cursor with this image
//    MouseCursor cursorTemp(cursorImage, cursorImage.getWidth() / 2, cursorImage.getHeight() / 2);
//
//    setMouseCursor(cursorTemp);

    setMouseCursor(MouseCursor::CrosshairCursor);
}

void Interface::passPixelDistanceToLabel(const int &input)
{
    pixelDistanceInt = input;
    String tempString = "Pixel Distance: " + (String) pixelDistanceInt;
    pixelDistanceLabel->setText(tempString, dontSendNotification);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Interface" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="500" initialHeight="500">
  <METHODS>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
    <METHOD name="mouseUp (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="0"/>
  <LABEL name="pixelDistanceLabel" id="c34f3ff65f74d049" memberName="pixelDistanceLabel"
         virtualName="" explicitFocusOrder="0" pos="0 0 100% 40" bkgCol="0"
         textCol="ffffffff" edTextCol="0" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="36.600000000000001421" kerning="0" bold="0" italic="0"
         justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
