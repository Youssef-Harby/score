#pragma once

#include <QWidget>
#include <QString>
#include <QUrl>
#include <iscore_lib_base_export.h>
#include <QSize>

class QVBoxLayout;
class QQuickWidget;

class ISCORE_LIB_BASE_EXPORT QMLContainerPanel : public QWidget {
public:
    QMLContainerPanel(QWidget* parent = nullptr);
    QMLContainerPanel(QMLContainerPanel* container, QWidget* parent = nullptr);

    virtual void setSource(const QString&);
    QString source() const;
    virtual bool isCollapsed() const;
    const QSize internalSize() const;
    void setInternalSize(const QSize& s);
    void setInternalSize(const int& w, const int& h);

    ~QMLContainerPanel();

public slots:
    virtual void collapse();
    virtual QQuickWidget* container();
    virtual QWidget* rootWidget();

private:
    QString m_source;
    QWidget* m_widget;
    QQuickWidget* m_qcontainer;
    QAction* m_collapse;
    QVBoxLayout* m_layout;
};
