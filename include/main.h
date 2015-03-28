#ifndef MAIN_H
#define MAIN_H
#ifdef __cplusplus


#define DECLARE_CLASS_PTR(type) \
    class type; \
    typedef std::shared_ptr<type> type##Ptr; \
    typedef const std::shared_ptr<type> type##CPtr; \
    typedef std::weak_ptr<type> type##WPtr;

#define DECLARE_NS_CLASS_PTR(ns, type) \
    namespace ns { \
    class type; \
    typedef std::shared_ptr<type> type##Ptr; \
    typedef const std::shared_ptr<type> type##CPtr; \
    typedef std::weak_ptr<type> type##WPtr; \
    }


#endif
#endif
