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

#include "GameDataManager.hpp"
#include <QFile>
#include <QString>
#include <QTextStream>
#include <iostream>


GameDataManager::GameDataManager()
{
    //Empty constructor.
}

/**
  * \brief Given a resource name, it opens it, read the content,
  * build a C++ String from it and parse these string with the
  * JSon Library
  * \param filename The resource name
  */
GameDataManager::GameDataManager(const std::string &filename)
    :filename_(filename)
{

    //We need to convert the QT resource into a C++ String
    QFile file(QString(filename.c_str()));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString document = in.readAll();

    //Convent the QString
    std::string documentAsString(document.toUtf8().constData());

    //Parse the document, given as an utf8 string.
    Json::Reader reader;

    bool parsingSuccessful = reader.parse(documentAsString, dataRoot_ );
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        std::cout << reader.getFormatedErrorMessages() << std::endl;
        return;
    }
}

GameDataManager::~GameDataManager()
{
    //TODO
}


GameDataManager& GameDataManager::operator=(const GameDataManager& rhs)
{
    if(this != &rhs)
    {
        dataRoot_.clear();
        filename_.clear();

        filename_ = rhs.filename_;
        dataRoot_ = rhs.dataRoot_;
    }

    return *this;
}


const Json::Value GameDataManager::operator[] (const std::string& key) const
{
    return dataRoot_.get(key, "ValueNotFound");
}
