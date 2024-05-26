#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QVector>

class Question
{
public:
    Question();
    Question(QString& type,
        QString& difficulty,
        QString& category,
        QString& question,
        QString& correct_answer,
        QVector<QString>& incorrect_answers
    );

    // Getters
    QString getType() const;
    QString getDifficulty() const;
    QString getCategory() const;
    QString getQuestion() const;
    QString getCorrectAnswer() const;
    const QVector<QString>& getIncorrectAnswers() const;

    // Setters
    void setType(const QString& newType);
    void setDifficulty(const QString& newDifficulty);
    void setCategory(const QString& newCategory);
    void setQuestion(const QString& newQuestion);
    void setCorrectAnswer(const QString& newCorrectAnswer);
    void setIncorrectAnswers(const QVector<QString>& newIncorrectAnswers);


private:
    QString type{};
    QString difficulty{};
    QString category{};
    QString question{};
    QString correct_answer{};
    QVector<QString> incorrect_answers{};
};

#endif // QUESTION_H
