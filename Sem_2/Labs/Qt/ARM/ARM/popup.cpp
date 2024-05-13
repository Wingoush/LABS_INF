#include "popup.h"
#include "ui_popup.h"

popup::popup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::popup)
{
    ui->setupUi(this);

    connect(ui->ConfirmBTN, &QPushButton::pressed, this, &popup::closePopup);
}
void popup::receiveEventData(QString eventName, QString eventDesc, QString eventEffects){
    ui->EventName->setText(eventName);
    ui->EventDescription->setText(eventDesc);
    ui->Effects->setText(eventEffects);
}
void popup::closePopup(){
    this->close();
}
popup::~popup()
{
    delete ui;
}
