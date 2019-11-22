import socket

#获取本机名
myname=socket.gethostname()

#获取本机ip
myaddr=socket.gethostbyname(myname)

print(myname+':'+myaddr)

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.setblocking(False)

s.bind(('',10000))
print("Alone  sendto ('127.0.0.1',10000)")
for i in ['A','l','o','n','e']:
    data=str(i)
    data=data.encode()
    s.sendto(data,('127.0.0.1',10000))
    try:
        data,addr=s.recvfrom(1024)
        data=data.decode()
        print(data,end='')
    except :
        print('Not Message!\n')
        break
print('  recvfrom',addr)
s.close()
