#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QRandomGenerator>

// Создание экземпляров класса товара
Item vegetables;
Item fruits;
Item berries;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Инициализация окна улучшений и событий
    uWindow = new UpgradesWindow();
    eWindow = new popup();

    // Задание начального уровня и размера склада овощей
    vegetables.warehouseSize = 1;
    vegetables.warehouseLVL = 1;

    // Подключение слайдера к тексту % для продажи
    connect(ui->SellSlider, &QSlider::valueChanged, this, &MainWindow::changeSellPercent);

    // Продажа овощей
    connect(ui->SellVegetables, &QPushButton::pressed, this, &MainWindow::sellVegetables);
    // Продажа фркутов
    connect(ui->SellFruits, &QPushButton::pressed, this, &MainWindow::sellFruits);
    // Продажа ягод
    connect(ui->SellBerries, &QPushButton::pressed, this, &MainWindow::sellBerries);

    // Создание, подключение и активация таймера смены дня
    QTimer *DayTimer = new QTimer(this);
    connect(DayTimer, &QTimer::timeout, this, &MainWindow::updateDay);
    DayTimer->start(1000);

    // Подключение кнопки к открытию улучшений
    connect(ui->UpgradesBtn, &QPushButton::pressed, this, &MainWindow::openUpgrades);

    // Подключение сигналов передачи информации между окнами
    connect(uWindow, &UpgradesWindow::sendUpgrade, this, &MainWindow::receiveUpgrade);
    connect(uWindow, &UpgradesWindow::sendMoneyData, this, &MainWindow::receiveMoneyData);
    connect(this, &MainWindow::sendMoneyData, uWindow, &UpgradesWindow::receiveMoneyData);
    connect(this, &MainWindow::sendEventData, eWindow, &popup::receiveEventData);

    // Изначальный вызов обновления данных
    updateData();
}

// Обновление данных
void MainWindow::updateData(){
    // Обновление отображения количества товаров
    ui->Vegetables->setText(QString::number(vegetables.stock) + '/' + QString::number(vegetables.stockMax));
    ui->Fruits->setText(QString::number(fruits.stock) + '/' + QString::number(fruits.stockMax));
    ui->Berries->setText(QString::number(berries.stock) + '/' + QString::number(berries.stockMax));

    // Обновление отображения прироста
    ui->VegetablesDay->setText(QString::number(vegetables.gain));
    ui->FruitsDay->setText(QString::number(fruits.gain));
    ui->BerriesDay->setText(QString::number(berries.gain));

    // Обновление отображения цены
    ui->VegetablesPrice->setText(QString::number(round(vegetables.price*100)/100));
    ui->FruitsPrice->setText(QString::number(round(fruits.price*100)/100));
    ui->BerriesPrice->setText(QString::number(round(berries.price*100)/100));

    // Обновление процента брака
    ui->DefectPercent->setText(QString::number(round(DefectPercent * EventDefectModifier * 100*100)/100) + '%');

    // Обновление денег и следующего платежа
    ui->Money->setText(QString::number(CurrentMoney));
    ui->Rent->setText(QString::number(RentPay));

    // Обновление отображения даты
    QString dayString = QString::number(Date[0]);
    QString monthString = QString::number(Date[1]);
    QString yearString = QString::number(Date[2]);
    QString dateString = (Date[0] < 10 ? '0'+dayString : dayString) + '.' + (Date[1] < 10 ? '0'+monthString : monthString) + '.' +yearString;
    ui->Date->setText(dateString);

    // Обновление данных лимитов и прироста
    vegetables.stockMax = vegetables.warehouseSize * 1000;
    vegetables.gain = (vegetables.warehouseSize + vegetables.warehouseLVL * 2) * 20 * EventGainModifier;
    vegetables.priceModifier = 1 * pow(1.2, vegetables.warehouseLVL) * EventPriceModifier;

    fruits.stockMax = fruits.warehouseSize * 1000;
    fruits.gain = (fruits.warehouseSize + fruits.warehouseLVL * 2) * 20 * EventGainModifier;
    fruits.priceModifier = 1 * pow(1.2, fruits.warehouseLVL) * EventPriceModifier;

    berries.stockMax = berries.warehouseSize * 1000;
    berries.gain = (berries.warehouseSize + berries.warehouseLVL * 2) * 20 * EventGainModifier;
    berries.priceModifier = 1 * pow(1.2, berries.warehouseLVL) * EventPriceModifier;

    // Отправление данных о средствах в окно улучшений
    emit sendMoneyData(CurrentMoney);
}

// Смена дня
void MainWindow::updateDay(){
    if (GameOver == 1){return;}
    // Прирост овощей
    vegetables.stock + vegetables.gain*EventGainModifier*(1.0-DefectPercent*EventGainModifier) < vegetables.stockMax ? vegetables.stock += vegetables.gain*EventGainModifier*(1.0-DefectPercent*EventGainModifier*EventDefectModifier) : vegetables.stock+=(vegetables.stockMax - vegetables.stock);

    // Прирост фруктов
    fruits.stock + fruits.gain*EventGainModifier*(1.0-DefectPercent*EventGainModifier) < fruits.stockMax ? fruits.stock += fruits.gain*EventGainModifier*(1.0-DefectPercent*EventGainModifier*EventDefectModifier) : fruits.stock+=(fruits.stockMax - fruits.stock);

    // Прирост ягод
    berries.stock + berries.gain*EventGainModifier*(1.0-DefectPercent*EventGainModifier) < berries.stockMax ? berries.stock += berries.gain*EventGainModifier*(1.0-DefectPercent*EventGainModifier*EventDefectModifier) : berries.stock+=(berries.stockMax - berries.stock);

    // Обновление даты
    if(Date[1] == 2){
        Date[0] < 28 ? Date[0]++ : (Date[0] = 1, (Date[1] < 12 ? Date[1]++ : (Date[1] = 1, Date[2]++)));
    } else if(Date[1]%2 == 0){
        Date[0] < 30? Date[0]++ : (Date[0] = 1, (Date[1] < 12 ? Date[1]++ : (Date[1] = 1, Date[2]++)));
    }else{
        Date[0] < 31? Date[0]++ : (Date[0] = 1, (Date[1] < 12 ? Date[1]++ : (Date[1] = 1, Date[2]++)));
    }

    // Обновление цен
    vegetables.price = (75 + QRandomGenerator::global()->bounded(75)) * vegetables.priceModifier * EventPriceModifier / 100.0;
    fruits.price = (175 + QRandomGenerator::global()->bounded(75)) * fruits.priceModifier * EventPriceModifier / 100.0;
    berries.price = (275 + QRandomGenerator::global()->bounded(75)) * berries.priceModifier * EventPriceModifier / 100.0;

    // Аренда и события
    if(RentTimer>1){
        RentTimer--;
    }else{
        if(RentPay > CurrentMoney){ Rent(); GameOver = 1; }else{
            CurrentMoney-=RentPay;
            EventDefectModifier = 1;
            EventGainModifier = 1;
            EventPriceModifier = 1;
            int eventChance = QRandomGenerator::global()->bounded(5);
            if (eventChance == 3){
                int eventType = QRandomGenerator::global()->bounded(3);
                if (eventType == 1){Drought();} else if (eventType == 2){ Fertile();} else if (eventType == 3){Provider();}
            }

            RentTimer = 30;
        }
    }

    // Вызов обновления данных
    updateData();
}

// Смена текста при движении слайдера
void MainWindow::changeSellPercent(){
    ui->SellPercent->setText(QString::number(ui->SellSlider->value())+'%');
}

// Продажа товара
void MainWindow::sellVegetables(){
    CurrentMoney += vegetables.stock*(ui->SellSlider->value() / 100.0) * vegetables.price;
    vegetables.stock -= vegetables.stock*(ui->SellSlider->value() / 100.0);

    updateData();
}
void MainWindow::sellFruits(){
    CurrentMoney += fruits.stock*(ui->SellSlider->value() / 100.0) * fruits.price;
    fruits.stock -= fruits.stock*(ui->SellSlider->value() / 100.0);

    updateData();
}
void MainWindow::sellBerries(){
    CurrentMoney += berries.stock*(ui->SellSlider->value() / 100.0) * berries.price;
    berries.stock -= berries.stock*(ui->SellSlider->value() / 100.0);
    updateData();
}

// Открытие окна улучшений
void MainWindow::openUpgrades(){
    uWindow->show();
}

// Принятие данных о средствах из окна улучшений
void MainWindow::receiveMoneyData(int moneyData){
    CurrentMoney -= moneyData;
    updateData();
}

// Улучшение складов (1-3: Расширение/Улучшение/Контракт, 1-3: Овощи/Фрукты/Ягоды)
void MainWindow::receiveUpgrade(int operation, int itemType){
    if (operation == 1){
        if (itemType == 1){
            vegetables.warehouseSize++;
            RentPay = RentPay + 200 * vegetables.warehouseSize;
        }else if (itemType == 2){
            fruits.warehouseSize++;
            RentPay = RentPay + 300 * fruits.warehouseSize;
        }else if (itemType == 3){
            berries.warehouseSize++;
            RentPay = RentPay + 400 * berries.warehouseSize;
        }
    } else if(operation == 2){
        if (itemType == 1){
            vegetables.warehouseLVL++;
            RentPay = RentPay + 300 * vegetables.warehouseSize;
        }else if (itemType == 2){
            fruits.warehouseLVL++;
            RentPay = RentPay + 400 * fruits.warehouseSize;
        }else if (itemType == 3){
            berries.warehouseLVL++;
            RentPay = RentPay + 500 * berries.warehouseSize;
        }
    } else if (operation == 3){
        DefectPercent*=0.7;
        RentPay *= 1.2;
    }

    updateData();
}

// События
void MainWindow::Rent(){
    emit sendEventData("Событие: Неуплата аренды.",
                       "Вы не смогли заплатить за аренду в этом месяце, в следствие чего ваш контракт на аренду склада был разорван.",
                       "Игра окончена.");
    eWindow->show();
}
void MainWindow::Drought(){
    int variant = QRandomGenerator::global()->bounded(2);
    if (variant == 1){
        emit sendEventData("Событие: Сезон засухи (глобальный).",
                           "Следующий месяц для всех будет скудным на урожай, в следствие чего урожай будет ниже, но цены на товары поднимутся.",
                           "Прирост товаров ниже, цена товаров выше.");
        EventGainModifier = 0.5; EventPriceModifier = 1.5;
    }else{
        emit sendEventData("Событие: Сезон засухи (локальный).",
                           "Следующий месяц для вас будет скудным на урожай, в следствие чего урожай будет ниже.",
                           "Прирост товаров ниже.");
        EventGainModifier = 0.5;
    }
    eWindow->show();
}
void MainWindow::Fertile(){
    int variant = QRandomGenerator::global()->bounded(2);
    if (variant == 1){
        emit sendEventData("Событие: Плодородный сезон (глобальный).",
                           "Следующий месяц для всех будет богатым на урожай, в следствие чего урожай будет выше, но цены на товары снизятся.",
                           "Прирост товаров выше, цена товаров ниже.");
        EventGainModifier = 1.5; EventPriceModifier = 0.5;
    }else{
        emit sendEventData("Событие: Плодородный сезон (локальный).",
                           "Следующий месяц для вас будет богатым на урожай, в следствие чего урожай будет выше.",
                           "Прирост товаров выше.");
        EventGainModifier = 1.5;
    }
    eWindow->show();
}
void MainWindow::Provider(){
    int variant = QRandomGenerator::global()->bounded(2);
    if (variant == 1){
        emit sendEventData("Событие: Проблемные поставки.",
                           "В результате некачественных переевозок, количество брака товара увеличилось.",
                           "Выше процент брака.");
        EventDefectModifier = 1.5;
    }else{
        emit sendEventData("Событие: Удачные поставки.",
                           "Вы смогли заключить удачный договор на следующий метод на высококачественный товар.",
                           "Ниже процент брака.");
        EventDefectModifier= 0.5;
    }
    eWindow->show();
}
MainWindow::~MainWindow()
{
    delete ui;
}

