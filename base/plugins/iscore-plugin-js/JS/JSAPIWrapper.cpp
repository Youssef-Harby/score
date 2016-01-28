#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>

#include <Explorer/DocumentPlugin/NodeUpdateProxy.hpp>
#include "JSAPIWrapper.hpp"

namespace JS
{
QJSValue APIWrapper::value(QJSValue address)
{
    auto addr_str = address.toString();
    if(State::Address::validateString(addr_str))
    {
        return iscore::convert::JS::value(
                    m_engine,
                    devices.updateProxy.refreshRemoteValue(State::Address::fromString(addr_str)));
    }

    return {};
}
}
