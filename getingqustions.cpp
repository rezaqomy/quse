#include "getingqustions.h"

GetingQustions::GetingQustions()
{
    getQuestion(10, 15, "hard");
}

GetingQustions::~GetingQustions()
{

}

void GetingQustions::getQuestion(int number, int category, QString difficaly){
    sendRequest(QUESTION_URL.arg(number).arg(category).arg(difficaly));
}

void GetingQustions::handelRequst(QString &data)
{
    QVector<Question*> questions;
    QJsonDocument json = QJsonDocument::fromJson(data.toUtf8());
    if (json["response_code"].toDouble() == 0){
        QJsonArray questionsJsons = json["results"].toArray();
        for (int i{}; i < questionsJsons.size(); i++){
            Question* question = &jsonToQuestion(questionsJsons[i]);
            questions.push_back(question);
        }

    } else {
        /* TODO */
    }
    emit questionIsReady(questions);


}

Question& GetingQustions::jsonToQuestion(QJsonValueRef jsonValue)
{
    Question question;
    QJsonObject json = jsonValue.toObject();
    question.setCategory( json["category"].toString());
    question.setQuestion(json["question"].toString());
    question.setType(json["type"].toString());
    question.setDifficulty(json["difficulty"].toString());
    question.setCorrectAnswer(json["correct_answer"].toString());
    QVector<QString> incorrectAnswerVector;
    auto data = json["incorrect_answers"].toArray();
    for (int i {data.size()}; i > 0; i--){
       incorrectAnswerVector.push_back(data[i - 1].toString());
    }
    question.setIncorrectAnswers(incorrectAnswerVector);
    qDebug() <<
                question.getCategory() <<
                question.getCorrectAnswer() <<
                question.getDifficulty() <<
                question.getQuestion() <<
                question.getType() <<
                question.getIncorrectAnswers();
    return question;
}

