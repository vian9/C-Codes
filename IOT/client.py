import zmq

context = zmq.Context()

# Create a SUB socket
socket = context.socket(zmq.SUB)
socket.connect("tcp://localhost:5555")  # Connect to the server's address

# Subscribe to all messages (empty string)
socket.setsockopt_string(zmq.SUBSCRIBE, "")

while True:
    message = socket.recv().decode()
    print(message)
