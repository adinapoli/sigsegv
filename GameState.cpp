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
#include <sstream> //Needed for int ->

GameState::GameState(const GameObjId& id, int level)
    :GameObject(id), currentLevel_(level)
{
    std::stringstream levelStream;
    levelStream << level; //add level number to the stream

    //The input string to the method will be something like:
    // :/data/level1.json
    loadGameData(levelsPath + "level" + levelStream.str() + ".json");
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
  *\brief Load game data from a Data Manager.
  *\param dgm A GameDataManager
  */
void GameState::loadGameData(const std::string& resourceData)
{
    GameDataManager gdm(resourceData);
    currentManager_ = gdm;
}
