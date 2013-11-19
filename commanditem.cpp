#include "commanditem.h"

CommandItem::CommandItem(QGraphicsItem *item,
                         QGraphicsScene *scene) : QObject(0), QUndoCommand(0),
    command_item(item), current_scene(scene)
{
}

void CommandItem::undo() {
    current_scene->removeItem(command_item);
}

void CommandItem::redo() {
    current_scene->addItem(command_item);
}
