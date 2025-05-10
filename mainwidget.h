#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QStackedWidget> // Useful for switching content on the right

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();


private:
    Ui::MainWidget *ui;
    QMenuBar *menuBar;
    QHBoxLayout *mainLayout;
    QListWidget *toolListWidget;
    QLineEdit *searchLineEdit;
    QStackedWidget *contentStackWidget;

    void initMenuBar();
    void initUI();
    void addTooltoListWidget();

private slots:
    // Slot to filter the list widget items based on search text
    void filterModes(const QString &text);

};

struct toolMetaInfo{
public:
    toolMetaInfo(
        QString name,
        QWidget* (*constractNewWidget)()
        );

    QString name;
    QWidget* (*constractNewWidget)();
};

#endif // MAINWIDGET_H
