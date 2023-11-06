---
aliases:
tags:
  - 计算机网络
date created: 2023-09-19 二 04:25:58
date modified: 2023-09-22 五 05:11:47
---

# Link

---

Previous:[ARP](ARP.md)

Next: [路由协议](路由协议.md)

# ICMP

---

ICMP 报文作为 IP 分组的数据字段封装，因此 IP 层对 ICMO 直接提供服务。

主要的几种情况：

- 终点不可达
- 时间超过
  接收方接收到了一个 TTL=0 的数据报
- 参数问题
- 改变路由
  有更好的路由途径

对于以下情况不发送 ICMP 差错控制报：

- ICMP 差错控制报出错
- 对于第一个数据报分片的后续分片
- 对于组播地址的数据报
- 特殊地址的数据报

# Relative

---

[网络层](网络层.md)

# Reference

---
