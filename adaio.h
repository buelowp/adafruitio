#ifndef AdafruitIO_H
#define AdafruitIO_H

#include <string>
#include <functional>
#include <iostream>
#include <cstring>
#include <mosquittopp.h>
#include <cstdio>

class AdafruitIO : public mosqpp::mosquittopp
{
public:
    enum CallbackType {
        CONNECT = 0,
        SUBSCRIBE,
        UNSUBSCRIBE,
        PUBLISH,
        DISCONNECT,
    };

    AdafruitIO(std::string &id, std::string &host, std::string &username, std::string &password, int port);
    virtual ~AdafruitIO();

    void setGenericCallback(std::function<void(CallbackType, int)> cbk) { m_genericCallback = cbk; }
    void setMessageCallback(std::function<void(int, std::string, uint32_t*, int)> cbk) { m_messageCallback = cbk; }
    void setErrorCallback(std::function<void(std::string, int)> cbk) { m_errorCallback = cbk; }
    
    void enableDebug(bool debug) { m_debug = debug; }
    
	void on_connect(int rc) override;
    void on_disconnect(int rc) override;
    void on_error() override;
    void on_subscribe(int , int , const int*) override;
    void on_unsubscribe(int) override;
    void on_message(const struct mosquitto_message*) override;
    void on_publish(int) override;
        
private:
    std::string m_name;
    std::string m_host;
    std::string m_user;
    std::string m_pass;
    std::function<void(CallbackType, int)> m_genericCallback;
    std::function<void(int, std::string, uint32_t*, int)> m_messageCallback;
    std::function<void(std::string, int)> m_errorCallback;
    int m_port;
    int m_debug;
};

#endif // AdafruitIO_H
