---
aliases:
tags:
  - 计算机网络
date created: 2023-09-19 二 04:09:19
date modified: 2023-09-19 二 04:12:46
---

# Link

---

Previous:

Next: [TCP 拥塞控制](TCP拥塞控制.md)

# TCP 连接管理

---

## 三次握手：建立连接

1. 客户端的 TCP 向服务器 TCP 发送一个 SYN 报文段：SYN=1，ACK=0，随机选择一个初始序号（client_isn）置于序号字段。
   - 客户端进入 SYN_SENT 状态。
2. 服务器接收到 SYN 报文段后，为该 TCP 连接分配变量和缓存（**这使得服务器易受到 SYN 泛洪攻击**），并返回一个 SYNACK 报文段：SYN=1，ACK=1，确认号字段=client_isn+1，序号字段=server_isn（同样也是随机选择）。
   - 服务器进入 SYN_RECV 阶段。
3. 收到 SYNACK 报文段后，客户端也为该 TCP 连接分配变量和缓存，再返回一个用于确认 SYNACK 的报文段：SYN=0，ACK=1，序号=client_isn+1，确认号=server_isn+1。由于此时 TCP 连接已经建立，该报文段可以携带数据发送给服务器。
   - 客户端进入 ESTABLISHED 阶段。服务器在接受到 ACK 后也进入 ESTABLISHED 阶段。

![](三次握手建立TCP连接.png)

## 四次握手：关闭连接

1. 客户端 TCP 向服务器 TCP 发送一个 FIN 报文段：FIN=1，序号 = clinent_isn。clinent_isn = 最后一个发送过的序号+1。
   - 客户端进入 FIN_WAIT_1 状态。
2. 服务器 TCP 接收到 FIN 报文段后，返回一个 ACK 报文段：ACK=1，序号=server_isn，确认号=clinent_isn+1。server_isn = 最后一个发送过的序号+1。
   - 服务端进入 CLOSE_WAIT 状态。
   - 客户端接收到 ACK 报文段后，进入 FIN_WAIT_2 状态。
3. 一段时间后（此时服务器还能给客户端发送消息），服务器向客户端发送一个 FIN 报文段：FIN=1，ACK=1，序号 = server_isn，确认号=clinent_isn+1。server_isn 为最后一个发送过的序号+1。
   - 服务器进入 LAST_WAIT 状态。
   - 客户端接收到报文段后进入 TIME_WAIT 状态。
4. 客户端返回一个 ACK 报文段：ACK=1，序号 = clinent+1，确认号 = server_isn+1。
   - 服务端接收到 ACK 报文段后进入 CLOSED 状态。
   - 2 个 MSL 后，客户端进入 CLOSED 状态。

![](四次握手释放TCP连接.png)

# Relative

---

[TCP](TCP.md)

[TCP 连接管理](TCP连接管理.md)

# Reference

---
