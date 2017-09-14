#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QProcess"
#include "qfilesystemmodel.h"
#include "qtreeview.h"
#include "qdirmodel.h"
#include "qmenu.h"
#include "qaction.h"

#define ROLE_MARK Qt::UserRole + 1
#define MARK_FOLDER 2
#define MARK_ITEM 3


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDirModel *model= new QDirModel();
    ui->fileView->setModel(model);
    ui->fileView->setRootIndex(model->index("D:\\myDesktop"));

    //QProcess::execute("explorer.exe");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myMenu()
{
    m_projectMenu = new QMenu(this);
    m_itemMenu = new QMenu(this);

    QAction* ac = nullptr;

}
void MainWindow::on_fileView_customContextMenuRequested(const QPoint &pos)
{
    QModelIndex index = ui->fileView->indexAt(pos);
    QVariant var = index.data(ROLE_MARK);
    if(var.isValid())
    {
        if(MARK_FOLDER==var.toInt())
            m_projectMenu->exec(QCursor::pos());
        else if(MARK_ITEM==var.toInt())
            m_itemMenu->exec(QCursor::pos());

    }
}
