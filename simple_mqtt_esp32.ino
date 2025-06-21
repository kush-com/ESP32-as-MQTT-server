#include <PicoMQTT.h>

#define MyWiFi ""  //replace with your wifi name as displayed
#define password "" //password to login the wifi network, avoid use of open networks

PicoMQTT::Server mqtt;

void setup() {
    // Usual setup
    Serial.begin(115200);

    //attempting to connect to wifi
    Serial.printf("connecting to wifi %s\n", MyWiFi);
    WiFi.mode(WIFI_STA);
    WiFi.begin(MyWiFi, password);
    while(WiFi.status() != WL_CONNECTED){
      delay(1000);
    }
    Serial.printf("Wifi connected to IP: %s\n", WiFi.localIP().toString().c_str());

    // Subscribe to a topic pattern and attach a callback
    mqtt.subscribe("#", [](const char * topic, const char * payload) {
        Serial.printf("Received message in topic '%s': %s\n", topic, payload);
    });

    // Start the broker
    mqtt.begin();
}

void loop() {
    // This will automatically handle client connections.  By default, all clients are accepted.
    mqtt.loop();
}