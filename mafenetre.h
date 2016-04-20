#ifndef MAFENETRE
#define MAFENETRE

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>

class maFenetre : public QWidget
{
    Q_OBJECT

    public:
    maFenetre();

    public slots:
    void ouvrirDialogue();

    private:
    QPushButton *m_boutonDialogue;
    int reponse;
    QString pseudo;
    bool ok;
};

#endif
