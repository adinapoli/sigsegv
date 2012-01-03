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

#include "GameState.hpp"
#include "Utils.hpp"
#include <QString>
#include <sstream> //Needed for int -> string conversion.

GameState::GameState(const GameObjId& id, int level)
    :GameObject(id), currentLevel_(level)
{
    //Read configuration from settings.
    Json::Value settings = readSettingsFor(id_);

    //Get the coordinates for setting window and vieport size
    Json::Value upperLeft = settings["resolution"][0u];
    Json::Value bottomRight = settings["resolution"][1u];

    int ulX = upperLeft[0u].asInt();
    int ulY = upperLeft[1u].asInt();
    int brX = bottomRight[0u].asInt();
    int brY = bottomRight[1u].asInt();

    //Setup the scene
    scene_.setSceneRect(ulX,ulY,brX,brY);
    scene_.setItemIndexMethod(QGraphicsScene::NoIndex);

    //Setup the view
    std::string background = settings["background"].asString();

    view_.setScene(&scene_);
    view_.setRenderHint(QPainter::Antialiasing);
    view_.setBackgroundBrush(QPixmap(background.c_str()));
    view_.setCacheMode(QGraphicsView::CacheBackground);
    view_.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view_.setDragMode(QGraphicsView::ScrollHandDrag);

    std::string windowTitle = settings["windowTitle"].asString();
    view_.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, windowTitle.c_str()));
    view_.resize(brX, brY);


    //Bootstraps the grid
    std::stringstream levelStream;
    levelStream << level; //add level number to the stream

    //The input string to the method will be something like:
    // :/data/level1.json
    std::string resourcePath = levelsPath + "level" + levelStream.str() + ".json";
    loadGameData(resourcePath);

    //Create the grid
    grid_.load(currentManager_);


    //Create the HUD
    HUD hud(GameObjId("hud"), currentManager_);
    hud_ = hud;
}

GameState::~GameState()
{
    //TODO
}

void GameState::update()
{
    //TODO
}


/**
  *\brief Show the world, calling the display of the HUD, Grid and
  *       everything else. Probably it will be deprecated.
  */
void GameState::showWorld()
{
    //Show the grid
    grid_.show(scene_);
    hud_.show(scene_);
    view_.show();
}


/**
  *\brief Load game data from a Data Manager.
  *\param dgm A GameDataManager
  */
void GameState::loadGameData(const std::string& resourceData)
{
    GameDataManager gdm(resourceData);
    currentManager_ = gdm;
}
