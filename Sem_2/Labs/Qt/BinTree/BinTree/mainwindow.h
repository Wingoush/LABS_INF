#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
using namespace std;
QT_END_NAMESPACE

// Создание класса узла
class Node{
public:
    int key;
    Node* left;
    Node* right;
    Node(char key){
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void insertNode(Node* root, char key);
void deleteNode(Node* &root, char key);
void preorderBypass(Node* root);
void inorderBypass(Node* root);
void postorder(Node* root);
void deleteTree(Node* &root);
Node* balanceTree(Node* root);

class BinTreeView : public QGraphicsView{
public:
    QGraphicsScene* scene;
    Node* main_root;

    // Получение текущей глубины дерева
    int getTreeDepth(Node* node){
        if (node == nullptr){
            return 0;
        }
        int leftDepth = getTreeDepth(node->left);
        int rightDepth = getTreeDepth(node->right);
        return 1 + max(leftDepth, rightDepth);
    }
    void drawTreeNode(Node* node, int x, int y){
        // Прерывание если нет продолжения дерева
        if (node == nullptr){
            return;
        }
        // Конфигурация отрисовки
        QPen linePen(Qt::red);
        linePen.setWidth(1);
        QBrush circleBrush(Qt::white);

        // Сдвиг позиций узлов в зависимости от текущей глубины дерева для левой и правой части
        int offsetX_l = 30 * pow(2, getTreeDepth(node->left));
        int offsetX_r = 30 * pow(2, getTreeDepth(node->right));
        int offsetY = 70;

        // Отрисовка нижних уровней и их связи с верхними
        if (node->left != nullptr){
            scene->addLine(x + 20, y + 20, x - offsetX_l + 20, y + offsetY + 20, linePen);
            drawTreeNode(node->left, x - offsetX_l, y + offsetY);
        }
        if (node->right != nullptr){
            scene->addLine(x + 20, y + 20, x + offsetX_r + 20, y + offsetY + 20, linePen);
            drawTreeNode(node->right, x + offsetX_r, y + offsetY);
        }

        // Отрисовка и позициирование узлов
        scene->addEllipse(x, y, 40, 40, linePen, circleBrush);

        // Отрисовка значений в узлах
        QFont font("Times New Roman", 12);
        QGraphicsTextItem* textItem = scene->addText("", font);
        textItem->setTextWidth(40);
        textItem->setPos(x, y+5);
        textItem->setHtml("<div align='center'>"+ QString::number(node->key) +"</div>");
    }


public:
    // Инициализация рабочего окна и первоначального узла
    BinTreeView(Node* root, QWidget* parent = nullptr) : QGraphicsView(parent), main_root(root){
        scene = new QGraphicsScene(this);
        setScene(scene);
        drawTreeNode(main_root, 0, 0);
    }
};
class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void createTree();
    void insertNodeBTN();
    void deleteNodeBTN();
    void bypassBTN();
    void balanceBTN();
    void keyCountBTN();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene2;

    Node* root;
    BinTreeView* view;

    // Методы
    void updateTreeView();
};
#endif // MAINWINDOW_H
