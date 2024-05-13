#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    view = nullptr;

    connect(ui->TreeBalanceBTN, &QPushButton::pressed, this, &MainWindow::balanceBTN);
    connect(ui->NodeDeleteBTN, &QPushButton::pressed, this, &MainWindow::deleteNodeBTN);
    connect(ui->NodeAddBTN, &QPushButton::pressed, this, &MainWindow::insertNodeBTN);
    connect(ui->Bypass, &QPushButton::pressed, this, &MainWindow::bypassBTN);
    connect(ui->ButtonFindMax, &QPushButton::pressed, this, &MainWindow::keyCountBTN);

    createTree();
    balanceBTN();
}

// Удаление дерева (или его части) и обновление
void deleteTree(Node* &root){
    if (root == nullptr){ return; }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;

    root = nullptr;

    return;
}
void MainWindow::updateTreeView(){
    if (view != nullptr){ delete view; }

    view = new BinTreeView(root, ui->Scene);
    view->resize(ui->Scene->width(), ui->Scene->height());
    view->setRenderHint(QPainter::Antialiasing);
    view->show();

    return;
}

// Обходы дерева
void preorderBypass(Node* root, QString& bypassResult){
    if (root == nullptr){ return; }

    bypassResult += QString::number(root->key) + " ";
    preorderBypass(root->left, bypassResult);
    preorderBypass(root->right, bypassResult);

    return;
}
void inorderBypass(Node* root, QString& bypassResult){
    if (root == nullptr){ return; }

    inorderBypass(root->left, bypassResult);
    bypassResult += QString::number(root->key) + " ";
    inorderBypass(root->right, bypassResult);

    return;
}
void postorder(Node* root, QString& bypassResult){
    if (root == nullptr){ return; }

    postorder(root->left, bypassResult);
    postorder(root->right, bypassResult);
    bypassResult += QString::number(root->key) + " ";

    return;
}
void MainWindow::bypassBTN(){
    ui->TextOutput->clear();
    QString bypass;

    switch(ui->BypassMethod->currentIndex()){
    case 0: bypass = "Прямой: ";
        preorderBypass(root, bypass);
        ui->TextOutput->setText(bypass);
        break;
    case 1: bypass = "Симметричный: ";
        inorderBypass(root, bypass);
        ui->TextOutput->setText(bypass);
        break;
    case 2: bypass = "Обратный: ";
        postorder(root, bypass);
        ui->TextOutput->setText(bypass);
    }

    return;
}

// Удалить узел и все последующие ветви
void deleteNode(Node* &root, char key){
    if (root == nullptr){ return; }

    if (key < root->key){
        deleteNode(root->left, key);
    } else if (key > root->key){
        deleteNode(root->right, key);
    } else {
        deleteTree(root);
    }

    return;
}
void MainWindow::deleteNodeBTN(){
    int key = (ui->NodeEntry->text()).toInt();

    deleteNode(root, key);

    updateTreeView();

    ui->NodeEntry->clear();
    ui->TextOutput->setText("Узел удалён.");

    return;
}

// Вставить узел на подходящую позицию
void insertNode(Node* root, char key){
    if (root == nullptr){ return; }

    if (key < root->key){
        if (root->left == nullptr){
            root->left = new Node(key);
        }else{
            insertNode(root->left, key);
        }
    }else{
        if (root->right == nullptr){
            root->right = new Node(key);
        }else{
            insertNode(root->right, key);
        }
    }

    return;
}
void MainWindow::insertNodeBTN(){
    int key = (ui->NodeEntry->text()).toInt();

    insertNode(root, key);
    updateTreeView();

    ui->NodeEntry->clear();
    ui->TextOutput->setText("Узел вставлен.");

    return;
}

// Балансировка дерева
void storeinorderBypass(Node* root, vector<char> &values){
    if (root == nullptr){ return; }

    storeinorderBypass(root->left, values);
    values.push_back(root->key);
    storeinorderBypass(root->right, values);

    return;
}
Node* buildBalancedTree(const vector<char> &values, int start, int end){
    if (start > end){ return nullptr; }

    int mid = (start + end) / 2;
    Node* root = new Node(values[mid]);

    root->left = buildBalancedTree(values, start, mid - 1);
    root->right = buildBalancedTree(values, mid + 1, end);

    return root;
}
Node* balanceTree(Node* root){
    vector<char> values;
    storeinorderBypass(root, values);

    if (values.empty()){ return nullptr; }
    sort(values.begin(), values.end());

    return buildBalancedTree(values, 0, values.size() - 1);
}
void MainWindow::balanceBTN(){
    if (root == nullptr){ return; }

    Node* newRoot = balanceTree(root);
    if (newRoot != nullptr){
        deleteTree(root);
        root = newRoot;
        updateTreeView();
        ui->TextOutput->setText("Дерево сбалансировано.");
    }

    return;
}

// Создать дерево
void MainWindow::createTree(){
    srand(time(0));
    root = new Node(rand()%100-rand()%100);

    for(int i = 0; i < rand()%100; i++){
        insertNode(root, (rand()%100-rand()%100));
    }

    updateTreeView();
    return;
}

// Поиск количества значений в дереве
int findKey(Node* node, char key){
    if (node == nullptr){ return 0; }
    if (node->key == key){ return 1 + findKey(node->right, key) + findKey(node->left, key);}

    return findKey(node->right, key) + findKey(node->left, key);
}
void MainWindow::keyCountBTN(){
    if (root == nullptr){ return; }
    int key = (ui->NodeEntry->text()).toInt();

    int count = findKey(root, key);

    ui->TextOutput->setText("Кол-во значений: " + QString::number(count));
    return;
}

MainWindow::~MainWindow(){
    delete ui;
    if (view != nullptr)
        delete view;
}
