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

void GetingQustions::getRandomQuestion()
{
    sendRequest(RANDOM_QUESTION_URL);
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
    QString question = json["question"].toString();
    QString type = json["type"].toString();
    QString difficulty = json["difficulty"].toString();
    QString answer = json["correct_answer"].toString();
    QVector<QString> incorrectAnswerVector;
    auto data = json["incorrect_answers"].toArray();
    for (int i {}; i < data.size(); i++){
       incorrectAnswerVector.push_back(data[i].toString());
    }
    Question* questions = new Question(type, difficulty, category, question, answer, incorrectAnswerVector);
    return questions;
}

