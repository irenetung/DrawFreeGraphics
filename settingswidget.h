#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include "basewidget.h"

class SettingsWidget : public BaseWidget
{
public:
    explicit SettingsWidget();
};

class SettingsWidgetButtonSize : public SettingsWidget
{
public:
    explicit SettingsWidgetButtonSize();
    QPushButton *bwn5Button;
    QPushButton *bwp5Button;
    QPushButton *bhn5Button;
    QPushButton *bhp5Button;
private:
};

#endif // SETTINGSWIDGET_H
