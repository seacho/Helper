#include "mainwidget.h"
#include "./ui_mainwidget.h"
#include <QLineEdit>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    initMenuBar();
    initUI();
}

MainWidget::~MainWidget()
{

    delete ui;
}

void MainWidget::filterModes(const QString &text)
{
    for (int i = 0; i < toolListWidget->count(); ++i) {
        QListWidgetItem *item = toolListWidget->item(i);
        // Set item visibility based on whether its text contains the search text (case-insensitive)
        item->setHidden(!item->text().contains(text, Qt::CaseInsensitive));
    }
}

void MainWidget::initMenuBar()
{
//    menuBar = new QMenuBar(this);
//    // menuBar->setNativeMenuBar(false);
//    QMenu *file = menuBar->addMenu("File");
//    QMenu *edit = menuBar->addMenu("Edit");
//    QMenu *help = menuBar->addMenu("Help");

//    file->addAction("New File");
//    file->addAction("Open File");
//    edit->addAction("Undo");
}
void MainWidget::initUI()
{
    setWindowTitle("Programming Helper");

    mainLayout = new QHBoxLayout(this);

    // --- Left Side: ListWidget for tools with Search ---
    QWidget *leftWidget = new QWidget(this);
    QVBoxLayout *leftLayout = new QVBoxLayout(leftWidget);

    QLabel *modeLabel = new QLabel("Select tool:", leftWidget);
    leftLayout->addWidget(modeLabel);

    // Add the search box (QLineEdit)
    searchLineEdit = new QLineEdit(leftWidget);
    searchLineEdit->setPlaceholderText("Search modes..."); // Placeholder text
    leftLayout->addWidget(searchLineEdit);
    // --- Connections ---
    // Connect the search box textChanged signal to the filter slot
    connect(searchLineEdit, &QLineEdit::textChanged, this, &MainWidget::filterModes);


    toolListWidget = new QListWidget(leftWidget);
    leftLayout->addWidget(toolListWidget);
    leftWidget->setLayout(leftLayout); // Set the layout for the left widget

    // Set a fixed width for the left widget (optional, but helps structure)
    leftWidget->setFixedWidth(200);

    // --- Apply Stylesheet to the List Widget for better appearance ---
    toolListWidget->setStyleSheet(
        "QListWidget {"
        "    border: 1px solid #cccccc;" // Add a light grey border
        "    border-radius: 5px;"      // Rounded corners
        "    background-color: #f0f0f0;" // Light grey background
        "    outline: 0;"               // Remove the focus outline
        "}"
        "QListWidget::item {"
        "    padding: 5px;"             // Add some padding to items
        "    border-bottom: 1px solid #dddddd;" // Separator line between items
        "}"
        "QListWidget::item:selected {"
        "    background-color: #a6a6a6;" // Darker background for selected item
        "    color: white;"             // White text for selected item
        "}"
        "QListWidget::item:hover {"
        "    background-color: #d0d0d0;" // Slightly darker background on hover
        "}"
        );

    // --- Right Side: Content Area (Placeholder) ---
    contentStackWidget = new QStackedWidget(this);

    addTooltoListWidget();
    // --- Add left and right widgets to the main layout ---
    mainLayout->addWidget(leftWidget);
    mainLayout->addWidget(contentStackWidget);


    // Connect the list widget's currentRowChanged signal to the stacked widget's setCurrentIndex slot
    // This will switch the content on the right when a list item is selected
    connect(toolListWidget, &QListWidget::currentRowChanged, contentStackWidget, &QStackedWidget::setCurrentIndex);

    // Set the initial selected item and corresponding stacked widget page
    if (toolListWidget->count() > 0) {
        toolListWidget->setCurrentRow(0);
    }
}

QVector<toolMetaInfo*> toolsMetaInfo;

toolMetaInfo::toolMetaInfo(
    QString name,
    QWidget* (*constractNewWidget)()
    )
{
    this->name = name;
    this->constractNewWidget = constractNewWidget;
    toolsMetaInfo.append(this);
};


void MainWidget::addTooltoListWidget()
{
    for (auto tool: toolsMetaInfo)
    {
        toolListWidget->addItem(tool->name);
        QWidget *toolWidget = tool->constractNewWidget();
        contentStackWidget->addWidget(toolWidget);
    }

}



