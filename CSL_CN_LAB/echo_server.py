import socket

HOST = '127.0.0.1' #Standard loopback interface address(local)
PORT = 65432 #Port to listen on(non-privileged ports)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT))
    s.listen()
    conn,addr = s.accept()
    with conn:
        print('Connected by',addr,conn)
        while True:
            data = conn.recv(1024)
            data = data.decode()
            print(data)
            if not data:
                break
            fact = 1
            for i in range(1,int(data)+1):
                fact = fact * i
            conn.sendall(str(fact).encode())