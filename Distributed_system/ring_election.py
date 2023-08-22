import socket
import threading


processes = [8000+i for i in range(5)]

def process(port):
	participant = False
	elected = None
	own_id = port
	listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	listener.bind(('127.0.0.1', port))
	listener.listen(5)

	if own_id == 8003 or own_id == 8000: # processes that start the election
		con = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		con.connect(('127.0.0.1', own_id+1))
		con.send(own_id.to_bytes(4, 'big'))
		con.sendall(b'ELECTION')
		con.close()

	def accept():
		nonlocal participant, elected, own_id
		connection, address = listener.accept()
		data = connection.recv(4)
		if not data:
			return
		msg_type = connection.recv(16)
		con2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		con2.connect(('127.0.0.1', ((port+1) if port != 8004 else 8000)))


		if msg_type == b"ELECTION":
			prev_id = int.from_bytes(data, 'big')

			print(f'{own_id} received {prev_id}')
			if participant == False or prev_id > own_id:
				participant = True
				nxt_id = max(prev_id, own_id)
				
				con2.send(nxt_id.to_bytes(4, 'big'))
				con2.sendall(b"ELECTION")
				print(f'{own_id} passsed on {nxt_id}')


			if prev_id == own_id:
				participant = False
				elected = own_id
				
				con2.send(own_id.to_bytes(4, 'big'))
				con2.sendall(b"ELECTED")
				print(f'{own_id} am electing myself the co-ordinator.')

		else:
			elected_id = int.from_bytes(data, 'big')
			if elected_id != own_id:
				participant = False
				elected = elected_id

				con2.send(elected_id.to_bytes(4, 'big'))
				con2.sendall(b"ELECTED")
				print(f'{own_id} recognizes {elected_id} as the co-ordinator.')
		con2.close()

	while True:
		accept()

for i in range(5):
	threading.Thread(target=process, args=(processes[i],)).start()