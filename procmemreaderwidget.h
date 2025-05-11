#ifndef PROCMEMREADERWIDGET_H
#define PROCMEMREADERWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <keystone/keystone.h>
#include <capstone/capstone.h>

class ProcMemReaderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProcMemReaderWidget(QWidget *parent = nullptr);

signals:

};

#endif // PROCMEMREADERWIDGET_H
