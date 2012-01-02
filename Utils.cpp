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

#include "Utils.hpp"
#include <QFile>
#include <QString>
#include <QTextStream>
#include <iostream>

Json::Value readSettingsFor(const std::string objName)
{
    Json::Value dataRoot;

    //We need to convert the QT resource into a C++ String
    QFile file(QString(settingsPath.c_str()));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString document = in.readAll();

    //Convent the QString
    std::string documentAsString(document.toUtf8().constData());

    //Parse the document, given as an utf8 string.
    Json::Reader reader;

    bool parsingSuccessful = reader.parse(documentAsString, dataRoot);
    std::cout << dataRoot << std::endl;
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        std::cout << reader.getFormatedErrorMessages() << std::endl;
        throw SettingsParsingException();
    }

    Json::Value settingsForObj = dataRoot.get(objName, "ObjectNotFound");


    //If for the selected objects doesn't exist a settings line,
    //throws an exception.
    //BUGGY: it makes the code crash. CPP-JSON problem I guess.
    //std::string result = std::string(settingsForObj.asString());
    //std::string nomatch = std::string("ObjectNotFound");
    //if(!result.compare(nomatch))
    //    throw ObjectNotFoundInSettingsException(objName);

    return settingsForObj;
}
