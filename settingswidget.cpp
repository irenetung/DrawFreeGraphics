#include "settingswidget.h"

SettingsWidget::SettingsWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(255,204,229));
}

SettingsWidgetButtonSize::SettingsWidgetButtonSize()
{
    hLayout = new FlowLayout;

    bwn5Button = new QPushButton("width\n-5");
    setButtonProperties(bwn5Button);
    bwp5Button = new QPushButton("width\n+5");
    setButtonProperties(bwp5Button);
    bhn5Button = new QPushButton("height\n-5");
    setButtonProperties(bhn5Button);
    bhp5Button = new QPushButton("height\n+5");
    setButtonProperties(bhp5Button);

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}
