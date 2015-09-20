//
// Date: 2015/09/09
// Author: dinosaur
//
// drive NonCopyable for non copyable.

#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

class NonCopyable
{
    public:
        NonCopyable() = default;
        NonCopyable(const NonCopyable&) = delete;
        NonCopyable& operator=(const NonCopyable&) = delete;
};

#endif
