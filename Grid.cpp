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


#include "Grid.hpp"
#include "json/json.h"
#include "GridCell.hpp"
#include <sstream>


Grid::Grid(const GameObjId& id)
    :GameObject(id)
{
    //TODO
}

Grid::~Grid()
{
    //TODO
}


void Grid::show(QGraphicsScene& scene)
{
    //Get only the graphics component
    std::vector<const GameComponent*> gc = getComponentsByFamilyID("graphics");

    //For each of them, convert to a GraphicsComponent and add to the scene.
    //Pre-condition: Every graphics object is addable to the scene.
    for(int i = 0; i < gc.size(); i++)
    {
        //I need to const_cast the component in order to display it
        GameComponent* nonConstComp = const_cast<GameComponent*>(gc[i]);
        scene.addItem(dynamic_cast<QGraphicsItem*>(nonConstComp));
    }
}

void update()
{
    //TODO
}

void Grid::load(const GameDataManager& gdm)
{
    //Read the map info, create grid objects but
    //don't render them.

    //First load the free cells.
    Json::Value mapCells = gdm["map"];
    Json::Value freeCells = mapCells.get("free", "ValueNotFound");

    for(int i = 0; i < freeCells.size(); i++)
    {
        int x = freeCells[i][0u].asInt();
        int y = freeCells[i][1u].asInt();

        //Use ssstream to obtain the cellname from int -> string conversion.
        std::stringstream cellNameStream;
        cellNameStream << x << y;
        std::string cellName(cellNameStream.str());
        componentsMap_[cellName] = new GridCell(GameCompId("cell" + cellName),
                                                x,y);
    }

    //TODO, enemies and objects cells.
}
