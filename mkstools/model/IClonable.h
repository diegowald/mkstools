#ifndef ICLONABLE_H
#define ICLONABLE_H

#include <QSharedPointer>

template <class T> class IClonable
{
public:
    virtual ~IClonable() {}
    virtual QSharedPointer<T> clone() = 0;
};

#endif // ICLONABLE_H
