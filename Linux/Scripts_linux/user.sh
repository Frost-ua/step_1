#! /bin/bash

function show_menu(){
echo "1. Add user"
echo "2. Delete user"
echo "3. Edit user"
echo "4. Create group"
echo "5. Add user to group"
echo "6. Drop user from group"
echo "7. Show all users"
echo "0. Exit"
}

is_menu=true
while [[ $is_menu != false ]];
do
    show_menu;
    read -r -p "Enter the action you want to do: " choice
    case $choice in
        1) 
            read -r -p "Enter user name: " name
            read -r -p "Enter user id: " uid
            read -r -p "Enter period of password active: " period
            useradd $name -m -f $period
            usermod $name -u $uid
            echo "Enter user password: "
            passwd $name
            ;;

        2) 
            read -r -p "Enter user name you want to delete: " name
            userdel -r $name
            ;;

        3) 
            read -r -p "Enter new user name: " new_name
            read -r -p "Enter old user name: " name
            usermod -l $new_name $name
            read -r -p "Enter new user id: " new_uid
            usermod -u $new_uid $new_name
            ;;

        4) 
            read -r -p "Enter group name: " group_name
            read -r -p "Enter group id: " gid
            groupadd $group_name -g $gid
            ;;

        5) 
            read -r -p "Enter user name: " user_name
            read -r -p "Enter group name: " group_name
            usermod -aG $group_name $user_name
            ;;
        6) 
            read -r -p "Enter user name you want to delete: " user_name
            read -r -p "Enter group name for deleting user: " group_name
            gpasswd -d $user_name $group_name
            ;;
        7) 
            echo "There are such users:"
            cat /etc/passwd
            ;;
        0) 
            is_menu=false
            echo "Thanks for using"
            ;;
        *) 
            echo "You entered wrong value! Enter digit from 0 to 7."    
            exit 1
    esac
done    