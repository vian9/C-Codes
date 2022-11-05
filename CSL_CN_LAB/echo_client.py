import socket

HOST = '127.0.0.1' #The Server's hostname or IP address
PORT = 65432 # The port used by the server

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    data = input()
    s.sendall(data.encode())
    data = s.recv(1024).decode()
    
print('Received',repr(data))