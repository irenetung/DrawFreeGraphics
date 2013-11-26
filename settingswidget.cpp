#include "settingswidget.h"

SettingsWidget::SettingsWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(255,153,204));
    this->setStyleSheet(tr("QPushButton{background-color:#FFCCE5; border-color:#FF3399; border-style:solid; border-width:3px; border-radius:3px;}"
                        "QPushButton:checked{background-color:#E5CCFF; border-color:#9933FF;}"
                        "QPushButton:hover{background-color:#FF99FF; border-color:#CC00CC;}"));
}

SettingsWidgetButtonSize::SettingsWidgetButtonSize()
{
    hLayout = new FlowLayout;

    bwn5Button = new QPushButton(tr("Width\n-5"));
    setButtonProperties(bwn5Button);
    bwp5Button = new QPushButton(tr("Width\n+5"));
    setButtonProperties(bwp5Button);
    bhn5Button = new QPushButton(tr("Height\n-5"));
    setButtonProperties(bhn5Button);
    bhp5Button = new QPushButton(tr("Height\n+5"));
    setButtonProperties(bhp5Button);

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToGroup(bwn5Button);
    addToGroup(bwp5Button);
    addToGroup(bhn5Button);
    addToGroup(bhp5Button);
}
