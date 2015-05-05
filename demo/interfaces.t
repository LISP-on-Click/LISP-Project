auto lo
iface lo inet loopback

# The ethernet interface
iface eth0 inet manual

# XEN bridges
auto xenbr0
iface xenbr0 inet static
    bridge_ports eth0
    address 10.0.0.3
    broadcast 10.0.0.255
    netmask 255.255.255.0

auto xenbr1
iface xenbr1 inet static
    address 192.168.0.1
    broadcast 192.168.0.255
    netmask 255.255.255.0
