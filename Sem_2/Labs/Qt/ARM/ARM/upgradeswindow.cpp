#include "upgradeswindow.h"
#include "ui_upgradeswindow.h"

UpgradesWindow::UpgradesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UpgradesWindow)
{
    ui->setupUi(this);

    connect(ui->VegetablesBEUpgrade, &QPushButton::pressed, this, &UpgradesWindow::vegetablesExpand);
    connect(ui->VegetablesUpgrade, &QPushButton::pressed, this, &UpgradesWindow::vegetablesUpgrade);

    connect(ui->FruitsBEUpgrade, &QPushButton::pressed, this, &UpgradesWindow::fruitsExpand);
    connect(ui->FruitsUpgrade, &QPushButton::pressed, this, &UpgradesWindow::fruitsUpgrade);

    connect(ui->BerriesBEUpgrade, &QPushButton::pressed, this, &UpgradesWindow::berriesExpand);
    connect(ui->BerriesUpgrade, &QPushButton::pressed, this, &UpgradesWindow::berriesUpgrade);

    connect(ui->ContractUpgrade, &QPushButton::pressed, this, &UpgradesWindow::contractUpgrade);

    updateData();
}

// Приём количества средств
void UpgradesWindow::receiveMoneyData(int moneyData){
    money = moneyData;
}

// Улучшение складов (1-3: Расширение/Улучшение/Контракт, 1-3: Овощи/Фрукты/Ягоды)
void UpgradesWindow::vegetablesExpand(){
    if( money >= vegetablesExpandCost){ emit sendUpgrade(1,1); emit sendMoneyData(vegetablesExpandCost); vegetablesExpandCost*=1.3; updateData();}
}
void UpgradesWindow::fruitsExpand(){
    if( money >= fruitsExpandCost){ emit sendUpgrade(1,2); emit sendMoneyData(fruitsExpandCost); fruitsExpandCost*=1.3; updateData();}
}
void UpgradesWindow::berriesExpand(){
    if( money >= berriesExpandCost){ emit sendUpgrade(1,3); emit sendMoneyData(berriesExpandCost); berriesExpandCost*=1.3; updateData();}
}
void UpgradesWindow::vegetablesUpgrade(){
    if( money >= vegetablesUpgradeCost){ emit sendUpgrade(2,1); emit sendMoneyData(vegetablesUpgradeCost); vegetablesUpgradeCost*=1.4; updateData();}
}
void UpgradesWindow::fruitsUpgrade(){
    if( money >= fruitsUpgradeCost){ emit sendUpgrade(2,2); emit sendMoneyData(fruitsUpgradeCost); fruitsUpgradeCost*=1.4; updateData();}
}
void UpgradesWindow::berriesUpgrade(){
    if( money >= berriesUpgradeCost){ emit sendUpgrade(2,3); emit sendMoneyData(berriesUpgradeCost); berriesUpgradeCost*=1.4; updateData();}
}
void UpgradesWindow::contractUpgrade(){
    if( money >= contractUpgradeCost){ emit sendUpgrade(3,0); emit sendMoneyData(contractUpgradeCost); contractUpgradeCost*=1.5; updateData();}
}

void UpgradesWindow::updateData(){
    ui->VegetablesBEUpgrade->setText("Расширить склад\nовощей\n" + QString::number(vegetablesExpandCost) + '$');
    ui->FruitsBEUpgrade->setText("Расширить склад\nфруктов\n" + QString::number(fruitsExpandCost) + '$');
    ui->BerriesBEUpgrade->setText("Расширить склад\nягод\n" + QString::number(berriesExpandCost) + '$');

    ui->VegetablesUpgrade->setText("Улучшить склад\nовощей\n" + QString::number(vegetablesUpgradeCost) + '$');
    ui->FruitsUpgrade->setText("Улучшить склад\nфруктов\n" + QString::number(fruitsUpgradeCost) + '$');
    ui->BerriesUpgrade->setText("Улучшить склад\nягод\n" + QString::number(berriesUpgradeCost) + '$');

    ui->ContractUpgrade->setText("Сменить контракт на\nболее выгодный\n" + QString::number(contractUpgradeCost) + '$');
}

UpgradesWindow::~UpgradesWindow()
{
    delete ui;
}
