#ifndef CONNECTOR_H_
#define CONNECTOR_H_

#include <QtCore>
#include <QtNetwork>

class TestBlipClass : public QObject
{
    Q_OBJECT
private:
    QHttp *http;
    int httpGetId;
    QByteArray data;

public:
    TestBlipClass(QObject *parent = 0);

public slots:
    void httpRequestFinished(int, bool);
    void readResponseHeader(const QHttpResponseHeader &);
};

#endif // CONNECTOR_H_