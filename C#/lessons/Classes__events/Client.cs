using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lessons
{
    class Client
    {
        string name;
        string phone_number;
        public readonly uint CorrectNumberSize = 10;
        // Ctors
        public Client(string name, string phone_number)
        {
            this.Name = name;
            this.PhoneNumber = phone_number;
        }
        public Client() :this("Noname", "0000000000")
        { }
        // Properties
        public string Name   // Getter and setter for "name"  ---  property
        {
            get => name; // Short method
            set => name = !string.IsNullOrWhiteSpace(value) ? value : "NoName"; // Short method

            /*set
            {
                if (!string.IsNullOrWhiteSpace(value))
                {
                    name = value;
                }
            }*/
        }
        public string PhoneNumber  // Getter and setter for "phone number"  ---  property
        {
            get => phone_number;
            set
            {
                if (value.Length == CorrectNumberSize)
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
                        phone_number = value;
                    }
                    else
                    {
                        phone_number = "Incorrect phone number.";
                    }
                }
                else
                {
                    phone_number = "Incorrect phone number.";
                }
            }
        }
        // Methods
        // Short method (one operator) :
        public override string ToString() => $"Client name : {name,-10}phone number : {phone_number,-10}";
        /*public override string ToString()
        {
            return $"Client name : {name, -10}phone number : {phone_number, -10}";
        }*/
    }
}
