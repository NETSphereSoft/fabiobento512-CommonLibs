/**
 * Copyright (C) 2017
 *
 * This library is distributed under the MIT License. See notice at the end
 * of this file.
 *
 * All code credit go to "Igor" from stackoverflow:
 * http://stackoverflow.com/a/21285323
 */

#include "customtreewidget.h"

CustomTreeWidget::CustomTreeWidget(QWidget *parent)
    : QTreeWidget(parent)
{
    setSelectionMode(QAbstractItemView::SingleSelection);
    setDragEnabled(true);
    viewport()->setAcceptDrops(true);
    setDropIndicatorShown(true);
    setDragDropMode(QAbstractItemView::InternalMove);
}

void CustomTreeWidget::dropEvent(QDropEvent * event)
{
    QModelIndex droppedIndex = indexAt(event->position().toPoint());

    if( !droppedIndex.isValid() )
        return;

    QTreeWidget::dropEvent(event);

    QTreeWidgetItem *itemMoved = itemAt(event->position().toPoint());

    // If the item was dropped in top level item (project), it is moved to the bottom
    if(itemMoved == this->topLevelItem(0)){
        itemMoved = this->topLevelItem(0)->child(this->topLevelItem(0)->childCount()-1);
    }

    // Set the item moved as currentItem
    setCurrentItem(itemMoved);

    // Signal that the item has changed
    itemChanged(itemAt(event->position().toPoint()),0);
}

/**
 * Copyright (c) 2017
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */
