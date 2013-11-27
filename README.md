DRAW FREE APPLICATION README



AUTHORS:
Saam Aghevli, Hobey Kuhn, Pauline Low, Yi-Ling Tung, Girish Vinodkumar




DESCRIPTION:
This document contains information about checking out, building, running, and using the DrawFree Application contained in this package.



SETTING UP EXTERNAL DEVICES (Optional):
The program is catered for external devices including a joystick, a Makey-Makey (http://www.makeymakey.com), and a large, pressable button.  However, the application does not require these external devices to run.  

Installing the Joystick Driver - 
If you wish to use the joystick with this application, please install the joystick driver from the link below:

http://joytokey.net/en/

Then, configure the joystick to the driver using the application’s GUI.  To use the joystick with this application, disable the ability to click using the joystick buttons, and enable the ability to control the mouse.

Setting up the Makey-Makey and Button - 
If you wish to use the Makey-Makey and button interface for clicking, plug in the Makey-Makey via USB, and attach the Makey-Makey to the button such that a click of the button completes the circuit and simulates a computer click.



EXTERNAL SOFTWARE:
(Optional)
Development was done in Qt Creator (http://qt.digia.com).  To take full advantage of viewing our source code, we recommend you download this SDK to view file heirarchy, project files, resources files, etc. that are dependent on this environment.  An executable is included with the package so that you do not need Qt to run the application.




CHECKING OUT THE CODE:
The github repository containing the most recent version of the application can be checked out from this URL:

https://github.com/irenetung/DrawFreeGraphics.git

Clone this repository onto your computer to view the source code of this application.  Open the project file using Qt Creator, or view the source files using any other SDK/text viewer.  If you are using Qt, you have the option to build the project.  You can either run the code by building in this environment, or executing the executable files we have included in this package (the latter is recommended)




RUNNING THE APPLICATION:
To run the application, you can either build and run via Qt Creator, or execute the executable file included with this package (the latter is recommended).

The executable is called DrawFreeApplication.exe



INTERACTING WITH THE APPLICATION:
The DrawFree is an art application that allows the user to experiment with different brush effects, paint tools, stamps, and colors among an assortment of other things.  Explore the different options in the menu bar!  Below is a brief description of how to interact with each component of the application:

Settings - 
To adjust the size of the buttons, you can click on this tab and adjust accordingly.

New - 
This button will clear the canvas, and start a new document.  We currently have no method of saving your work yet.

Open - 
Under Construction.  The desired effect is to open saved works.  Currently, we can open images and place them as background on the canvas.

Save - 
Under Construction.  The desired effect is to save works.  Currently, we can save your work as a png file with a transparent background.

Undo - 
This button will allow you to undo the last edit made to the canvas.  Our application stores a history of edits to the canvas, so the undo button can be clicked for as many changes you have made to the document.

Cursor - 
This button will allow you to make edits to any items on your canvas.  Features include translating, scaling, stretching, rotating, shearing, changing depth, flipping, copying, and deleting.

Colors - 
This button will allow you to change the color of items added to the canvas (shapes, drawings, compatible stamps).  You can even set the background color!

Shapes - 
This button will allow you to draw various shapes onto the canvas.  The letters tool is still under development.

Stamps - 
This button will allow you to add pre-existing stamps to the canvas.  You can choose from a variety of categories.  Some stamps are small/are not licensed for commercial usage.  They are merely there for demo purposes.

Brush Effects - 
This button will allow you to draw on the canvas using different brush effects.  Click once to begin drawing and click again to end the drawing.  Real-Time drawing feedback is still under construction.  Resizing for optimal quality is still under construction.  Pencil tool is not implemented yet.

Insert Picture - 
This button will allow you to insert a picture onto the canvas.

Close - 
This button will close the application.

Hide Popup - 
This button will hide the sub-widget for the category selected.



CONTACT:
If you have any further questions, please contact one of the developers below:


Saam Aghevli - saghevli@umich.edu
Hobey Kuhn - hkuhn@umich.edu
Pauline Low - lpuiling@umich.edu
Yi-Ling Tung - yilingt@umich.edu
Girish Vinodkumar - girishvk@umich.edu





