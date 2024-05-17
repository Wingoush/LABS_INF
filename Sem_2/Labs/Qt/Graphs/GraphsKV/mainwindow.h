#include <QWidget>
#include <QMouseEvent>
#include <ui_mainwindow.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Предопределение классов
class Edge;
class Node;
class Graph;

class Node{
public:
    int data;
    vector<Edge*> edges_to_node;
    QPoint pos;
    Node(){
        pos = QPoint(800 + (rand()%400 - 400), 300 + (rand()%300 - 300));
    }
};

class Edge{
public:
    int weight;
    Node* to;
};

class Graph{
public:
    unordered_map<int, Node*> nodes_map;

    void DepthBypass(int startData, vector<int>& dbp);
    void WidthBypass(int startData, vector<int>& wbp);
    vector<int> AlgorithmBypass(int startData, int endData);

    void addNode(int data);
    void removeNode(int data);

    void addEdge(int startData, int endData, int weight);
    void removeEdge(int startData, int endData);
    void updateEdgeWeight(int startData, int endData, int newWeight);

    void clearGraph();
};

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    Graph graph;

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
private:
    Ui::MainWindow ui;
    Node* selectedNode;
    bool nodeMoving;
    bool nodeSelection = false;
    Node* currentNode;

    void printAdjTable(const Graph& graph);

public slots:
    void nodeOperation();
    void edgeOperation();
    void bypassOperation();
    void createGraph();
    void deleteGraph();
    void printTable();
};
