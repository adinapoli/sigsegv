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

#include "LevelDisplayer.hpp"
#include "Utils.hpp"


LevelDisplayer::LevelDisplayer(const GameCompId& id,
                               int levelNumber,
                               const std::string& levelName)
    :GraphicComponent(id), levelNumber_(levelNumber), levelName_(levelName)
{

    Json::Value settings = readSettingsFor(id_);
    Json::Value textColor = settings["textColor"];
    Json::Value textPosition = settings["textPosition"];

    std::string s("Level 1  - " + levelName_); //QQ
    QString plainText(s.c_str());
    setPlainText(plainText);
    setPos(textPosition[0u].asInt(),
           textPosition[1u].asInt());
    setDefaultTextColor(QColor(textColor[0u].asInt(),
                               textColor[1u].asInt(),
                               textColor[2u].asInt()));
}

LevelDisplayer::~LevelDisplayer()
{
    //TODO
}

void LevelDisplayer::update()
{
    //TODo
}

void LevelDisplayer:: render()
{
    //TODo
}
