/*
 * @Author: hongdong.liao
 * @Date: 2022-04-21 15:40:45
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-23 09:56:16
 * @FilePath: /test/Factory.hpp
 */
#pragma once

#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <type_traits>
#include <map>

#define ERROR(message)                                                                   \
    {                                                                                    \
        std::ostringstream _err;                                                         \
        _err << "Fatal error.\n"                                                         \
             << " In Function " << __func__ << " at line " << __LINE__ << " of file "    \
        << __FILE__ << "\n"                                                              \
        << message << std::endl;                                                         \
        std::fprintf(stderr, "%s", _err.str().c_str());                                  \
        std::exit(EXIT_FAILURE);                                                         \
    }

namespace detail {
template <typename CreateObject> class BaseFactory {
private:
    typedef std::map<std::string, CreateObject> CallbackMap;
    typedef typename CallbackMap::value_type CallbackPair;
    typedef typename CallbackMap::const_iterator CallbackConstIter;

protected:
    CallbackMap callbacks_;
    CallbackConstIter retrieve(const std::string &objId) const {
        if (objId.empty()) {
            ERROR("Object id is empty.");
        }
        CallbackConstIter i = callbacks_.find(objId);
        if (i == callbacks_.end())
            ERROR("Object id is not found.");
        return i;
    }

private:
    bool registerObject(const std::string &objId, const CreateObject &functor) {
        return callbacks_.insert(CallbackPair(objId, functor)).second;
    }
    bool unRegisterObject(const std::string &objId) {
        return callbacks_.erase(objId) == 1;
    }

public:
    void subscribe(const std::string &objId, const CreateObject &functor) {
        bool done = this->registerObject(objId, functor);
        if (!done)
            ERROR("Subscription of object ID " + objId + " to factory failed!");
    }
    void unsubscribe(const std::string &objId) {
        bool done = this->unRegisterObject(objId);
        if (!done)
            ERROR("Unsubscription of object ID " + objId + " from factory failed!");
    }
};
}

template <typename CreateObject>
class Factory final : public detail::BaseFactory<CreateObject> {
public:
    template <typename... ObjectInputArgs>
    typename std::result_of<CreateObject(ObjectInputArgs...)>::type create(
        const std::string &objId, ObjectInputArgs... data) const {
        return (this->retrieve(objId)->second)(data...);
    }
};