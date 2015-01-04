#ifndef IAPPLYABLE
#define IAPPLYABLE

#include <QWidget>

struct IApplyable
{
public:
    virtual void apply() = 0;
};

class QWidgetApplyable : public QWidget, public IApplyable
{

};

#endif // IAPPLYABLE

