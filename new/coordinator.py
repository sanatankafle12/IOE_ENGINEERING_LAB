from threading import Thread
from threading import Lock
import socket

HOST = "127.0.0.1"
PORT = 9000

acks = 0
abort = False

lock = Lock()

def coordinate(psock, addr, lock):
	global acks, abort
	start = time.time()
	psock.sendall(b"PREPARE")
	go_ahead = psock.recv(1024)

	with lock:
		acks += 1

	if go_ahead == b"ABORT":
		abort = True

	while acks < 5:
		pass

	if not abort:
		psock.send(b"COMMIT")
	else:
		psock.send(b"ABORT")

	ack = psock.recv(1024)
	print(addr, ack)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen(6)
    for i in range(5):
	    conn, addr = s.accept()
	    Thread(target=coordinate, args=(conn, addr, lock)).start()
	    