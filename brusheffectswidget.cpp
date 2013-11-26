#include "brusheffectswidget.h"

BrushEffectsWidget::BrushEffectsWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(184,184,233));
    this->setStyleSheet(tr("QPushButton{background-color:#CCCCFF; border-color:#6666FF; border-style:solid; border-width:3px; border-radius:3px;}"
                        "QPushButton:checked{background-color:#E5CCFF; border-color:#9933FF;}"
                        "QPushButton:hover{background-color:#FF99FF; border-color:#CC00CC;}"));
}

BrushEffectsWidgetBrushEffects::BrushEffectsWidgetBrushEffects(QWidget *parent)
{
    brushSizeButton = new QPushButton(tr("Set\nBrush\nSize"));
    brushSizeButton->setStyleSheet(tr("QPushButton{background-color:#C0C0C0;}"));
    setButtonProperties(brushSizeButton);
    brushColorButton = new QPushButton(tr("Set\nBrush\nColor"));
    brushColorButton->setStyleSheet(tr("QPushButton{background-color:#C0C0C0;}"));
    setButtonProperties(brushColorButton);

    paintButton = new QPushButton(tr("Paint"));
    setButtonProperties(paintButton);
    waterColorButton = new QPushButton(tr("Water\ncolor"));
    setButtonProperties(waterColorButton);
    calligraphyButton = new QPushButton(tr("Calligraphy"));
    setButtonProperties(calligraphyButton);
    pencilButton = new QPushButton(tr("Pencil"));
    setButtonProperties(pencilButton);
    sprayPaintButton = new QPushButton(tr("Spray\nPaint"));
    setButtonProperties(sprayPaintButton);
    dustButton = new QPushButton(tr("Dust"));
    setButtonProperties(dustButton);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToButtonGroup(paintButton);
    addToButtonGroup(waterColorButton);
    addToButtonGroup(calligraphyButton);
    addToButtonGroup(pencilButton);
    addToButtonGroup(sprayPaintButton);
    addToButtonGroup(dustButton);

    buttonGroup->setExclusive(true);
}

BrushEffectsWidgetBrushSizes::BrushEffectsWidgetBrushSizes()
{
    currentSize = tr("The current brush size is: %1. Adjust the brush size. Or click a brush stroke on the canvas to change its brush size. Toggle the sign button to change the increments from positive to negative or vice versa.");

    backButton = new QPushButton(tr("< Brush\nEffects"));
    backButton->setStyleSheet(tr("QPushButton{background-color:#C0C0C0;}"));
    setButtonProperties(backButton);
    signButton = new QPushButton(tr("+"));
    signButton->setStyleSheet(tr("QPushButton{background-color:#C0C0C0;}"));
    setButtonProperties(signButton);

    si1Button = new QPushButton(tr("1"));
    setButtonProperties(si1Button);
    si5Button = new QPushButton(tr("5"));
    setButtonProperties(si5Button);
    si10Button = new QPushButton(tr("10"));
    setButtonProperties(si10Button);
    si20Button = new QPushButton(tr("20"));
    setButtonProperties(si20Button);
    si50Button = new QPushButton(tr("50"));
    setButtonProperties(si50Button);
    si100Button = new QPushButton(tr("100"));
    setButtonProperties(si100Button);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToGroup(si1Button);
    addToGroup(si5Button);
    addToGroup(si10Button);
    addToGroup(si20Button);
    addToGroup(si50Button);
    addToGroup(si100Button);
}
