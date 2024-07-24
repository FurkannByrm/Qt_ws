#ifndef DIALOG_H
#define DIALOG_H

#include <QObject>
#include <QAction>
#include <QBoxLayout>
#include <QMenuBar>
#include <QGroupBox>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLayout>
#include <QScrollArea>

class Dialog : public QObject
{
    Q_OBJECT
public:
          Dialog();
private:
    void createMenu();
    void createHorizontalGroupBox();
    void createGridGroupBox();
    void createFormGroupBox();

    enum { NumGridRows = 3, NumButtons = 4 };

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    QGroupBox *gridGroupBox;
    QGroupBox *formGroupBox;
    QTextEdit *smallEditor;
    QTextEdit *bigEditor;
    QLabel *labels[NumGridRows];
    QLineEdit *lineEdits[NumGridRows];
    QPushButton *buttons[NumButtons];
    QDialogButtonBox *buttonBox;

    QMenu *fileMenu;
    QAction *exitAction;
};



#endif // DIALOG_H
