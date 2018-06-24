#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>

class CCustomButton : public QPushButton
{
    Q_OBJECT
public:
    CCustomButton(QWidget *parent = Q_NULLPTR);
    CCustomButton(const QString &text, QWidget *parent = Q_NULLPTR);
    CCustomButton(const QIcon &icon, const QString &text, QWidget *parent = Q_NULLPTR);


private:
    void setupButton();
};

#endif // CUSTOMBUTTON_H
