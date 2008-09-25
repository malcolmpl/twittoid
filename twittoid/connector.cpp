#include "connector.h"
#include <QDebug>
#include <json/json.h>

TestBlipClass::TestBlipClass(QObject *parent /* = 0 */)
 : QObject(parent)
{
    httpGetId = 0;
    http = new QHttp();

    connect(http, SIGNAL(requestFinished(int, bool)), 
        this, SLOT(httpRequestFinished(int, bool)));
    connect(http, SIGNAL(responseHeaderReceived(const QHttpResponseHeader &)),
        this, SLOT(readResponseHeader(const QHttpResponseHeader &)));

    QHttpRequestHeader header("GET", "/statuses/all?limit=20");
    header.setValue("Host", "api.blip.pl");
    header.setValue("Accept", "application/json");
    header.setValue("X-Blip-api", "0.02");
    qDebug() << header.toString();

    http->setHost("api.blip.pl");
    httpGetId = http->request(header);
}

void TestBlipClass::httpRequestFinished(int requestId, bool error)
{
    if(httpGetId != requestId)
        return;

    if(error)
    {
        qDebug() << "Blad!";
        return;
    }

    qDebug() << "Finished";
    qDebug() << data.data();

    QByteArray ba = http->readAll();
    Json::Value root;
    Json::Reader reader;

    bool parsingSuccessful = reader.parse(QString(ba).toStdString(), root);
    if(!parsingSuccessful)
        goto clean;

    if(root.type() != Json::arrayValue)
        goto clean;

    qDebug() << "Wykryto tablice!";

    for(int i=0; i<root.size(); ++i)
    {
        if(!root.isValidIndex(i))
            goto clean;

        Json::Value val = root[i];

        if(val.type() != Json::objectValue)
            goto clean;

        qDebug() << "Wykryto objekt!";

        QString status = val["type"].asString().c_str();
        QString body = val.get("body", "").asString().c_str();
        QString dateCreated = val.get("created_at", "").asString().c_str();
        Json::Value valTransport = val["transport"];
        QString transportName = valTransport.get("name", "0").asString().c_str();
        QString transportId = QString("%1").arg(valTransport.get("id", 0).asInt());
        QString userPath = val.get("user_path", "").asString().c_str();
        QString id = QString("%1").arg(val.get("id", "0").asInt());

        qDebug() << i << " " << status << "\n" << "Date: " << dateCreated << "\n" << "Transport: " << transportName <<
            " id: " << transportId << "\nPath: " << userPath << " id: " << id << "\n" << "Tresc: " << body << "\n";
           
    }
/*
    qDebug() << "Parsing ok";

*/
clean:
    http->abort();
    qDebug() << "Koniec";
}

void TestBlipClass::readResponseHeader(const QHttpResponseHeader &header)
{
    switch (header.statusCode())
    {
     case 200:                   // Ok
         qDebug() << "200 OK";
         break;
     case 201:
         qDebug() << "201 Created";
         break;
     case 204:
         qDebug() << "204 No Content";
         break;
     case 301:                   // Moved Permanently
         qDebug() << "301 Moved Permanently";
         break;
     case 302:                   // Found
        qDebug() << "302 Found";
        break;
     case 303:                   // See Other
         qDebug() << "303 See Other";
         break;
     case 307:                   // Temporary Redirect
         qDebug() << "307 Temporary Redirect";
         break;
     case 400:
         qDebug() << "400 Bad Request";
         break;
     case 401:
         qDebug() << "401 Unauthorized";
         break;
     case 404:
         qDebug() << "404 Missing";
         break;
     case 422:
         qDebug() << "Unprocessable Entity";
         break;
     case 503:
         qDebug() << "Server Unavailable";
         break;

     default:
         qDebug() << "Download failed " << header.reasonPhrase();
         http->abort();
    }
}

#include "connector.moc"

