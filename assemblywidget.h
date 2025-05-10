#ifndef ASSEMBLYWIDGET_H
#define ASSEMBLYWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <keystone/keystone.h>
#include <capstone/capstone.h>

class AssemblyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AssemblyWidget(QWidget *parent = nullptr);
private:
    int curArch;
    QTextEdit *assemblyInput;
    QTextEdit *outputDisplay;
    ks_engine *ksEng;
    csh csEng;

private slots:
    void setBinaryTextEdit();
    void setAssemblyTextEdit();
    void setCurArch(int indexArch);
signals:

};

#endif // ASSEMBLYWIDGET_H
