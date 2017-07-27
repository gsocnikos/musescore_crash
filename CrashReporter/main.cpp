#include <QtCore/qdebug.h>
#include <QApplication>
#include <QWidget>
#include <QMessageBox>

#include "CrashReporterWidget.h"
#include "version.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    a.setOrganizationName(VER_COMPANYNAME_STR);
    a.setOrganizationDomain(VER_COMPANYDOMAIN_STR);
    a.setApplicationName(VER_FILEDESCRIPTION_STR);
    a.setApplicationVersion(VER_FILEVERSION_STR);

    CrashReporterWidget w;

    if ( a.arguments().size() != 2 )
    {
        qDebug() << "Invalid Startup Problem" << ".dmp file path is required as argument" ;
        //return 101;
     }


//    qDebug() << "Arg path" << a.arguments().first();

    //w.setDmpPath( a.arguments().first() );
    w.setDmpPath("c:/Users/nickhatz/86f16d5c-fe2e-46ca-93cb-bbcdff1cebe2.dmp" );

    w.show();


  return a.exec();

}


