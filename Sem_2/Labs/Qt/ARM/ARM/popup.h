#ifndef POPUP_H
#define POPUP_H

#include <QMainWindow>

namespace Ui {
class popup;
}

class popup : public QMainWindow
{
    Q_OBJECT

public:
    explicit popup(QWidget *parent = nullptr);
    ~popup();
public slots:
    void receiveEventData(QString eventName, QString eventDesc, QString eventEffects);
    void closePopup();
private:
    Ui::popup *ui;
};

#endif // POPUP_H
