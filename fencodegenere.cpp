#include "fencodegenere.h"
#include <QVBoxLayout>
#include <QFont>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

FenCodeGenere::FenCodeGenere(QString code) : QDialog()
{
     QVBoxLayout *vbox = new QVBoxLayout(this);
     QHBoxLayout *hbox = new QHBoxLayout();

     vbox->addWidget(codegen);
     vbox->addLayout(hbox);

     hbox->addWidget(enregistre);
     hbox->addWidget(fermer);

     codegen->setText(code);
     codegen->setReadOnly(true);
     codegen->setFont(QFont("Courier"));

     connect(fermer, SIGNAL(clicked(bool)), this, SLOT(close()));
     connect(enregistre, SIGNAL(clicked(bool)), this, SLOT(enregistrer()));
}

void FenCodeGenere::enregistrer()
{
    QString chemin = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", "../ZeroClassGenerator");
    QFile *monfichier = new QFile(chemin);
    monfichier->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream flux(monfichier);
    flux << codegen->toPlainText();
    monfichier->close();
}
