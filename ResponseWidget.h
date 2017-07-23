#ifndef RESPONSEWIDGET_H
#define RESPONSEWIDGET_H

#include <QWidget>
#include <QVector>

class QCustomPlot;
class QLineEdit;
class QCPGraph;
class QCPItemTracer;
class MainWindow;

class ResponseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ResponseWidget(MainWindow *main, int mainWindowItem, QWidget *parent = 0);
    ~ResponseWidget();

    int getItem();
    void setItem(int);
    void setData(QVector<double> &data, QVector<double> time, int numSteps, double dt);
    void setData(QVector<double> &data, QVector<double> x, int numSteps);

signals:

public slots:
    void itemEditChanged(void);

private:
    QCustomPlot *thePlot;
    QLineEdit *theItemEdit;
    int theItem; // floor or story #
    int mainWindowItem; // tag used in call back

    MainWindow *main;

    QCPGraph *graph;
    QCPItemTracer *groupTracer;
};

#endif // NODERESPONSEWIDGET_H
