auto lo
iface lo inet loopback

# The primary network interface
auto eth0
iface eth0 inet static
 address 192.168.0.50
 gateway 192.168.0.10
 netmask 255.255.255.0
 post-up ethtool -K eth0 tx off rx off
