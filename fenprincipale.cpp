#include "fenprincipale.h"
#include "fencodegenere.h"
#include <QVBoxLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QFormLayout>

FenPrincipale::FenPrincipale() : QWidget()
{
    QVBoxLayout *vboxprincipal = new QVBoxLayout(this);
    QFormLayout *vboxdefclass = new QFormLayout();
    QFormLayout *vboxoption = new QFormLayout();
    QFormLayout *vboxcom = new QFormLayout();
    QHBoxLayout *hbox = new QHBoxLayout();
    QGroupBox *grpboxdefclass = new QGroupBox("Définition de la classe");
    QGroupBox *grpboxoption = new QGroupBox("Options");
    QGroupBox *grpboxcom = new QGroupBox("Commentaires");

    auteur->setEnabled(false);
    date->setEnabled(false);
    role->setEnabled(false);

    vboxprincipal->addWidget(grpboxdefclass);
    vboxprincipal->addWidget(grpboxoption);
    vboxprincipal->addWidget(grpboxcom);
    vboxprincipal->addLayout(hbox);

    hbox->addWidget(genere);
    hbox->addWidget(quitter);

    vboxdefclass->addRow("&Nom:", name);
    vboxdefclass->addRow("Classe &mère:", classemere);

    vboxoption->addRow(protectheader);
    vboxoption->addRow(genconst);
    vboxoption->addRow(gendest);

    vboxcom->addRow(commentaire);
    vboxcom->addRow("&Auteur:", auteur);
    vboxcom->addRow("Da&te de création", date);
    vboxcom->addRow("&Role de la classe:", role);

    grpboxdefclass->setLayout(vboxdefclass);
    grpboxoption->setLayout(vboxoption);
    grpboxcom->setLayout(vboxcom);

    connect(commentaire, SIGNAL(clicked(bool)), auteur, SLOT(setEnabled(bool)));
    connect(commentaire, SIGNAL(clicked(bool)), date, SLOT(setEnabled(bool)));
    connect(commentaire, SIGNAL(clicked(bool)), role, SLOT(setEnabled(bool)));

    connect(quitter, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(genere, SIGNAL(clicked(bool)), this, SLOT(generer()));
}

void FenPrincipale::generer()
{
    QString code;
    if(commentaire->isChecked())
    {
        code.push_back("/*\nAuteur: " + auteur->text() + "\nDate de création: " + date->text() +"\n\nRole: " + role->toPlainText() + "\n*/\n\n");
    }
    if(protectheader->isChecked())
    {
        code.push_back("#ifndef HEADER_" + name->text() + "\n#define HEADER_" + name->text() + "\n\n");
    }
    code.push_back("class " + name->text());
    if(genere->isChecked())
    {
        code.push_back(" : public " + classemere->text());
    }
    code.push_back("\n{\n\tpublic:\n");
    if(genconst->isChecked())
    {
        code.push_back("\t\t" + name->text() + "();\n");
    }
    if(gendest->isChecked())
    {
        code.push_back("\t\t~" + name->text() + "();\n");
    }
    code.push_back("\n\tprotected:\n\n\tprivate:\n\n};");

    resultat = new FenCodeGenere(code);
    resultat->exec();

}
