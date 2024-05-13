#ifndef UPGRADESWINDOW_H
#define UPGRADESWINDOW_H

#include <QMainWindow>

namespace Ui {
class UpgradesWindow;
}

class UpgradesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UpgradesWindow(QWidget *parent = nullptr);
    ~UpgradesWindow();
public slots:
    void receiveMoneyData(int money);

signals:
    void sendUpgrade(int, int);
    void sendMoneyData(int);

private slots:
    void vegetablesExpand();
    void vegetablesUpgrade();
    void fruitsExpand();
    void fruitsUpgrade();
    void berriesExpand();
    void berriesUpgrade();
    void contractUpgrade();

private:
    Ui::UpgradesWindow *ui;

    // Переменные
    int money = 0;
    int vegetablesExpandCost = 1000;
    int fruitsExpandCost = 3000;
    int berriesExpandCost = 5000;
    int vegetablesUpgradeCost = 4000;
    int fruitsUpgradeCost = 6000;
    int berriesUpgradeCost = 8000;
    int contractUpgradeCost = 15000;

    // Методы

    void updateData();

};

#endif // UPGRADESWINDOW_H
