#include "apiclient.h"

ApiClient::ApiClient(const QString& path)
{
    QUrl url(path);
    getRequset(url);
}

ApiClient::~ApiClient()
{
    delete manager;
    delete request;
    delete reply;
    manager = nullptr;
    request = nullptr;
    reply = nullptr;
}

void ApiClient::getRequset(QUrl &url)
{
    manager = new QNetworkAccessManager;
    request = new QNetworkRequest(url);
    reply = manager->get(*request);

    QObject::connect(reply, &QNetworkReply::finished, this, &ApiClient::getRequestFinished);
}

void ApiClient::handelRequst(QString &data)
{
    QJsonDocument json = QJsonDocument::fromJson(data.toUtf8());
    emit apiRecived(json);
    qDebug() << json;
}

void ApiClient::getRequestFinished()
{
    QString result = reply->readAll();
    handelRequst(result);
}
