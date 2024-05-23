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
    ApiClient(const QString& path);
    ~ApiClient();


signals:
    void apiRecived(const QJsonDocument& json){}

public slots:
    void getRequestFinished() ;

private:
    QUrl getCategorys;
    QUrl getQuestions;
    QNetworkRequest* request;
    QNetworkAccessManager* manager;
    QNetworkReply* reply;
    void getRequset(QUrl& url);
    void handelRequst(QString& data);

};

#endif // APICLIENT_H
