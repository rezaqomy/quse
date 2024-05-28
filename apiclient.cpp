#include "apiclient.h"

ApiClient::ApiClient()
{

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

void ApiClient::sendRequest(const QString &path)
{
    QUrl url(path);
    getRequset(url);
}


void ApiClient::getRequestFinished()
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << reply->error();
    }
    QString result = reply->readAll();
    handelRequst(result);
}
