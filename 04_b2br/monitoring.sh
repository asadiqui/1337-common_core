#!/bin/bash
arc=$(uname -a)
pcpu=$(cat /proc/cpuinfo | grep "physical id" | wc -l)
vcpu=$(cat /proc/cpuinfo | grep processor | wc -l)
mem=$(free -m | awk '$1 == "Mem:" {printf"%d/%dMB (%.2f%%)",$3,$2,$3*100/$2}')
dsk_usg=$(df -BG --total | grep total | awk '{printf("%.2f/%dGb (%d%%)\n", $3, $2, $5)}')
cpul=$(top -bn2 -d=0.1 | grep %Cpu | awk 'NR==2 {printf("%.1f%%", $2 + $4)}')
#used n2 to access nr=2 as nr=1 always outputs 0%, -d for shorter delays; -b to make sure I always get 2 lines
lst_rbt=$(who -b | awk '{print $3 " " $4}')
lvm=$(lsblk | grep lvm | awk '{if ($1) {print "yes";exit} else {print "no"}}')
tcp=$(ss -pt state established | wc -l)
usrs=$(who | wc -l) #or users | wc -w
ip=$(hostname -I)
mac=$(ip a | awk '$1 == "link/ether" {print $2}')
sdcmd=$(grep COMMAND /var/log/sudo/sudo.log | wc -l)

wall "	#Architecture: $arc
	#CPU physical : $pcpu
	#vCPU : $vcpu
	#Memory Usage: $mem
	#Disk Usage: $dsk_usg
	#CPU load: $cpul
	#Last boot: $lst_rbt
	#LVM use: $lvm
	#Connections TCP : $tcp ESTABLISHED
	#User log: $usrs
	#Network: IP ${ip}($mac)
	#Sudo : $sdcmd cmd"