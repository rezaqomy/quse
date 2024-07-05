#include "getingqustions.h"

GetingQustions::GetingQustions()
{

}

GetingQustions::~GetingQustions()
{

}

void GetingQustions::getQuestion(int number, int category, QString difficaly){
    sendRequest(QUESTION_URL.arg(number).arg(category).arg(difficaly));
}

void GetingQustions::getRandomQuestion(QString difficaly)
{
    sendRequest(RANDOM_QUESTION_URL.arg(difficaly));
}

void GetingQustions::handelRequst(QString &data)
{
    QVector<Question*> questions;
    QJsonDocument json = QJsonDocument::fromJson(data.toUtf8());
    if (json["response_code"].toDouble() == 0){
        QJsonArray questionsJsons = json["results"].toArray();
        for (int i{}; i < questionsJsons.size(); i++){
            Question* question = jsonToQuestion(questionsJsons[i]);
            questions.push_back(question);
        }

    } else {
        qDebug() << json;
        /* TODO */
    }
    emit questionIsReady(questions);
}

Question* GetingQustions::jsonToQuestion(QJsonValueRef jsonValue)
{
    QJsonObject json = jsonValue.toObject();
    QString category = json["category"].toString();
    QByteArray decoded_data = QByteArray::fromBase64(category.toLocal8Bit());
    category = QString::fromUtf8(decoded_data);
    QString question = json["question"].toString();
    decoded_data = QByteArray::fromBase64(question.toLocal8Bit());
    question = QString::fromUtf8(decoded_data);
    QString type = json["type"].toString();
    decoded_data = QByteArray::fromBase64(type.toLocal8Bit());
    type = QString::fromUtf8(decoded_data);
    QString difficulty = json["difficulty"].toString();
    decoded_data = QByteArray::fromBase64(difficulty.toLocal8Bit());
    difficulty = QString::fromUtf8(decoded_data);
    QString answer = json["correct_answer"].toString();
    decoded_data = QByteArray::fromBase64(answer.toLocal8Bit());
    answer = QString::fromUtf8(decoded_data);
    QVector<QString> incorrectAnswerVector;
    auto data = json["incorrect_answers"].toArray();
    for (int i {}; i < data.size(); i++){
       decoded_data = QByteArray::fromBase64(data[i].toString().toLocal8Bit());
       QString dataS = QString::fromUtf8(decoded_data);
       incorrectAnswerVector.push_back(dataS);
    }
    Question* questions = new Question(type, difficulty, category, question, answer, incorrectAnswerVector);
    return questions;
}

