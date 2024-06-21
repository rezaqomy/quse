#ifndef APICLIENT_H
#define APICLIENT_H


#include "question.h"
#include <QtNetwork>
#include <QApplication>
#include <QString>
#include <QByteArray>

class ApiClient: public QObject
{
public:
    ApiClient();
    ~ApiClient();



public slots:
    void getRequestFinished() ;

private:
    QUrl getCategorys;
    QUrl getQuestions;
    QNetworkRequest* request;
    QNetworkAccessManager* manager;
    QNetworkReply* reply;
    void getRequset(QUrl& url);

protected:
    void virtual handelRequst(QString& data)=0;
    void sendRequest(const QString& path);

};

#endif // APICLIENT_H
