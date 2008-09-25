#include <QtCore>
#include <QApplication>
#include "connector.h"

int main( int argc, char ** argv )
{
    QApplication app(argc,argv);

    TestBlipClass *test = new TestBlipClass();

    return app.exec();
}
