import paho.mqtt.client as mqtt
import time

# MQTT broker address and port
broker_address = "192.168.232.169"  #same as the one printed on the Serial monitor when you upload the code on ESP32.
broker_port = 1883 #select the same number not randomly

#create mqtt client
client = mqtt.Client()

#connect to mqtt broker
client.connect(broker_address, broker_port)

#subscribe to a topic
topic = "Python"
client.subscribe(topic)

#Function to handle incoming messages
def on_message(client, userdata, message):
    print("Recieved message: ", str(message.payload.decode))

#calling
client.on_message = on_message

#publishing the same string to mqtt broker, i.e ESP32
client.publish(topic, msg)
print(f"Published message: {msg}")
time.sleep(0.05)