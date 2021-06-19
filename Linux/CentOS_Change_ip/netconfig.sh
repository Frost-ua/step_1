#! /bin/bash

function check_ip(){

echo $1 | awk -F "." '{if ( NF != 4 ) print "\tIt is not an IP-address";
        else if ( $1 >= 0 && $1 <= 255 && $2 >=0 && $2 <= 255 && $3 >=0 && $3 <= 255 && $4 >= 0 && $4 <= 255 )
        print "\tIt is a right IP-address";
        else print "\tIt is not a valid IP-address"}'
}

echo -e -n "\n1. Use static IP adress\n"
echo -e -n "2. Use dynamic IP adress\n\n"
read -r -p "Enter the action you want to do: " choice

case $choice in
    1)
         sed '/^IPV6/d' -i /etc/sysconfig/network-scripts/ifcfg-en*                   # delete ipv6 ALL strings

         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "IPADDR"; then
               sed '/^IPADDR/d' -i /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "NETMASK"; then
               sed '/^NETMASK/d' -i /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "GATEWAY"; then
               sed '/^GATEWAY/d' -i /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "DNS1"; then
               sed '/^DNS1/d' -i /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "DNS2"; then
            sed '/^DNS2/d' -i /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "BOOTPROTO=dhcp"; then
               sed -i "s/BOOTPROTO=dhcp/BOOTPROTO=static/g" /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "BOOTPROTO=\"dhcp\""; then
               sed -i "s/BOOTPROTO=\"dhcp\"/BOOTPROTO=\"static\"/g" /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "ONBOOT=no"; then
            sed -i "s/ONBOOT=no/ONBOOT=yes/g" /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "ONBOOT=\"no\""; then
            sed -i "s/ONBOOT=\"no\"/ONBOOT=\"yes\"/g" /etc/sysconfig/network-scripts/ifcfg-en*
         fi

         echo -e -n "\n\nYour default gateway now is:\n"
         ip rout | grep default
         echo -e -n "\nEnter your default gateway: "
         read gateway
         check_ip $gateway;
         read -r -p "Enter your static ip adress: " ip
         check_ip $ip;
         read -r -p "Enter your network mask: " netmask
         check_ip $netmask;
         read -r -p "Enter DNS server (recommended 8.8.8.8): " dns1
         check_ip $dns1;
         read -r -p "Enter reserve DNS server (recommended 8.8.4.4): " dns2
         check_ip $dns2;

         echo IPADDR=$ip>> /etc/sysconfig/network-scripts/ifcfg-en*
         echo NETMASK=$netmask>> /etc/sysconfig/network-scripts/ifcfg-en*
         echo GATEWAY=$gateway>> /etc/sysconfig/network-scripts/ifcfg-en*
         echo DNS1=$dns1>> /etc/sysconfig/network-scripts/ifcfg-en*
         echo DNS2=$dns2>> /etc/sysconfig/network-scripts/ifcfg-en*
         echo -e -n "\nYour network configuration was changed.\n\n"
         
         cat /etc/sysconfig/network-scripts/ifcfg-en*
         echo -e -n "\nThe network service will restart.\nAfter restarting, you will have to use\nthe new static IP adress to connect with SSH.\n\t\tWARNING!!!\nIf the network settings are incorrect\nYOU MUST BREAK this script with command \"Ctrl + C\",\nand run the script again.\n\n"
         read -r -p "Press ENTER if you want to restart network service!" t
         reboot
         ;;
    2)
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "IPADDR"; then
            sed '/^IPADDR/d' -i /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "NETMASK"; then
            sed '/^NETMASK/d' -i /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "GATEWAY"; then
            sed '/^GATEWAY/d' -i /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "DNS1"; then
            sed '/^DNS1/d' -i /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "DNS2"; then
            sed '/^DNS2/d' -i /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         if cat /etc/sysconfig/network-scripts/ifcfg-en* | grep -i "BOOTPROTO=static"; then
            sed -i "s/BOOTPROTO=static/BOOTPROTO=dhcp/g" /etc/sysconfig/network-scripts/ifcfg-en*
         fi
         echo -e -n "\nYour network configuration was changed.\n\n"
         cat /etc/sysconfig/network-scripts/ifcfg-en*
         echo -e -n "\nThe network service will restart.\nAfter restarting, you have to use the command,\"dhclient\"\nto take a new dynamic IP address from DHCP server\n\t\tWARNING!!!\nIf the network settings are incorrect\nYOU MUST BREAK this script with command \"Ctrl + C\",\nand run the script again.\n\n"
         read -r -p "Press ENTER if you want to restart network service!" t
         reboot
         ;;
     *) 
         echo "You entered wrong value! Run the script again. Enter digit from 1 to 2"    
         exit 1

esac


      
