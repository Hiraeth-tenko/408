---
aliases:
tags:
  - 计算机网络
date created: 2023-09-19 二 04:25:12
date modified: 2023-09-22 五 05:11:36
---

# Link

---

Previous:[DHCP](DHCP.md)

Next:[ICMP](ICMP.md)

# ARP

---

适配器维护一个从 IP 地址映射到 MAC 地址的转换表（类似 NAT）。

链路层要转发一个来自上层的分组时，有两种情况：

1. 适配器的 ARP 表中含有目的 IP 地址的转换表项，直接转发
2. 否则，需要更新 ARP 表后再转发分组

## 更新 ARP 表

1. 首先，发送方指示适配器广播一个 ARP 查询分组，包含：源 IP 地址，目的 IP 地址，源 MAC 地址，目的 MAC 地址。
2. 子网内所有的适配器都能接收到这个 ARP 分组，而 IP 地址匹配的适配器向来源发送一个 ARP 响应分组
3. 发送方接收到这个 ARP 响应分组后更新 ARP 表，随后向目的 IP 地址发送 IP 数据报。

# Relative

---

[网络层](网络层.md)

# Reference

---
