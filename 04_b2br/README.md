# Born2beroot

## 🗣️ About The Project
This project aims to introduce you to the wonderful world of virtualization. You will create your first virtual machine dynamically configured according to strict security protocols.

## 🛡️ Key Configurations & Constraints
- **Operating System:** Debian or CentOS without graphical user interface (Debian preferred).
- **Disk Partitioning:** LVM (Logical Volume Management) utilizing strictly separate encrypted partitions for `/var`, `/home`, `/tmp`, `/srv`, etc.
- **SSH Configuration:** SSH service running solely on port 4242, root login denied, password authentication disabled in favor of RSA Keys.
- **UFW (Uncomplicated Firewall):** Restricted ruleset allowing access only via port 4242.
- **Sudo Policy:** Strict group assignments, logging of all modifications inside `/var/log/sudo/`, custom 3-attempt password limits, custom path restrictions.
- **Monitoring Script:** A bash script `monitoring.sh` executed continuously every 10 minutes (via cron) that broadcasts system statistics to all active terminals using `wall`.

## 📊 Monitoring Script Output Parameters
- OS Architecture and Kernel Version
- Physical and Virtual Processor Cores
- RAM and Disk Usage
- CPU Load Percentage
- Last Boot Time
- LVM Active Status
- TCP Connection Counts
- Logged Users
- IPv4 and MAC Addresses
- Total Sudo Commands Executed
