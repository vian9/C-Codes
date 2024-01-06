import zmq
import time

context = zmq.Context()

# Create a PUB socket
socket = context.socket(zmq.PUB)
socket.bind("tcp://*:5555")  # Bind to port 5555

while True:
    message = "Server time: " + str(time.time())
    socket.send(message.encode())
    time.sleep(5)  # Add a 1-second delay
