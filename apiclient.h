#ifndef APICLIENT_H
#define APICLIENT_H

#include <QtNetwork>
#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

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
    void sendRecuset(const QString& path);

};

#endif // APICLIENT_H
