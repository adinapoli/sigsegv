/*
 * Copyright (c) 2011, Alfredo Di Napoli
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the authors nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ALFREDO DI NAPOLI ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ALFREDO DI NAPOLI BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "GridCell.hpp"
#include <iostream>

GridCell::GridCell(int x, int y)
    :x_(x), y_(y)
{
    //NO-OP
}

GridCell::~GridCell()
{
    //NO-OP
}

void GridCell::update()
{
    //NO-OP
}

void GridCell::render()
{
    //NO-OP
}

QRectF GridCell::boundingRect() const
{
    return QRectF();
}

void GridCell::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->setPen(Qt::NoPen);

    //This simple math assure that you can position a cell
    //just like a real grid, for example (1,1) will be the
    //first row, first column.
    QPoint topLeft((x_ - 1) * CELL_SIDE + CELL_OFFSET * x_,
                   (y_ - 1) * CELL_SIDE + CELL_OFFSET * y_);
    QPoint bottomRight(topLeft.x() + CELL_SIDE,
                       topLeft.y() + CELL_SIDE);
    QRect rect(topLeft, bottomRight);
    painter->drawRect(rect);

    std::cout << "<" << topLeft.x() << "," << topLeft.y() << ">" << std::endl;
}
