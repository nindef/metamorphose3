#include "operationitem.h"

void OperationItem::applyOperation(int itemPosition, std::pair<QString, QString> &name)
{
    this->itemPosition = itemPosition;

    if (applyToName) {
        operation(name.first);
    }
    if (applyToExtension) {
        operation(name.second);
    }
}

/**
 * Innermost loop!
 */
QString OperationItem::parseSubOps(const QString text)
{
    qCDebug(M3CORE) << "parsing for subops" << text;

    QStringList segments = text.split(":", QString::SkipEmptyParts);

    for (int i = 0; i < segments.size(); ++i) {
        QString segment = segments.at(i);

        if (segment == "numb") {
            segments[i] = numbering();
        }
        if (segment == "date") {
            segments[i] = datetime("yyyy-MM-dd");
        }
        if (segment == "time") {
            segments[i] = datetime("hh-mm-ss");
        }
    }
    return segments.join("");
}

void OperationItem::setApplyToName(const bool apply)
{
    applyToName = apply;
}

void OperationItem::setApplyToExtension(const bool apply)
{
    applyToExtension = apply;
}

QString OperationItem::numbering()
{
    int numb = itemPosition + 1;
    return QString("%1").arg(numb, 3, 10, QChar('0'));
}

QString OperationItem::datetime(const QString format)
{
    QDateTime datetime = QDateTime::currentDateTime();
    return datetime.toString(format);
}
