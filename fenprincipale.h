#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QPushButton>
#include <fencodegenere.h>

class FenPrincipale : public QWidget
{
    Q_OBJECT

public:
    FenPrincipale();

public slots:
    void generer();

private:
    QLineEdit *name = new QLineEdit();
    QLineEdit *classemere = new QLineEdit();
    QCheckBox *protectheader = new QCheckBox("Protéger le &header contre les inclusions multiples");
    QCheckBox *genconst = new QCheckBox("Générer un &constructeur par défaut");
    QCheckBox *gendest = new QCheckBox("Générer un &destructeur");
    QCheckBox *commentaire = new QCheckBox("A&jouter des commentaires");
    QLineEdit *auteur = new QLineEdit();
    QDateEdit *date = new QDateEdit();
    QTextEdit *role = new QTextEdit();
    QPushButton *genere = new QPushButton("Générer!");
    QPushButton *quitter = new QPushButton("Quitter");

    FenCodeGenere *resultat;

};

#endif // FENPRINCIPALE_H
