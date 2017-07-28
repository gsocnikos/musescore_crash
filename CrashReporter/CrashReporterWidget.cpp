/****************************************************************************
**
** Copyright (C) 2007-2015 Speedovation
** Contact: Speedovation Lab (info@speedovation.com)
**
** KineticWing IDE CrashHandler
** http:// kineticwing.com
** This file is part of the core classes of the KiWi Editor (IDE)
**
** Author: Yash Bhardwaj
** License : Apache License 2.0
**
** All rights are reserved.
*/

#include "CrashReporterWidget.h"
#include "ui_CrashReporterWidget.h"

#include <QNetworkReply>
#include <QMessageBox>
#include <QProcess>
#include <QDesktopWidget>

#include "version.h"

CrashReporterWidget::CrashReporterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CrashReporterWidget),
    movie(":/animation/animation/350.GIF")
{
    ui->setupUi(this);

    ui->loader->clear();
    ui->info->clear();

    ui->loader->setMovie (&movie);
    movie.start ();

    ui->loader->hide();
    ui->btnClose->hide();

    setWindowTitle(VER_PRODUCTNAME_STR  " CrashReporter");

    // TODO in future we can do something about it
    // for now hide it
    //ui->btnCreateIssue->hide();


    //Move the dialog away from the center
    setGeometry(0,0,this->width(),this->height());
    int i = 0;
    if ( qApp->desktop()->screenCount() > 1 )
    {
        i = qApp->desktop()->screenNumber(this) ;
    }

    //Put the dialog in the screen center
    const QRect screen = qApp->desktop()->screenGeometry(i);
    move( screen.center() - rect().center() );

    setWindowFlags(Qt::WindowStaysOnTopHint);

}

CrashReporterWidget::~CrashReporterWidget()
{
    delete ui;
}

void CrashReporterWidget::setDmpPath(const QString& path)
{
    _dmpPath = path;
}

void CrashReporterWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

void CrashReporterWidget::on_btnSendReport_clicked()
{
    // trigger the request - see the examples in the following sections

    QString url_str = CRASHREPORTER_SUBMIT_URL;

    HttpRequestInput input(url_str, "POST");

    input.add_var( "build-id", BUILD_ID );
    input.add_var( "product-name", VER_PRODUCTNAME_STR );
    input.add_var( "version", VER_FILEVERSION_STR );


    input.add_var( "email", ui->email->text() );
    input.add_var( "desc", ui->desc->toPlainText() );


    input.add_file("dmp-file", _dmpPath, NULL, "binary/octet-stream");

    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_result(HttpRequestWorker*)));
    worker->execute(&input);

    ui->loader->show();
    ui->info->setText("Sending...");
    ui->btnSendReport->setEnabled(false);

}



void CrashReporterWidget::handle_result(HttpRequestWorker *worker) {
    QString msg;

    if (worker->error_type == QNetworkReply::NoError) {
        // communication was successful
        msg = "Success - Response: " + worker->response;

        ui->info->setText("Report submitted successfully");
        ui->btnSendReport->hide();
        ui->btnClose->show();

    }
    else {
        // an error occurred
        msg = "Error: " + worker->error_str + worker->response;

        ui->info->setText("Sending failed.");
        ui->btnSendReport->setEnabled(true);
    }

    ui->loader->hide();

    qDebug() << msg;
}

void CrashReporterWidget::on_btnCancel_clicked()
{
    qApp->quit();
}

void CrashReporterWidget::on_btnRestart_clicked()
{

    QProcess p;

#if defined(Q_OS_MAC) || defined(Q_OS_LINUX)
    p.startDetached("./KiWi");
#elif defined(Q_OS_WIN32)
    p.startDetached("KiWi.exe");
#endif

    qApp->quit();

}

void CrashReporterWidget::on_btnClose_clicked()
{
    qApp->quit();
}
