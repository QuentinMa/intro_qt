#include "mafenetre.h"

maFenetre::maFenetre() : QWidget()
{
    setFixedSize(230, 120);

    m_boutonDialogue = new QPushButton("Ouvrir la boîte de dialogue", this);
    m_boutonDialogue->move(40, 50);

    QObject::connect(m_boutonDialogue, SIGNAL(clicked()), this, SLOT(ouvrirDialogue()));
}

void maFenetre::ouvrirDialogue()
{
   reponse = QMessageBox::question(this, "Titre de la fenêtre", "Bonjour et bienvenue à <strong>tous les Zéros !</strong>");
   if(reponse == QMessageBox::Yes)
   {
        QMessageBox::information(this,"titre", "cool cool cool");
        QString pseudo = QInputDialog::getText(this, "Pseudo", "Quel est votre pseudo ?",QLineEdit::Normal, QString(), &ok);
        if(ok && pseudo.isEmpty())
            QMessageBox::critical(this, "erreur", "entre ton pseudo!");
        else if(ok && !pseudo.isEmpty())
            this->setWindowTitle("Salut " + pseudo);
   }
   else
   QMessageBox::critical(this, "titre", "ah non non non");
}
