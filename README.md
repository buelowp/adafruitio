# C++ MQTT library for connecting to Adafruit IO

This is a C++ 14 compliant library that uses libmosquittopp as a backend, and implements methods to directly connect using unencrypted or encrypted MQTT to Adafruit.io. The API is simple, provides a quick solution, and works for the simplest cases. It really hasn't been tested much beyond that.

## Usage

```
mkdir build
cd build
cmake ..
make
make install DESTDIR=...
```

The AdafruitIO class directly inherits mosqpp::mosquittopp, so you can do all of the standard API calls.

The default constructor takes the following arguments

```
AdafruitIO(std::string &id, std::string &host, std::string &username, std::string &password, int port)
```

Where
* id: The overloaded MQTT name to use for this connection. The library forces you to create one to avoid conflicts later.
* host: The AdafruitIO hostname
* username: Your AdafruitIO connectoin username
* password: Your AdafruitIO password, which for all uses is actually the KEY you generate on the site, and not your login password
* port: You can use 1883 or 8883, but it will enforce encrypted or not encrypted connections depending on your choice

The following functions are overridden to work for this library

* on_connect(int rc)
* on_disconnect(int rc)
* void on_error()
* on_subscribe(int , int , const int*)
* on_unsubscribe(int)
* void on_message(const struct mosquitto_message*)
* void on_publish(int)

Each will fire a callback to your application with the specified parameters

The following fire a the generic callback with the operation type specified

* on_connect
* on_disconnect
* on_subscribe
* on_publish

A message received will fire a callback passing the mosquitto_message as a pointer to the caller. The caller MUST not free the message struct or otherwise clean up.

An error fires the error callback.

