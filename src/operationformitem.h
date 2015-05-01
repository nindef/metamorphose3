#ifndef OPERATIONFORMITEM_H
#define OPERATIONFORMITEM_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include "core/operationitem.h"
#include "suboperationsform.h"

namespace Ui {
class OperationFormItem;
}

class OperationFormItem : public QWidget
{
    Q_OBJECT

public:
    explicit OperationFormItem(QWidget *parent = 0);
    ~OperationFormItem();
    virtual OperationItem* getOperation() = 0;
    virtual void configureOperation() = 0;
    virtual QString name() = 0;
    void init(QLineEdit *mainInput);
    void init();
    bool applyToName = true;
    bool applyToExtension = false;

protected:
    SubOperationsForm *subOperationsForm;
    Ui::OperationFormItem *formItemUi;
    QLineEdit *mainInput = 0;

private slots:
    void insertSubOpText(QString text);
};

#endif // OPERATIONFORMITEM_H
