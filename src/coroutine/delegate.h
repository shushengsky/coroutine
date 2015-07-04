/*
 * delegate.h
 *
 *  Created on: 2015年7月2日
 *      Author: zhusheng
 */

#ifndef SRC_COROUTINE_DELEGATE_H_
#define SRC_COROUTINE_DELEGATE_H_

#include <memory>

namespace coroutine
{

class coroutine_base;
typedef std::shared_ptr<coroutine_base> coroutine_ptr;

class delegate
{
public:
    virtual ~delegate() = default;
    virtual void on_start(coroutine_base*) = 0;
    virtual void on_stop(coroutine_base*) = 0;
};

} /* namespace coroutine */

#endif /* SRC_COROUTINE_DELEGATE_H_ */