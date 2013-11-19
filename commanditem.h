#ifndef COMMANDITEM_H
#define COMMANDITEM_H

#include <QUndoCommand>
#include <QGraphicsItem>
#include <QGraphicsScene>

class CommandItem : public QObject, public QUndoCommand
{
    Q_OBJECT
public:
    explicit CommandItem(QGraphicsItem *item = 0,
                         QGraphicsScene *scene = 0);
    void undo() override;
    void redo() override;
signals:

public slots:

private:
    QGraphicsItem *command_item;
    QGraphicsScene *current_scene;

};

#endif // COMMANDITEM_H
