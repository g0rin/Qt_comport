#include "command_form.h"
#include "ui_command_form.h"

QDialogCommand::QDialogCommand(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDialogCommand)
{
    ui->setupUi(this);
}

QDialogCommand::~QDialogCommand()
{
    delete ui;
}

void QDialogCommand::set_command(const QHash<QString, QString> &data)
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(data.count());

    int r = 0;

    QHashIterator<QString, QString> i(data);
    while (i.hasNext()) {
        i.next();
        ui->tableWidget->setItem( r, 0, new QTableWidgetItem(i.key()));
        ui->tableWidget->setItem( r, 1, new QTableWidgetItem(i.value()));
        r++;
    }


}

void QDialogCommand::on_addButton_clicked()
{
    ui->tableWidget->insertRow(0);
}

void QDialogCommand::on_buttonBox_accepted()
{
    QHash<QString, QString> data;
    for (int i=0;i<ui->tableWidget->rowCount();i++) {
        data.insert(ui->tableWidget->item(i,0)->text(), ui->tableWidget->item(i,1)->text());
    }

    emit commandChanged(data);
}

void QDialogCommand::on_delButton_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}
