#include "procmemreaderwidget.h"
#include "mainwidget.h"
#include <iostream>
extern "C" {
#include "mac/requestRootAuthorization.h"
}

ProcMemReaderWidget::ProcMemReaderWidget(QWidget *parent)
    : QWidget{parent}
{

}




QWidget* registerProcMemReaderWidget()
{
    return new ProcMemReaderWidget();
}
//toolMetaInfo gProcMemReaderWidget(
//    "ProcMemReader",
//    registerProcMemReaderWidget
//    );
