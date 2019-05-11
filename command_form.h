#ifndef COMMAND_FORM_H
#define COMMAND_FORM_H

#include <QDialog>

namespace Ui {
class QDialogCommand;
}

class QDialogCommand : public QDialog
{
    Q_OBJECT

public:
    explicit QDialogCommand(QWidget *parent = nullptr);
    ~QDialogCommand();
public slots:
    void set_command(const QHash<QString, QString> &data);

private slots:
    void on_addButton_clicked();
    void on_buttonBox_accepted();

    void on_delButton_clicked();

signals:
    void commandChanged (const QHash<QString, QString> &data);

private:
    Ui::QDialogCommand *ui;
};

#endif // COMMAND_FORM_H
