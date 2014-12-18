#ifndef SINGLETON_H
#define SINGLETON_H

#include "no_base.h"

template <class S, class B = NoBase>
class Singleton : public B
{
    static S *__instance;
    static bool __destroyed;

protected:
    Singleton() = default;

    static bool destroyed();

public:
    virtual ~Singleton();

    static S *instance();
};

///////////////////////////////////////////////////////////////////////////////

template <class S, class B> S *Singleton<S, B>::__instance;
template <class S, class B> bool Singleton<S, B>::__destroyed = true;

template <class S, class B>
Singleton<S, B>::~Singleton()
{
    __destroyed = true;
}

template <class S, class B>
bool Singleton<S, B>::destroyed()
{
    return __destroyed;
}

template <class S, class B>
S *Singleton<S, B>::instance()
{
    if (__destroyed)
    {
        __instance = new S();
        __destroyed = false;
    }

    return __instance;
}

#endif // SINGLETON_H
