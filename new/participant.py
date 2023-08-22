import socket
import random
from threading import Thread

HOST = "127.0.0.1"
PORT = 9000

def participate():
	with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	    s.connect((HOST, PORT))
	    r = s.recv(1024)

	    #perform the actual transaction
	    #we will assume each process aborts with probability .1 during transaction
	    if random.random() < 0.1:
	    	s.sendall(b"ABORT")
	    else:
	    	s.sendall(b"PROCEED")

	    if s.recv(1024) == b"COMMIT":
	    	s.sendall(b"Committed")
	    else:
	    	s.sendall(b"Aborted")

for i in range(5):
	Thread(target=participate, args = ()).start()