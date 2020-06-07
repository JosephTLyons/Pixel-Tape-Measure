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
    setUpCustomCursor();

    //[/Constructor_pre]

    pixelDistanceLabel.reset (new Label ("pixelDistanceLabel",
                                         String()));
    addAndMakeVisible (pixelDistanceLabel.get());
    pixelDistanceLabel->setFont (Font (36.60f, Font::plain).withTypefaceStyle ("Regular"));
    pixelDistanceLabel->setJustificationType (Justification::centredLeft);
    pixelDistanceLabel->setEditable (false, false, false);
    pixelDistanceLabel->setColour (Label::backgroundColourId, Colours::black);
    pixelDistanceLabel->setColour (Label::textColourId, Colours::white);
    pixelDistanceLabel->setColour (TextEditor::textColourId, Colour (0x00000000));
    pixelDistanceLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    pixelDistanceLabel->setBounds (0, 0, 320, 40);


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

    // Only draw dot and line if line exists (has some sort of length)
    if(startingCoordinate.getDistanceFrom(currentCoordinate) > 0)
    {
        g.setColour(Colours::red);
        createEndPointDot(g, startingCoordinate.getX(), startingCoordinate.getY());

        g.setColour(Colours::green);
        const int lineThickness = 3;
        g.drawLine(startingCoordinate.getX(), startingCoordinate.getY(),
                   currentCoordinate.getX(), currentCoordinate.getY(), lineThickness);

    }

    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Interface::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Interface::mouseDown (const MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...

    startingCoordinate.setXY(e.getMouseDownX(), e.getMouseDownY());

    //[/UserCode_mouseDown]
}

void Interface::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...

    passPixelDistanceToLabel(e.getDistanceFromDragStart());
    currentCoordinate.setXY(e.x, e.y);
    repaint();

    //[/UserCode_mouseDrag]
}

void Interface::mouseUp (const MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...

    passPixelDistanceToLabel(0);

    // Remove line by giving it length of zero
    startingCoordinate.setXY(0, 0);
    currentCoordinate.setXY(0, 0);
    repaint();

    //[/UserCode_mouseUp]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void Interface::createEndPointDot(Graphics &g, const int &x, const int &y)
{
    Rectangle<float> boundaryForStartingCircle(x - 4, y - 4, 8, 8);
    g.fillEllipse(boundaryForStartingCircle);
}

void Interface::setUpCustomCursor()
{
    // Load image from binary
    cursorImage = ImageFileFormat::loadFrom(BinaryData::Crosshair_Cursor_jpg, BinaryData::Crosshair_Cursor_jpgSize);

    // Make a cursor with this image
    MouseCursor cursorTemp(cursorImage, (cursorImage.getWidth() / 2) - 4, (cursorImage.getHeight() / 2) - 2);

    setMouseCursor(cursorTemp);
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
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ffffff"/>
  <LABEL name="pixelDistanceLabel" id="c34f3ff65f74d049" memberName="pixelDistanceLabel"
         virtualName="" explicitFocusOrder="0" pos="0 0 320 40" bkgCol="ff000000"
         textCol="ffffffff" edTextCol="0" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="36.6" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

