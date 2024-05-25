#include "question.h"

Question::Question()
{

}

Question::Question(QString &type, QString &difficulty, QString &category, QString &question, QString &correct_answer, QVector<QString> &incorrect_answers)
{
    setType(type);
    setDifficulty(difficulty);
    setCategory(category);
    setQuestion(question);
    setCorrectAnswer(correct_answer);
    setIncorrectAnswers(incorrect_answers);
}

QString Question::getType() const {
  return type;
}

QString Question::getDifficulty() const {
  return difficulty;
}

QString Question::getCategory() const {
  return category;
}

QString Question::getQuestion() const {
  return question;
}

QString Question::getCorrectAnswer() const {
  return correct_answer;
}

const QVector<QString>& Question::getIncorrectAnswers() const {
  return incorrect_answers;
}

void Question::setType(const QString& newType) {
  type = newType;
}

void Question::setDifficulty(const QString& newDifficulty) {
  difficulty = newDifficulty;
}

void Question::setCategory(const QString& newCategory) {
  category = newCategory;
}

void Question::setQuestion(const QString& newQuestion) {
  question = newQuestion;
}

void Question::setCorrectAnswer(const QString& newCorrectAnswer) {
  correct_answer = newCorrectAnswer;
}

void Question::setIncorrectAnswers(const QVector<QString>& newIncorrectAnswers) {
  incorrect_answers = newIncorrectAnswers;
}
