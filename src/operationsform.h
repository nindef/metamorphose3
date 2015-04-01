#ifndef OPERATIONSFORM_H
#define OPERATIONSFORM_H

#include <QtWidgets/QWidget>
#include "operationformmodel.h"

namespace Ui {
class OperationsForm;
}

class OperationsForm : public QWidget
{
    Q_OBJECT

public:
    explicit OperationsForm(OperationFormModel *model, QWidget *parent = 0);
    ~OperationsForm();

private slots:
    void on_addOperation_activated(int index);
    void on_operationsTable_activated(const QModelIndex &index);
    void on_deleteOperation_activated(int index);

    void operationFormModel_rowsInserted();

    void on_applyToName_clicked(bool checked);

    void on_applyToExtension_clicked(bool checked);

private:
    void setActionsEnabled(bool enable);

    Ui::OperationsForm *ui;
    OperationFormModel *operationFormModel;
};

#endif // OPERATIONSFORM_H
