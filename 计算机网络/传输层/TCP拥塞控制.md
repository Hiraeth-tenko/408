---
aliases:
tags:
  - 计算机网络
date created: 2023-09-19 二 04:10:10
date modified: 2023-09-19 二 04:12:57
---

# Link

---

Previous: [TCP 连接管理](TCP连接管理.md)

Next:

# TCP 拥塞控制

---

## 指导性原则

- 一个丢失的报文段意味着拥塞，需要减小发送方的发送速率。
- 一个确认报文段意味着当前网络可以成功交付数据，需要增加发送方的发送速率。
- 带宽探测。

## 名词

- rwnd
  表示接收窗口大小的值
- cwnd
  表示拥塞控制窗口大小的值
- swnd
  表示滑动发送窗口大小的值
  易知 $swnd = min\{rwnd, cwnd\}$

## 慢启动

TCP 连接一开始时，将 cwnd 设置为一个 MSS。对每个接收到确认的报文段，都增加一个 MSS，也就是说每经过一个 RTT 发送速率翻倍一次。

### 结束慢启动

当出现如下状况时，结束慢启动：

- 超时
  ssthread = cwnd/2，cwnd = 1。重启慢启动。
- 到达或超过 ssthread
  进入拥塞避免。
- 3 个冗余 ACK
  ssthread = cwnd/2，cwnd = ssthread + 3。执行快速重传，进入快速恢复。

## 拥塞避免

进入拥塞避免后，cwnd 按每 RTT 一个 MSS 的速率增加。

### 结束拥塞避免

当出现如下状况时，结束拥塞避免：

- 超时
  ssthread = cwnd/2，cwnd = 1。进入慢启动。
- 3 个冗余 ACK
  ssthread = cwnd/2，cwnd = ssthread + 3。执行快速重传，进入快速恢复。

## 快速恢复

进入快速启动后，cwnd 按每冗余 ACK 一个 MSS 的速率增加。

### 结束快速恢复

当出现如下状况时，结束快速恢复：

- 超时
  ssthread = cwnd/2，cwnd = 1。进入慢启动。
- 收到非冗余 ACK
  即对丢失报文段的 ACK 报文段。cwnd = ssthread。进入拥塞避免。

# Relative

---

[TCP](TCP.md)

[TCP 连接管理](TCP连接管理.md)

# Reference

---
