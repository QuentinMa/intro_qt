#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QWidget>
#include <QObject>
#include <QTextEdit>
#include <QPushButton>
#include <QDialog>

class FenCodeGenere : public QDialog
{
    Q_OBJECT

public:
    FenCodeGenere(QString);

public slots:
    void enregistrer();

private:
    QTextEdit *codegen = new QTextEdit;
    QPushButton *fermer = new QPushButton("Fermer");
    QPushButton *enregistre = new QPushButton("Enregistrer");
};

#endif // FENCODEGENERE_H

