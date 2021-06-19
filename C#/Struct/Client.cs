using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Struct;

namespace Struct
{
    class Client
    {
        public uint client_id;
        static uint counter;
        string client_name;
        string client_address;
        string client_phone;
        uint number_of_client_orders = 0;
        uint total_amount_of_orders = 0;
        public readonly uint Correct_Number_Size = 10;
        public Client(string client_name, string client_address, string client_phone)
        {
            ++counter;
            this.Client_name = client_name;
            this.Client_address = client_address;
            this.Client_phone = client_phone;
            client_id = counter;
        }
        public uint Client_id
        {
            get => client_id;
            set => client_id = counter;
        }
        public string Client_name
        {
            get => client_name;
            set => client_name = !string.IsNullOrWhiteSpace(value) ? value : "NoName";
        }
        public string Client_address
        {
            get => client_address;
            set => client_address = !string.IsNullOrWhiteSpace(value) ? value : "NoAddress";
        }
        public string Client_phone
        {
            get => client_phone;
            set
            {
                if (value.Length == Correct_Number_Size)
                {
                    int counter = 0;
                    for (int i = 0; i < value.Length; i++)
                    {
                        if (value[i] > 47 && value[i] < 58)
                        {
                            ++counter;
                        }
                    }
                    if (counter == value.Length)
                    {
                        client_phone = value;
                    }
                    else
                    {
                        client_phone = "Incorrect phone number.";
                    }
                }
                else
                {
                    client_phone = "Incorrect phone number.";
                }
            }
        }
        public uint Number_of_client_orders
        {
            get => number_of_client_orders;
            set => number_of_client_orders = value;
            
        }
        public uint Total_amount_of_orders
        {
            get => total_amount_of_orders;
            set
            {
                total_amount_of_orders = value;
            }
        }

        public override string ToString() => $"Client ID:\t\t\t\t{client_id}\nClient name : \t\t\t\t{client_name}\nAddress : \t\t\t\t{client_address,-10}" +
            $"\nPhone number : \t\t\t\t{client_phone,-10}\nNumber of client's orders : \t\t{Number_of_client_orders}" +
            $"\nTotal amount of client's orders : \t{Total_amount_of_orders}";
        
    }
}
