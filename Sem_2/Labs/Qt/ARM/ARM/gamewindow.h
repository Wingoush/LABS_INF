#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <upgradeswindow.h>
#include <popup.h>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

public slots:
    void receiveUpgrade(int itemType, int operation);
    void receiveMoneyData(int moneyData);
signals:
    void sendMoneyData(int);
    void sendEventData(QString, QString, QString);

private slots:
    void changeSellPercent();
    void updateDay();
    void sellVegetables();
    void sellFruits();
    void sellBerries();
    void openUpgrades();

private:
    Ui::MainWindow *ui;
    UpgradesWindow *uWindow;
    popup *eWindow;

    // РџРµСЂРµРјРµРЅРЅС‹Рµ
    int GameOver = 0;
    double DefectPercent = 0.4;
    int CurrentMoney = 0;
    int RentPay = 200;
    int RentTimer = 30;
    int Date[3] = {1, 1, 2000};
    double EventGainModifier = 1;
    double EventPriceModifier = 1;
    double EventDefectModifier = 1;

    // РњРµС‚РѕРґС‹
    void updateData();
    void Rent();
    void Drought();
    void Fertile();
    void Provider();
};

class Item{
public:
    int warehouseSize = 0;
    int warehouseLVL = 0;
    int stock = 0;
    int stockMax = 0;
    int gain = 0;
    double price = 0;
    double priceModifier = 1;
};

#endif // GAMEWINDOW_H
