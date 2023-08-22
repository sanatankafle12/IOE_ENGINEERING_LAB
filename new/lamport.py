import threading
import random
import time
import socket

ports = [8000+i for i in range(5)]

def process(socket_port, ports):
	timestamp = 0
	lock = threading.Lock()
	listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	listener.bind(('127.0.0.1', socket_port))
	listener.listen(5)
	def handle_connection(connection, address):
		nonlocal timestamp
		data1 = connection.recv(4)
		if not data1:
			return
		data2 = connection.recv(4)
		received_timestamp = int.from_bytes(data1, 'big')
		sender_port = int.from_bytes(data2, 'big')

		with lock:
			if received_timestamp > timestamp:
				timestamp = received_timestamp
			timestamp += 1

		print(f"{socket_port}: RECEIVE {timestamp} from", sender_port)
		
	def accept():
		while True:
			connection, address = listener.accept()
			handle_connection(connection, address)

	receive_thread = threading.Thread(target=accept)
	receive_thread.start()

	for i in range(5):
		slp = random.randint(0, 4)
		time.sleep(slp)

		with lock:
			timestamp += 1
			req = timestamp
		
		internal = random.randint(0, 1) 

		if internal == 0:
			while True: 
				port = random.choice(ports)
				if port != socket_port:
					break
			print(f"{socket_port}: REQUEST {req} to {port}")

			connection = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			connection.connect(('127.0.0.1', port))
			encoded = req.to_bytes(4, 'big')

			connection.send(encoded)
			connection.send(socket_port.to_bytes(4, 'big'))
			connection.close()
		else:
			print(f"{socket_port}: Internal Process Event {req}.")


for i in range(len(ports)):
	threading.Thread(target=process, args=(ports[i], ports)).start()